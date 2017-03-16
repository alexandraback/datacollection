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

LONGLONG CalR(string strWord, int n)
{
	int nBefore = -1;
	LONGLONG nR = 0;
	for (int i = 0; i+n-1 < strWord.length(); i++)
	{
		bool bFit = true;
		for (int j = 0; j < n; j++)
		{
			if (strWord[i+j] == 'a' || strWord[i+j] == 'e' 
				|| strWord[i+j] == 'i' || strWord[i+j] == 'o' 
				|| strWord[i+j] == 'u')
			{
				bFit = false;
				break;
			}
		}
		if (!bFit)
		{
			continue;
		}
		nR += strWord.length()-i-n+1;
		//if (nBefore>=0)
		{
			for (int j = nBefore+1; j < i; j++)
			{
				nR += strWord.length()-i-n+1;
			}
		}
		nBefore = i;
	}
	return nR;
}

int _tmain(int argc, _TCHAR* argv[])
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int nSize;
	cin >> nSize;
	for (int i = 0; i < nSize; i++)
	{
		string strWord;
		int n;
		cin >> strWord >> n;
		cout << "Case #" << i+1 << ": " << CalR(strWord, n) << "\n";
	}
	return 0;
}

