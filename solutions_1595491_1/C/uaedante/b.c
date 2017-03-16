#include <stdio.h>
#define MAXN 110
#define MAX(i, j) (((i)>(j))?(i):(j))
int f[MAXN][MAXN], a[MAXN], n, s, p;

int nor(int v, int p)
{
	if (!v)
		if (!p) return 1;
		else return 0;
	if ((v - 1) / 3 >= p - 1) return 1;
	else return 0;
}

int sup(int v, int p)
{
	if (v < 2) return -MAXN;
	if ((v - 2) / 3 >= p - 2) return 1;
	else return 0;
}

int main()
{
	int t, cc, i, j;
	scanf("%d", &t);
	f[0][0] = 0;
	for (i = 1; i < MAXN; i++)
		f[0][i] = -MAXN;
	for (cc = 1; cc <= t; cc++) {
		scanf("%d %d %d", &n, &s, &p);
		for (i = 1; i <= n; i++) scanf("%d", a + i);
		for (i = 1; i <= n; i++) {
			f[i][0] = f[i - 1][0] + nor(a[i], p);
			for (j = 1; j <= i; j++)
				f[i][j] = MAX(f[i - 1][j] + nor(a[i], p), f[i - 1][j - 1] + sup(a[i], p));
		}
		printf("Case #%d: %d\n", cc, f[n][s]);
	}
}
