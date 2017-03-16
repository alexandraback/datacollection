#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;

int T, n, m;
int h[110][110];

bool check(int x, int y)
{
	bool flag = true;
	for (int i = 1; i <= m && flag; ++i)
		if (h[x][i] > h[x][y]) flag = false;
	if (flag) return true;
	flag = true;
	for (int i = 1; i <= n && flag; ++i)
		if (h[i][y] > h[x][y]) flag = false;
	if (flag) return true;
	return false;
}

void work(int T)
{
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			scanf("%d",&h[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (!check(i, j))
			{
				printf("Case #%d: NO\n", T);
				return;
			}
	printf("Case #%d: YES\n", T);
}

int main()
{
	scanf("%d",&T);
	for (int i = 1; i <= T; ++i) work(i);
	return 0;
}
