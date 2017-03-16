#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, a[105][105], row_max[105], col_max[105], test;

void solve(int kase)
{
	printf("Case #%d: ", kase);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
		{
			if (a[i][j] >= row_max[i] || a[i][j] >= col_max[j])
				continue;
			puts("NO");
			return;
		}
	puts("YES");
}

int main()
{
	scanf("%d", &test);
	for (int kase = 1; kase <= test; ++kase)
	{
		scanf("%d %d", &n, &m);
		memset(row_max, 0, sizeof(row_max));
		memset(col_max, 0, sizeof(col_max));
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= m; ++j)
			{
				scanf("%d", &a[i][j]);
				row_max[i] = max(row_max[i], a[i][j]);
				col_max[j] = max(col_max[j], a[i][j]);
			}
		solve(kase);
	}
	
	return 0;
}
