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

void Func(int nX, int nY, string& sRet)
{
	if (nX<0)
	{
		while (nX++)
		{
			sRet+="EW";
		}
	}
	else if (nX>0)
	{
		while (nX--)
		{
			sRet+="WE";
		}
	}

	if (nY<0)
	{
		while (nY++)
		{
			sRet+="NS";
		}
	}
	else if (nY>0)
	{
		while (nY--)
		{
			sRet+="SN";
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nSize;
	cin >> nSize;
	for (int i = 0; i < nSize; i++)
	{
		int nX, nY;
		cin >> nX >> nY;
		string sRet;
		Func(nX, nY, sRet);

		string sNote = "Case #";
		cout << sNote << i+1<<": "<<sRet<<"\n";
	}
	return 0;
}
