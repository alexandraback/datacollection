#include <cstdio>

bool fringe[7][7];
bool point[7][7];
bool visit[7][7];
bool mine[7][7];

char __input[32];
int t;

int r;
int c;
int m;

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void dfs(int x, int y)
{
	if (visit[x][y])
		return;
	visit[x][y] = true;
	if (fringe[x][y])
		return;
	for (int i = 0;i < 8;i++) if (x+dx[i] > 0 && x+dx[i] < r+1 && y+dy[i] > 0 && y+dy[i] < c+1)
		dfs(x+dx[i], y+dy[i]);
}

bool check()
{
	for (int i = 0;i <= r+1;i++) for (int j = 0;j <= c+1;j++)
		fringe[i][j] = point[i][j] = visit[i][j] = false;
	for (int i = 1;i <= r;i++) for (int j = 1;j <= c;j++) if (mine[i][j]) for (int k = 0;k < 8;k++)
		fringe[i+dx[k]][j+dy[k]] = true;
	for (int i = 1;i <= r;i++) for (int j = 1;j <= c;j++) if (!fringe[i][j] && !mine[i][j])
	{
		dfs(i, j);
		for (int I = 1;I <= r;I++) for (int J = 1;J <= c;J++) if (!mine[I][J] && !visit[I][J])
			return false;
		point[i][j] = true;
		return true;
	}
	return false;
}

bool solve(int x, int y, int remain)
{
	if (r*c-(x-1)*c-(y-1) < m-remain)
		return false;
	if (remain == m)
		return check();
	if (x == r+1)
		return false;
	int nextX = x;
	int nextY = y + 1;
	if (nextY == c+1)
	{
		nextY = 1;
		nextX++;
	}
	mine[x][y] = true;
	if (solve(nextX, nextY, remain+1))
		return true;
	mine[x][y] = false;
	if (solve(nextX, nextY, remain))
		return true;
	return false;
}

int main()
{
	printf("Input file = "); fflush(stdout);
	scanf("%s", __input);
	freopen(__input, "r", stdin);
	freopen("out.C.txt", "w", stdout);
	scanf("%d", &t);
	for (int _ = 1;_ <= t;_++)
	{
		for (int i = 0;i < 7;i++) for (int j = 0;j < 7;j++)
			mine[i][j] = 0;
		printf("Case #%d:\n", _);
		scanf("%d%d%d", &r, &c, &m);
		if (m+1 == r*c)
		{
			for (int i = 0;i < r-1;i++)
			{
				for (int j = 0;j < c;j++)
					printf("*");
				printf("\n");
			}
			for (int i = 0;i < c-1;i++)
				printf("*");
			printf("c\n");
			continue;
		}
		if (solve(1, 1, 0))
		{
			for (int i = 1;i <= r;i++)
			{
				for (int j = 1;j <= c;j++)
					printf("%c", mine[i][j]?'*':point[i][j]?'c':'.');
				printf("\n");
			}
		} else
			printf("Impossible\n");
	}
}
