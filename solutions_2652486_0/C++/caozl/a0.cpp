//

#include "stdafx.h"
#include "a0.h"
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 唯一的应用程序对象

CWinApp theApp;

using namespace std;


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

//根据n为数字数量, m为数字最大值, strArrT为数字乘积信息,返回数字结果合并为sRet;
void GoodLuck(CString& sRet, const vector<CString>& strArrT, int N, int M)
{
	vector<int> nRets; //应该是n个
	int n2Max = 0;
	int n3Max = 0;
	int n5Max = 0;
	int n7Max = 0;
	for (int i=0; i<strArrT.size(); i++)
	{
		long nSub = atoi(strArrT[i]);
		if (nSub == 1)
		{
			continue;
		}
		int n2 = 0;
		int n3 = 0;
		int n5 = 0;
		int n7 = 0;
		//要把nRet分解为乘积的形式
		//这里面有窍门
		//m最大为8或5
		//所以3，5，7要先试
		while (nSub%3==0)
		{
			nSub = nSub/3;
			++n3;
		}

		while (nSub%5==0)
		{
			nSub = nSub/5;
			++n5;
		}

		while (nSub%7==0)
		{
			nSub = nSub/7;
			++n7;
		}

		while (nSub%2==0)
		{
			nSub = nSub/2;
			++n2;
		}

		if (n2>n2Max)
		{
			n2Max = n2;
		}
		if (n3>n3Max)
		{
			n3Max = n3;
		}
		if (n5>n5Max)
		{
			n5Max = n5;
		}
		if (n7>n7Max)
		{
			n7Max = n7;
		}
	}
	for (int i=0; i<n7Max; i++)
	{
		sRet+="7";
	}

	for (int i=0; i<n5Max; i++)
	{
		sRet+="5";
	}

	for (int i=0; i<n3Max; i++)
	{
		sRet+="3";
	}

	int nLeft = N - sRet.GetLength(); //剩给2的位置

	while (true)
	{
		if (nLeft<=0)
		{
			break;
		}
		int nt1 = n2Max/nLeft;
		int nt2 = n2Max%nLeft;
		if (nt1>2 || (nt1==2 && nt2>0))
		{
			sRet+="8";
			n2Max -= 3;
			nLeft--;
			continue;
		}
		else if (nt1>1 || (nt1==1 && nt2>0))
		{
			sRet+="4";
			n2Max -= 2;
			nLeft--;
			continue;
		}
		else
		{
			sRet+="2";
			n2Max--;
			nLeft--;
		}
	} 
}


int _tmain(int argc, TCHAR* argv[], TCHAR* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule != NULL)
	{
		// 初始化 MFC 并在失败时显示错误
		if (!AfxWinInit(hModule, NULL, ::GetCommandLine(), 0))
		{
			// TODO: 更改错误代码以符合您的需要
			_tprintf(_T("错误: MFC 初始化失败\n"));
			nRetCode = 1;
		}
		else
		{
			// TODO: 在此处为应用程序的行为编写代码。

			CStdioFile file;
			BOOL bOpen = file.Open("C:\\input", CFile::modeRead);
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

				//读总信息
				int R = 0;
				int N = 0;
				int M = 0;
				int K = 0;
				vector<CString> strArrT = string2Arr(strArr[1], ' ');
				if (strArrT.size() == 4)
				{
					R = atoi(strArrT[0]);
					N = atoi(strArrT[1]);
					M = atoi(strArrT[2]);
					K = atoi(strArrT[3]);
				}
				//返回值
				vector<CString> strRArr;
				strRArr.push_back("Case #1:");
				//读每次的信息
				for (size_t i=2; i<R+2; ++i)
				{
					//这个就是K个数据了
					vector<CString> strArrT = string2Arr(strArr[i], ' ');

					CString sRet;
					GoodLuck(sRet, strArrT, N, M);
					strRArr.push_back(sRet);
				}

				CStdioFile fileT;
				bOpen = fileT.Open("C:\\output", CFile::modeWrite|CFile::modeCreate);
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
	else
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: GetModuleHandle 失败\n"));
		nRetCode = 1;
	}

	return nRetCode;
}

