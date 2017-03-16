#include<cstdio>
#include<cstring>

const int maxn = 55;
char map[maxn][maxn];
bool vis[maxn][maxn], mine[maxn * maxn];
int R, C, M, queue[maxn * maxn];

int dirx[] = { -1, -1, 1, 1, -1, 1, 0, 0 };
int diry[] = { -1, 1, -1, 1, 0, 0, -1, 1 };
bool bfs();

bool dfs(int cur)
{
	if(cur == M)
	{
		if(bfs()) return true;
		return false;
	}
	for(int i = 0; i < R * C; i++) if(!mine[i])
	{
		mine[i] = true;
		int x = i / C, y = i % C;
		map[x][y] = '*';
		if(dfs(cur + 1)) return true;
		mine[i] = false;
		map[x][y] = '.';
	}
	return false;
}

bool check(int x, int y)
{
	if(x >= 0 && x < R && y >= 0 && y < C) return true;
	return false;
}

bool bfs()
{
	//printf("\n");
	/*for(int i = 0; i < R; i++)
		for(int j = 0; j < C; j++)
			printf("%c%s", map[i][j], j == C-1 ? "\n" : "");*/
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			if(map[i][j] == '*') continue;
			memset(vis, false, sizeof(vis));
			int front = 0, rear = 0;
			vis[i][j] = true;
			queue[rear++] = i * C + j;
			while(front < rear)
			{
				int x = queue[front] / C;
				int y = queue[front++] % C;
				bool ok = true;
				for(int d = 0; d < 8; d++)
				{
					int xx = x + dirx[d], yy = y + diry[d];
					if(check(xx, yy) && map[xx][yy] == '*') ok = false;
				}
				if(ok)
				{
					for(int d = 0; d < 8; d++)
					{
						int xx = x + dirx[d], yy = y + diry[d];
						if(check(xx, yy) && !vis[xx][yy])
						{
							vis[xx][yy] = true;
							queue[rear++] = xx * C + yy;
						}
					}
				}
			}
			bool ok = true;
			for(int p = 0; p < R; p++)
			{
				for(int q = 0; q < C; q++)
				{
					if(map[p][q] == '.' && !vis[p][q]) {
						ok = false;
						break;
					}
				}
				if(ok == false) break;
			}
			if(ok)
			{
				map[i][j] = 'c';
				for(int p = 0; p < R; p++)
					for(int q = 0; q < C; q++)
						printf("%c%s", map[p][q], q == C - 1 ? "\n" : "");
				return true;
			}
		}
	}
	return false;
}

int main()
{
	int T;
	scanf("%d", &T);
	for(int k = 1; k <= T; k++)
	{
		scanf("%d%d%d", &R, &C, &M);
		printf("Case #%d:\n", k);
		if(R > 1 && C > 1 && ((R*C - M > 1 && R*C - M< 4) || R*C - M == 5 || R*C - M == 7))
		{
			printf("Impossible\n");
			continue;
		}
		memset(map, '.', sizeof(map));
		memset(mine, false, sizeof(mine));
		if(!dfs(0)) printf("Impossible\n");
	}
	return 0;
}

