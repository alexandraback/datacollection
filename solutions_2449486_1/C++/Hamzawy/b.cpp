/*
 * b.cpp
 *
 *  Created on: Apr 13, 2013
 *      Author: AhmedHamza
 */

#include<cstdio>
#include<iostream>
#include<map>
#include<string>
#include<string.h>
#include<vector>
#include<algorithm>
using namespace std;

int b[101][101];

struct tuble
{
		int val, r, c;
		tuble()
		{
		}
		tuble(int val, int r, int c) :
			val(val), r(r), c(c)
		{
		}
		bool operator <(const tuble& t) const
		{
			if (val != t.val)
				return val < t.val;
			if (r != t.r)
				return r < t.r;
			return c < t.c;
		}
};

tuble all[10001];
bool vis[201][201];

int main()
{
	//freopen("b.in", "rt", stdin);
	freopen("B-large.in", "rt", stdin);
	freopen("b.out2", "wt", stdout);
	int tc;
	scanf("%d", &tc);
	for (int T = 1; T <= tc; ++T)
	{
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", b[i] + j), all[i * m + j] = tuble(b[i][j], i, j);
		int N = n * m, r, c, val;
		sort(all, all + N);
		memset(vis, 0, sizeof vis);
		for (int k = 0; k < N; ++k)
		{
			r = all[k].r;
			c = all[k].c;
			val = all[k].val;
			if (vis[r][c])
				continue;
			bool f = 1, temp = 0;
			for (int i = 0; i < n; ++i)
				if (b[i][c] > val)
				{
					f = 0;
					break;
				}
			if (f)
			{
				for (int i = 0; i < n; ++i)
					vis[i][c] = 1;
				temp = 1;
			}
			f = 1;
			for (int j = 0; j < m; ++j)
				if (b[r][j] > val)
				{
					f = 0;
					break;
				}
			if (f)
			{
				for (int j = 0; j < m; ++j)
					vis[r][j] = 1;
			}
			else if (!temp)
				goto FAIL;
		}
		printf("Case #%d: YES\n", T);
		continue;
		FAIL: printf("Case #%d: NO\n", T);

	}
	return 0;
}
