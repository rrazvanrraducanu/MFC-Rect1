
// Rect1View.cpp : implementation of the CRect1View class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Rect1.h"
#endif

#include "Rect1Doc.h"
#include "Rect1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRect1View

IMPLEMENT_DYNCREATE(CRect1View, CView)

BEGIN_MESSAGE_MAP(CRect1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRect1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CRect1View construction/destruction

CRect1View::CRect1View() noexcept
{
	// TODO: add construction code here
	m_button = FALSE;
	x = 0;
	y = 0;
}

CRect1View::~CRect1View()
{
}

BOOL CRect1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CRect1View drawing

void CRect1View::OnDraw(CDC* /*pDC*/)
{
	CRect1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CRect1View printing


void CRect1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRect1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRect1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRect1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CRect1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRect1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRect1View diagnostics

#ifdef _DEBUG
void CRect1View::AssertValid() const
{
	CView::AssertValid();
}

void CRect1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRect1Doc* CRect1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRect1Doc)));
	return (CRect1Doc*)m_pDocument;
}
#endif //_DEBUG


// CRect1View message handlers


void CRect1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	m_button = TRUE;
	CClientDC dc(this);
	CRect rect;
	GetClientRect(&rect);
	dc.MoveTo(0, 0);
	dc.LineTo(rect.Width(), rect.Height());
	CView::OnRButtonDown(nFlags, point);
}


void CRect1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CView::OnPaint() for painting messages
	CRect rect;
	GetClientRect(&rect);
	if (m_button == TRUE)
	{
		dc.MoveTo(0, 0);
		dc.LineTo(rect.Width(), rect.Height());
	}
}
