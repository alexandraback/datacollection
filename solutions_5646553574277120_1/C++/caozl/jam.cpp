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


int calR(int C, LONGLONG V, vector<int> DArr)
{
	int nX = C+1;
	int nR = 0;
	if (DArr[0] != 1)
	{
		nR = 1;
	}
	else
	{
		DArr.erase(DArr.begin());
	}
	
	LONGLONG nDCur = 1;
	LONGLONG nVCur = C;
	while (nVCur < V)
	{
		if (DArr.size() > 0)
		{
			LONGLONG nDNext = nVCur+1;
			if (nDNext>=DArr[0])
			{
				nDCur = DArr[0];
				nVCur += nDCur*C;
				DArr.erase(DArr.begin());
				continue;
			}
		}
		nR += 1;
		nDCur = nVCur+1;
		nVCur += nDCur*C;
	}
	return nR;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nSizeT;
	cin >> nSizeT;
	for (int i = 0; i < nSizeT; i++)
	{
		int C;
		int D;
		LONGLONG V;
		cin >> C >> D >> V;
		vector<int> DArr;
		DArr.resize(D, 0);
		for (int j =0; j < D; j++)
		{
			cin >> DArr[j];
		}
		string sNote = "Case #";
		cout << sNote << i+1<<": "<<calR(C, V, DArr)<<"\n";
	}
	return 0;
}
