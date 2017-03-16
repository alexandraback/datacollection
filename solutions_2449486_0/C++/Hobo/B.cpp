#include <cstdio>
#include <cstring>

int n, m, map[110][110];

bool row(int x, int y)
{
	for(int i = y; i > 0; i --)
		if(map[x][i] > map[x][y]) return false;
	for(int i = y; i <= m; i ++)
		if(map[x][i] > map[x][y]) return false;
	return true;
}
bool column(int x, int y)
{
	for(int i = x; i > 0; i --)
		if(map[i][y] > map[x][y]) return false;
	for(int i = x; i <= n; i ++)
		if(map[i][y] > map[x][y]) return false;
	return true;
}

void work()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			scanf("%d", &map[i][j]);
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= m; j ++)
			if(!row(i, j) && !column(i, j))
			{
				printf("NO\n");
				return;
			}
	printf("YES\n");
	return;
}

int main()
{
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
	int _;
	scanf("%d", &_);
	for(int i = 1; i <= _; i ++)
		printf("Case #%d: ", i), work();
	return 0;
}
