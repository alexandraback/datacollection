#pragma comment(linker, "/STACK:134217728")

#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <numeric>
#include <functional>
#include <cmath>
#include <complex>
#include <memory.h>
#include <time.h>

using namespace std;

typedef long long LL;

int T, R, C, W;

int dp[1 << 20][2];
int d[1 << 20];

int bad(int mask)
{
	int & res = d[mask];
	if (res != -1)
		return res;
	res = 0;
	for(int i = 0; i <= C - W; ++i)
		res |= (mask & (((1 << W) - 1) << i)) == 0;
	return res;
}

int go(int mask, int t)
{
	int & res = dp[mask][t];
	if (res != -1)
		return res;
	res = (int)1e9;
	for(int i = 0; i < C; ++i)
		if (!(mask & (1 << i)))
		{
			int next = mask | (1 << i);
			if (t)
			{
				if (!bad(next))
				{
					int total = 1;
					int j = i - 1;
					while (j >= 0 && !(mask & (1 << j)))
					{
						j--;
						total++;
					}
					j = i + 1;
					while (j < C && !(mask & (1 << j)))
					{
						j++;
						total++;
					}
					res = min(res, min(total, W + 1));
				}
				else
					res = min(res, 1 + go(mask | (1 << i), t));
			}
			else
			{
				if (!bad(next))
					res = 1;
				else
					res = min(res, 1 + go(mask | (1 << i), t));
			}
		}
	return res;
}

int main()
{
#ifndef _DEBUG
	freopen("A-large (6).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> T;
	for(int it = 1; it <= T; ++it)
	{
		cin >> R >> C >> W;
		memset(dp, -1, sizeof(dp));
		memset(d, -1, sizeof(d));

		cout << "Case #" << it << ": " << (R - 1) * go(0, 0) + go(0, 1) << endl;
	}
	return 0;
}