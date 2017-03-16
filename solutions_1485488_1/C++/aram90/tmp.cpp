#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <map>
using namespace std;

int getin[105][105];
int patalok[105][105];
int w[105][105];
bool vis[105][105];
int h, n, m;
int dr[] = {-1,  0, +1,  0};
int dc[] = { 0, -1,  0, +1};

void dfs(int row, int col)
{
	w[row][col] = 0;
	int k;
	for(k = 0; k < 4; k++)
	{
		int r0 = row + dr[k];
		int c0 = col + dc[k];
		if(r0 < 1 || c0 < 1 || r0 > n || c0 > m) continue;
		if(patalok[r0][c0] - max(max(getin[row][col], getin[r0][c0]), h) < 50) continue;
		if(patalok[row][col] - getin[r0][c0] < 50) continue;
		if(w[r0][c0])
		{
			dfs(r0, c0);
		}
	}
}

int main()
{
	freopen("B-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tt;
	scanf("%d", &tt);
	int ii;
	for(ii = 1; ii <= tt; ii++)
	{
		scanf("%d%d%d", &h, &n, &m);
		int i, j;
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				scanf("%d", patalok[i] + j);
			}
		}
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				scanf("%d", getin[i] + j);
			}
		}
		memset(w, -1, sizeof(w));
		dfs(1, 1);
/*		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <= m; j++)
			{
				cout << w[i][j] << ' ';
			}
			cout << endl;
		}*/
		memset(vis, 0, sizeof(vis));
		for(;;)
		{
			int best_row = -1;
			int best_col = -1;
			for(i = 1; i <= n; i++)
			{
				for(j = 1; j <= m; j++)
				{
					if(!vis[i][j] && w[i][j] != -1 && (best_row == -1 || w[i][j] < w[best_row][best_col]))
					{
						best_row = i;
						best_col = j;
					}
				}
			}
			if(best_row == -1)
			{
				break;
			}
			vis[best_row][best_col] = true;
			if(vis[n][m])
			{
				break;
			}
			int k;
			int row = best_row;
			int col = best_col;
			for(k = 0; k < 4; k++)
			{
				int r0 = row + dr[k];
				int c0 = col + dc[k];
				if(r0 < 1 || c0 < 1 || r0 > n || c0 > m) continue;
				if(patalok[row][col] - getin[r0][c0] < 50) continue;
				if(patalok[r0][c0] - max(getin[row][col], getin[r0][c0]) < 50) continue;
				int ww = w[row][col];
				if((h - ww) > patalok[r0][c0] - 50)
				{
					ww = h - (patalok[r0][c0] - 50);
				}
				if((h - ww) - getin[row][col] < 20) ww += 100;
				else ww += 10;
				if(w[r0][c0] == -1 || ww < w[r0][c0])
				{
					w[r0][c0] = ww;
				}
			}			
		}
		printf("Case #%d: %d.%d\n", ii, w[n][m] / 10, w[n][m] % 10);
	}
	return 0;
}
