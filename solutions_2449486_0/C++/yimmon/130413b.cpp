/*========================================================================
#   FileName: 130413b.cpp
#     Author: YIMMON
#      Email: yimmon.zhuang@gmail.com
#   HomePage: http://qr.ae/8DMzu
# LastChange: 2013-04-13 11:40:47
========================================================================*/
#include <iostream>
#include <cstdio>
#include <cstring>
#define N 105
using namespace std;

int T, g[N][N], row[N], col[N], n, m;

inline int solve()
{
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < m; ++j)
			if(g[i][j] < row[i] && g[i][j] < col[j])
				return 0;
	return 1;
}

int main(int argc, char **argv)
{
	scanf("%d", &T);
	for(int cas = 1; cas <= T; ++cas)
	{
		scanf("%d%d", &n, &m);
		for(int i = 0; i < n; ++i)
		{
			row[i] = 0;
			for(int j = 0; j < m; ++j)
			{
				scanf("%d", &g[i][j]);
				row[i] = max(row[i], g[i][j]);
			}
		}
		for(int i = 0; i < m; ++i)
		{
			col[i] = 0;
			for(int j = 0; j < n; ++j)
				col[i] = max(col[i], g[j][i]);
		}
		printf("Case #%d: %s\n", cas, solve()?"YES":"NO");
	}

	return 0;
}
