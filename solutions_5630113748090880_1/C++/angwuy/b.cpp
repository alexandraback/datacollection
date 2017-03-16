#include <cstdio>
#include <cstring>

const int MAXN = 2550;

int n;
int a[MAXN];

void solve()
{
	memset(a, 0, sizeof(a));
	scanf("%d", &n);
	int k;
	for (int i = 1; i <= 2 * n - 1; ++i)
	for (int j = 1; j <= n; ++j)
	{
		scanf("%d", &k);
		a[k] ^= 1;
	}
	for (int i = 1; i < MAXN; ++i)
	if (a[i] > 0)
		printf(" %d", i);
	printf("\n");
}

int main()
{
	freopen("b.in", "r", stdin);
	int tt;
	scanf("%d\n", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		printf("Case #%d:", ii);
		solve();
	}
	return 0;
}