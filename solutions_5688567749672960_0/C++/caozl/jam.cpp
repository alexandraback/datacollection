// jam.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
typedef __int64 LONGLONG;

vector<LONGLONG> nArr;

int calRn(LONGLONG nPos)
{
	vector<int> nArrT;
	nArrT.reserve(15);
	while (nPos>10)
	{
		nArrT.push_back(nPos%10);
		nPos = nPos/10;
	}
	nArrT.push_back(nPos);
	LONGLONG nR = 0;
	for (int i = 0; i < nArrT.size(); i++)
	{
		nR *= 10;
		nR += nArrT[i];
	}
	return nR;
}

int _tmain(int argc, _TCHAR* argv[])
{
	LONGLONG nSize = 1000000+1;
	nArr.resize(nSize,nSize);
	LONGLONG nCur = 1;
	for (LONGLONG i = 1; i < nSize; ++i, ++nCur)
	{
		if (nArr[i] > nCur)
		{
			nArr[i] = nCur;
			LONGLONG nRt = calRn(i);
			if (nRt>i && nArr[nRt] > nCur+1)
			{
				nArr[nRt] = nCur+1;
			}
		}
		else if (nArr[i] < nCur)
		{
			nCur = nArr[i];
		}		
	}

	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nSizeT;
	cin >> nSizeT;
	for (int i = 0; i < nSizeT; i++)
	{
		LONGLONG nT;
		cin >> nT;
		string sNote = "Case #";
		cout << sNote << i+1<<": "<<nArr[nT]<<"\n";
	}
	return 0;
}
