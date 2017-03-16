#include <cstdio>
#include <cstring>

int k, c, s;
long long a[120];

void solve()
{
	scanf("%d %d %d", &k, &c, &s);
	if (c * s < k)
	{
		printf(" IMPOSSIBLE\n");
		return;
	}
	int cur = 0;
	int l = 0;
	while (cur < k)
	{
		long long num = 0;
		for (int i = 0; i < c; ++i)
		{
			if (cur == k) --cur;
			num = num * k + cur;
			++cur;
		}
		a[++l] = num;
	}
	for (int i = 1; i <= l; ++i)
		printf(" %I64d", a[i] + 1);
	printf("\n");
}

int main()
{
	freopen("d.in", "r", stdin);
	int nn;
	scanf("%d\n", &nn);
	for (int ii = 1; ii <= nn; ++ii)
	{
		printf("Case #%d:", ii);
		solve();
	}
	return 0;
}