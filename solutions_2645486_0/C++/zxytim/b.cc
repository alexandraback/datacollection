/*
 * $File: b.cc
 * $Date: Sat Apr 27 10:09:44 2013 +0800
 * $Author: Xinyu Zhou <zxytim[at]gmail[dot]com>
 */

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void solve()
{
	int E, R, N;
	int v[1000];
	scanf("%d%d%d", &E, &R, &N);
	for (int i = 1; i <= N; i ++)
		scanf("%d", v + i);
	int f[11][11];
	bzero(f, sizeof(f));
	for (int i = 0; i < N; i ++)
	{
		for (int j = 0; j <= E; j ++)
		{
			for (int k = 0; k <= j; k ++)
			{
				int p = j - k + R;
				if (p > E)
					p = E;
				f[i + 1][p] = max(f[i + 1][p], f[i][j] + k * v[i + 1]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i <= E; i ++)
		ans = max(ans, f[N][i]);
	printf("%d\n", ans);
}

int main()
{
	int ncase;
	scanf("%d", &ncase);
	for (int i = 1; i <= ncase; i ++)
	{
		printf("Case #%d: ", i);
		if (i == 90)
		{
			int asdf = 0;
		}
		solve();
	}
	return 0;
}


/**
 * vim: syntax=cpp11 foldmethod=marker
 */

