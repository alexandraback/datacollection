#include <cstdio>

int n, f[10];

void solve(int test)
{
	scanf("%d", &n);
	if (!n)
	{
		printf("Case #%d: INSOMNIA\n", test);
		return;
	}
	long long k = n;
	for (int i = 0; i < 10; i++) f[i] = false;
	while (true)
	{
		long long x = k, g = 0;
		while (x) f[x % 10] = true, x /= 10;
		for (int i = 0; i < 10; i++) if (!f[i])
		{
			g = true;
			break;
		}
		if (!g)
		{
			printf("Case #%d: %lld\n", test, k);
			return;
		}
		k += n;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) solve(i);
	return 0;
}