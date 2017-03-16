#include <cstdio>
#include <cstring>

const int MAXN = 100;

int n, m, k;
char a[MAXN][MAXN];

bool proc(int n, int m, int k)
{
	if (n == 2 || m == 2)
	{
	}
	else
	{
		if (
	}
}

void solve()
{
	scanf("%d %d %d", &n, &m, &k);
	if (n * m <= k)
	{
		printf("EEEEEEEEEEEEEEEEEEEEEEEEEEEEEError\n");
	}
	if (n == 1)
	{
		printf("c");
		for (int i = 2; i <= m - k; ++i)
			printf(".");
		for (int i = 1; i <= k; ++i)
			printf("*");
		printf("\n");
		return;
	}
	if (m == 1)
	{
		printf("c\n");
		for (int i = 2; i <= n - k; ++i)
			printf(".\n");
		for (int i = 1; i <= k; ++i)
			printf("*\n");
		return;
	}
	if (n * m - k < 4 && n * m - k > 1)
	{
		printf("Impossible\n");
		return;
	}
	if (n * m - k == 1)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			if (i + j == n + m) printf("c");
			else            printf("*");
			printf("\n");
		}
		return;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (i == 2) continue;
		for (int j = 1; j <= m; ++j)
		{
			if (i == 1 && j == 1) a[i][j] = 'c';
			else
			{
			}
		}
	}
}

int main()
{
	freopen("C-small-attempt0.in", "r", stdin);
	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d:\n", ii);
		solve();
	}
	return 0;
}