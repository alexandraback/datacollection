#include <cstdio>

int n, x;
long long sol[20];

long long to_ba(long long x, long long b)
{
	long long res = 0, p = 1;
	for (int i = 0; i < n; i++) res += x % 2 * p, x /= 2, p *= b;
	return res;
}

long long fnd(long long x)
{
	for (long long i = 2; i * i <= x; i++) if (!(x % i)) return i;
	return 0;
}

void solve()
{
	scanf("%d %d", &n, &x);
	printf("Case #1:\n");
	int z = 0;
	for (int i = 0; i < 1 << n - 2; i++)
	{
		int r = (1 << n - 1) + 2 * i + 1, f = 1;
		for (int j = 2; j <= 10; j++)
		{
			sol[j] = fnd(to_ba(r, j));
			if (!sol[j])
			{
				f = false;
				break;
			}
		}
		if (!f) continue;
		for (int j = 0; j < n; j++) printf("%d", r >> (n - j - 1) & 1);
		for (int j = 2; j <= 10; j++) printf(" %lld", sol[j]);
		printf("\n");
		z++;
		if (z == x) break;
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	solve();
	return 0;
}