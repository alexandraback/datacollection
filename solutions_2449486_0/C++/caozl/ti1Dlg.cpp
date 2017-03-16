// ti1Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "ti1.h"
#include "ti1Dlg.h"
#include <vector>

using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// Cti1Dlg 对话框




Cti1Dlg::Cti1Dlg(CWnd* pParent /*=NULL*/)
	: CDialog(Cti1Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Cti1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Cti1Dlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &Cti1Dlg::OnBnClickedOk)
END_MESSAGE_MAP()


// Cti1Dlg 消息处理程序

BOOL Cti1Dlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void Cti1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void Cti1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
//
HCURSOR Cti1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



bool CalTi2(const vector<vector<int>>& nArr)
{
	//先看横向
	vector<vector<int>> nArrT = nArr;
	for (int i = 0; i < nArr.size(); i++)
	{
		int nMax = 0;
		for (int j = 0; j < nArr[i].size(); j++)
		{
			if (nMax < nArr[i][j])
				nMax = nArr[i][j];
		}

		for (int j = 0; j < nArr[i].size(); j++)
		{
			if (nMax == nArr[i][j])
				nArrT[i][j] = 0;
		}
	}

	for (int j = 0; j < nArr[0].size(); j++)
	{
		int nMax = 0;
		for (int i = 0; i < nArr.size(); i++)
		{
			if (nMax < nArr[i][j])
				nMax = nArr[i][j];
		}

		for (int i = 0; i < nArr.size(); i++)
		{
			if (nMax == nArr[i][j])
				nArrT[i][j] = 0;
		}
	}

	for (int i = 0; i < nArrT.size(); i++)
	{
		for (int j = 0; j < nArrT[i].size(); j++)
		{
			if (nArrT[i][j]!=0)
			{
				return false;
			}
		}
	}
	return true;
}



vector<CString> string2Arr(CString str, char cSplit)
{
	vector<CString> strArr;
	int nStart = 0;
	while (true)
	{
		int nPos = str.Find(cSplit, nStart);
		if (nPos < 0)
		{
			strArr.push_back(str.Mid(nStart));
			break;
		}
		strArr.push_back(str.Mid(nStart, nPos-nStart));
		nStart = nPos+1;
	}
	return strArr; 
}


void Cti1Dlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	if (1)
	{
		CStdioFile file;
		BOOL bOpen = file.Open("C:\\input2", CFile::modeRead);
		vector<CString> strArr;
		if (bOpen)
		{
			CString strT;
			while (file.ReadString(strT))
			{
				strArr.push_back(strT);
			}
			file.Close();
		}

		if (bOpen)
		{
			int nSize = atoi(strArr[0]);
			vector<CString> strRArr;
			int nPos = 1;
			for (int i = 0; i < nSize; i++)
			{
				vector<CString> strArrT = string2Arr(strArr[nPos++], ' ');
				if (strArrT.size()!=2)
				{
					AfxMessageBox("error!!");
					return;
				}
				int nHang = atoi(strArrT[0]);
				int nLie = atoi(strArrT[1]);
				vector<vector<int>> nArr(nHang);
				for (int j = 0; j < nHang; j++)
				{
					vector<CString> strArrT = string2Arr(strArr[nPos++], ' ');
					if (strArrT.size()!=nLie)
					{
						AfxMessageBox("error!!!!!");
					}
					vector<int> nArrT(nLie);
					for (int k = 0; k < nLie; k++)
					{
						nArrT[k] = atoi(strArrT[k]);
					}
					nArr[j] = nArrT;
				}
				bool bR = CalTi2(nArr);
				
				CString strIndex;
				strIndex.Format("Case #%d: ", i+1);
				if (bR)
				{
					strIndex += "YES";
				}
				else
				{
					strIndex += "NO";
				}
				strRArr.push_back(strIndex);
			}

			CStdioFile fileT;
			bOpen = fileT.Open("C:\\output2", CFile::modeWrite|CFile::modeCreate);
			if (bOpen)
			{
				for (int i = 0; i < strRArr.size(); i++)
				{
					fileT.WriteString(strRArr[i]+"\n");
				}
				fileT.Close();
			}
		}
	}

}
