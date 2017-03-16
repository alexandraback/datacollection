：// 2012r1A1.cpp : 定义控制台应用程序的入口点。
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


inline long long atoll(const char *instr)
{
	long long retval;
	int i;

	retval = 0;
	for (; *instr; instr++) {
		retval = 10*retval + (*instr - '0');
	}
	return retval;
}

// 唯一的应用程序对象

CWinApp theApp;

using namespace std;


LONGLONG getMaxR(LONGLONG nStart, LONGLONG nR, const vector<LONGLONG>& getRArr, LONGLONG nMax)
{
	LONGLONG nRt = 0;
	for (int i = 0; i < getRArr.size(); i++)
	{
		LONGLONG nCur = nStart+nR;
		LONGLONG nCurUse = 0;
		if (nCur>nMax)
		{
			nCurUse = nCur-nMax;
			nCur = nMax;
		}
		int nPos = 1;
		while (i+nPos < getRArr.size())
		{
			if (getRArr[i+nPos]>=getRArr[i])
			{
				break;
			}
			LONGLONG nAdd = nR;
			if (nCurUse+nAdd>nStart)
			{
				nAdd = nStart-nCurUse;
			}
			nCurUse+=nAdd;
			nCur-=nAdd;
			nPos+=1;
			if (nCurUse == nStart)
			{
				break;
			}
		}
		if (i+nPos >= getRArr.size())
		{
			nCurUse = nStart;
		}
		nRt += nCurUse*getRArr[i];
		nStart -= nCurUse;
		nStart += nR;
	}
	return nRt;
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
			BOOL bOpen = file.Open("C:\\input.txt", CFile::modeRead);
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
					vector<CString> strArrT2 = string2Arr(strArr[nPos++], ' ');

					LONGLONG nStart = atoll(strArrT[0]);
					LONGLONG nR = atoll(strArrT[1]);
					vector<LONGLONG> getRArr(strArrT2.size());
					for (int j = 0; j < strArrT2.size(); j++)
					{
						getRArr[j] = atoll(strArrT2[j]);
					}

					LONGLONG nRT = getMaxR(nStart, nR, getRArr, nStart);


					CString strIndex;
					strIndex.Format("Case #%d: %d",i+1, nRT); 
					strRArr.push_back(strIndex);
				}

				CStdioFile fileT;
				bOpen = fileT.Open("C:\\output.txt", CFile::modeWrite|CFile::modeCreate);
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
