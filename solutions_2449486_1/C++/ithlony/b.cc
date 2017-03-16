#include <cstdio>
#include <cstring>

const int MAXN = 111;

int a[MAXN][MAXN], b[MAXN][MAXN];
int T, n, m;

bool check()
{
	for (int i = 0; i < n; ++i)
	{
		int big = a[i][0];
		for (int j = 1; j < m; ++j)
			if (big > a[i][j])
			{
				b[i][j] = 1;
			}
			else {
				big = a[i][j];
			}
		big = a[i][m - 1];
		for (int j = m - 2; j >= 0; --j)
			if (big > a[i][j])
			{
				b[i][j] = 1;
			}
			else {
				big = a[i][j];
			}
	}
	for (int j = 0; j < m; ++j)
	{
		int big = a[0][j];
		for (int i = 1; i < n; ++i)
			if (big > a[i][j])
			{
				if (b[i][j] > 0)
					return false;
			}
			else {
				big = a[i][j];
			}
		big = a[n - 1][j];
		for (int i = n - 2; i >= 0; --i)
			if (big > a[i][j])
			{
				if (b[i][j] > 0)
					return false;
			}
			else {
				big = a[i][j];
			}
	}

	return true;
}

int main()
{
	scanf("%d", &T);
	for (int tt = 1; tt <= T; ++tt)
	{
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < m; ++j)
			{
				scanf("%d", &a[i][j]);
				b[i][j] = 0;
			}
		printf("Case #%d: %s\n", tt, check() ? "YES" : "NO");
	}

	return 0;
}
