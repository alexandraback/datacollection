#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <queue>
#include <stack>
#include <string>
#include <cassert>
#define INF 1000000000
using namespace std;
char S[105];
int T, L;
int dp[105][105];
char DW[550000][30];
int WL[550000];
int ds;


inline bool fits(const int& idx, const int& fidx, const int& si)
{
	if (idx + WL[si] - 1 > L)
		return false;
	int ld = fidx;
	for (int i = 0; i < WL[si]; ++i)
	{
		if (DW[si][i] != S[idx+i])
		{
			if (idx + i < ld)
				return false;
			ld = idx + i + 5;
		}
	}
	return true;
}

inline pair<int,int> diffs(const int& idx, const int& si)
{
	int ans = 0;
	int li = -1;
	for (int i = 0; i < WL[si]; ++i)
	{
		if (DW[si][i] != S[idx+i])
		{
			++ans;
			li = idx + i;
		}
	}
	return pair<int, int>(ans, li);
}

int go(int idx, int fidx)
{
	int& cur = dp[idx][fidx];
	if (cur != -1)
		return cur;

	cur = INF;

	for (int i = 0; i < ds; ++i)
		if (fits(idx, fidx, i))
		{
			pair<int, int> info = diffs(idx, i);
			int ni = idx + WL[i];
			int nd = (info.second >= 0) ? min(max(ni, info.second + 5), L + 1) : ni;
			cur = min(cur, info.first + go(ni, nd));
		}
	return cur;
}

int _tmain(int argc, _TCHAR* argv[])
{
	ifstream cin("C-small-attempt0.in");
	ofstream cout("C-small-attempt0.out");

	ifstream dcin("dictionary.txt");
	
	while(dcin.getline(DW[ds], 10000))
	{
		WL[ds] = strlen(DW[ds]);
		assert(WL[ds] < 20);
		++ds;
	}

	dcin.close();

	cin >> T;
	cin.ignore();

	for (int ts = 1; ts <= T; ++ts)
	{
		cin.getline(S, 105);
		
		L = strlen(S);
		for (int i = L; i >= 1; --i)
			S[i] = S[i-1];

		//1....L

		for (int i = 1; i <= L; ++i)
			for (int j = i; j < 105; ++j)
				dp[i][j] = -1;

		for (int i = 0; i < 105; ++i)
			dp[L+1][i] = 0;


		cout << "Case #" << ts << ": " << go(1, 1) << endl;
		std::cout << ts << endl;


	}







	
	cin.close(); cout.close();
	return 0;
}

