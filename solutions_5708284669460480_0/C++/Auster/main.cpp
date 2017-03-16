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

int T, K, L, S;
string keys;
string goal;

double dp[111][111];
int dpm[111][111];
int to[111][111];

double go(int n, int p)
{
	if (n == 0)
		return p == L;
	double & res = dp[n][p];
	if (res != -1.0)
		return res;
	res = 0;
	for(int i = 0; i < K; ++i)
		res += go(n - 1, to[p][i]);
	res /= K;
	res += L == p;
	return res;
}

int gomax(int n, int p)
{
	if (n == 0)
		return p == L;
	int & res = dpm[n][p];
	if (res != -1)
		return res;
	res = 0;
	for(int i = 0; i < K; ++i)
		res = max(res, gomax(n - 1, to[p][i]));
	res += L == p;
	return res;
}

int main()
{
#ifndef _DEBUG
	freopen("B-small-attempt0 (6).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> T;
	for(int it = 1; it <= T; ++it)
	{
		cin >> K >> L >> S;
		cin >> keys >> goal;

		for(int i = 0; i <= L; ++i)
		{
			for(int j = 0; j < K; ++j)
			{
				string s = goal.substr(0, i);
				s += keys[j];
				for(int k = 0; k <= min(L, i + 1); ++k)
					if (s.substr((int)s.size() - k, k) == goal.substr(0, k))
						to[i][j] = k;
			}
		}

		for(int i = 0; i < 111; ++i)
			for(int j = 0; j < 111; ++j)
				dp[i][j] = -1.0;
		memset(dpm, -1, sizeof(dpm));

		cout.precision(10);
		cout << "Case #" << it << ": " << fixed << (gomax(S, 0) - go(S, 0)) << endl;
	}
	return 0;
}