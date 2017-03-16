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

int calR(int R, int C, int W)
{
	int nDW = C/W;
	int nR = R*nDW;
	nR += W-1;
	if (nDW*W != C)
	{
		nR += 1;
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
		int R;
		int C;
		int W;
		cin >> R >> C >> W;
		string sNote = "Case #";
		cout << sNote << i+1<<": "<<calR(R, C, W)<<"\n";
	}
	return 0;
}
