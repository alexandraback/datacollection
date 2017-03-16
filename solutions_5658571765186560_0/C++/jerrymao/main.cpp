#include <bits/stdc++.h>
using namespace std;

int omino[5][5][5][2] = {
	{},
	{},
	{{{0, 0}, {0, 1}}},
	{{{0, 0}, {0, 1}, {0, 2}}, {{0, 0}, {0, 1}, {1, 0}}},
	{{{0, 0}, {0, 1}, {0, 2}, {0, 3}}, {{0, 0}, {0, 1}, {0, 2}, {1, 2}}, {{0, 0}, {0, 1}, {1, 0}, {1, 1}}, {{0, 0}, {0, 1}, {1, 1}, {1, 2}}, {{0, 0}, {0, 1}, {0, 2}, {1, 1}}},
};
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
int sz[5] = {0, 0, 1, 2, 5};
bool vis[6][6];
int x, r, c;
int newvis;
int t;

void dfs(int a, int b)
{
	if (a < 0 || b < 0 || a >= r || b >= c)
		return;
	if (vis[a][b])
		return;
	vis[a][b] = true;
	newvis++;
	for (int i = 0;i < 4;i++)
		dfs(a+dx[i], b+dy[i]);
}

int main()
{
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		scanf("%d%d%d", &x, &r, &c);
		printf("Case #%d: ", _);
		if (x == 1)
		{
			printf("GABRIEL\n");
			continue;
		}
		if ((r*c)%x || (x > r && x > c) || x >= 7)
		{
			printf("RICHARD\n");
			continue;
		}
		for (int i = 0;i < sz[x];i++)
		{
			bool fail = false;
			for (int j = 0;j < r;j++) for (int k = 0;k < c;k++)
				vis[j][k] = false;
			for (int j = 0;j < x;j++)
				if (omino[x][i][j][0] < r && omino[x][i][j][1] < c)
					vis[omino[x][i][j][0]][omino[x][i][j][1]] = true;
				else
				{
					fail = true;
					break;
				}
			if (!fail) for (int j = 0;j < r;j++) for (int k = 0;k < c;k++) if (!vis[j][k])
			{
				newvis = 0;
				dfs(j, k);
				if (newvis%x)
					fail = true;
			}
			swap(r, c);
			bool fail2 = false;
			for (int j = 0;j < r;j++) for (int k = 0;k < c;k++)
				vis[j][k] = false;
			for (int j = 0;j < x;j++)
				if (omino[x][i][j][0] < r && omino[x][i][j][1] < c)
					vis[omino[x][i][j][0]][omino[x][i][j][1]] = true;
				else
				{
					fail2 = true;
					break;
				}
			if (!fail2) for (int j = 0;j < r;j++) for (int k = 0;k < c;k++) if (!vis[j][k])
			{
				newvis = 0;
				dfs(j, k);
				if (newvis%x)
					fail2 = false;
			}
			if (fail && fail2) goto fail;
		}
		printf("GABRIEL\n");
		continue;
fail:
		printf("RICHARD\n");
	}
	return 0;
}
