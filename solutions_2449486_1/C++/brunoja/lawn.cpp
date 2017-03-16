#include <cstdio>
#include <cstring>

#define N 100

int mat[N][N], n, m;

bool fine(int i, int j, int di, int dj, int h)
{
	while (i < n && j < m)
	{
		if (mat[i][j] > h) return false;
		i += di;
		j += dj;
	}
	return true;
}

bool solve(int h)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (mat[i][j] == h)
			{
				if (fine(i, 0, 0, 1, h) || fine(0, j, 1, 0, h)) continue;
				return false;
			}
		}
	}
	return true;
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int q = 1; q <= t; ++q)
	{
		printf("Case #%d: ", q);
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
				scanf("%d", &mat[i][j]);
		bool g = 1;
		for (int h = 100; h >= 1 && g; --h)
		{
			g = solve(h);
		}
		if (g) printf("YES\n");
		else printf("NO\n");
	}
}
