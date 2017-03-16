#include <stdio.h>

int a[105][105], row[105], col[105], m, n;

int check(void)
{
	int i, j;

	for (i = 1; i <= n; i++)
		for (j = 1; j <= m; j++)
			if (row[i] > a[i][j] && col[j] > a[i][j])
				return 0;
	return 1;
}

int main()
{
	int i, j, t, casen;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &t);
	for (casen = 1; casen <= t; casen++) {
		scanf("%d%d", &n, &m);
		for (i = 1; i <= n; i++)
			for (j = 1; j <= m; j++)
				scanf("%d", &a[i][j]);
		for (i = 1; i <= n; i++) {
			row[i] = a[i][1];
			for (j = 2; j <= m; j++)
				if (a[i][j] > row[i])
					row[i] = a[i][j];
		}
		for (j = 1; j <= m; j++) {
			col[j] = a[1][j];
			for (i = 2; i <= n; i++)
				if (a[i][j] > col[j])
					col[j] = a[i][j];
		}
		printf("Case #%d: %s\n", casen, (check()) ? "YES" : "NO");
	}
	return 0;
}