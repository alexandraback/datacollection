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


void digui(string& ss, int nPos, string &sK, int nK, string& sT, int& nAll, int& nTime, int& nMax)
{
	if (nPos == ss.length())
	{
		nTime += 1;
		int nT = sT.length();
		int nCur = 0;
		for (int i = 0; i < nPos-nT+1; i++)
		{
			string ss1 = ss;
			ss1 = ss1.substr(i, nT);
			if (ss1 == sT)
			{
				nCur += 1;
			}
		}
		nAll += nCur;
		if (nMax < nCur)
		{
			nMax = nCur;
		}
		return;
	}
	for (int i = 0; i < nK; i++)
	{
		ss[nPos] = sK[i];
		digui( ss,  nPos+1, sK, nK, sT,  nAll,  nTime,  nMax);
	}
}

double calR(int S, string sK, string sT)
{
	int nK = sK.length();
	string ss = "";
	for (int i = 0; i < S; i++)
	{
		ss += "a";
	}
	int nMax = 0;
	int nTime = 0;
	int nAll = 0;
	digui(ss, 0, sK, nK, sT, nAll, nTime, nMax);
	return (double)nMax-(double)nAll/nTime;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nSizeT;
	cin >> nSizeT;
	for (int i = 0; i < nSizeT; i++)
	{
		int K;
		int L;
		int S;
		cin >> K >> L >> S;
		string sK;
		string sT;
		cin >> sK;
		cin >> sT;
		string sNote = "Case #";
		cout << sNote << i+1<<": "<<calR(S, sK, sT)<<"\n";
	}
	return 0;
}
