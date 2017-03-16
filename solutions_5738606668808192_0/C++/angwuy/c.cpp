#include <cstdio>
#include <cstring>
#include <cmath>


long long isPrime(long long n)
{
	long long m = (long long)sqrt(n);
	for (int i = 2; i <= m; ++i)
		if (n % i == 0) return i;
	return 1;
}

int n = 16;
int j = 50;
long long f[11];

void solve()
{
	long long cur = ((long long)1 << (n - 1)) + 1;
	while (j > 0)
	{
		bool ok = true;
		for (int i = 2; i <= 10; ++i)
		{
			long long tot = 0;
			long long mul = 1;
			for (int j = 0; j < n; ++j)
			{
				tot += mul * (((1 << j) & cur) >> j);
				mul *= i;
			}
			f[i] = isPrime(tot);
			if (f[i] == 1)
			{
				ok = false;
				break;
			}
		}
		if (ok)
		{
			for (int i = n - 1; i >= 0; --i)
				printf("%d", (((1 << i) & cur) >> i));
			for (int i = 2 ; i <= 10; ++i)
				printf(" %d", f[i]);
			printf("\n");
			--j;
		}
		cur += 2;
	}
}

int main()
{
	printf("Case #1:\n");
	solve();
	return 0;
}