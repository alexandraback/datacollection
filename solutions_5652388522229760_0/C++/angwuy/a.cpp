#include <cstdio>
#include <cstring>

const int MAXN = 100000;

int n;
int a[MAXN], l;
int b;

void solve()
{
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	l = 10;
	b = 0;
	int ans = 0;
	while (b < 1023 && l < MAXN - 10)
	{
		a[1] += n;
		for (int i = 1; i < l; ++i)
		if (a[i] >= 10)
		{
			a[i + 1] += a[i] / 10;
			a[i] %= 10;
		}
		while (a[l] >= 10)
		{
			a[l + 1] += a[l] / 10;
			a[l] %= 10;
			++l;
		}
		while (a[l] == 0 && l > 1) --l;
		for (int i = 1; i <= l; ++i)
			b |= (1 << a[i]);
		++ans;
		if (ans > 10000) break;
	}
	if (b != 1023)
		printf("INSOMNIA\n");
	else
	{
		for (int i = l; i >= 1; --i)
			printf("%d", a[i]);
		printf("\n");
	}
}

int main()
{
	freopen("a.in", "r", stdin);
	int nn;
	scanf("%d", &nn);
	for (int ii = 1; ii <= nn; ++ii)
	{
		printf("Case #%d: ", ii);
		solve();
	}
	return 0;
}