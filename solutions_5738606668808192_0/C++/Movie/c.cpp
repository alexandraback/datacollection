#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

long long convert (long long n, long long base)
{
	if (base == 2) return n;
	if (!n) return 0;

	return n%2 + base * convert (n/2, base);
}

long long print (long long n)
{
	if (n)
	{
		print (n/2);
		printf ("%lld", n%2);
	}
}

void f (long long full, long long half)
{
	print (full);

	for (int b = 2; b <= 10; b++)
	{
		printf (" %lld", convert (half, b));
	}

	printf ("\n");
}

int main (void)
{
	int T;

	scanf ("%d", &T);

	for (int t = 1; t <= T; t++)
	{
		long long N, K;

		scanf ("%lld %lld", &N, &K);

		printf ("Case #%d:\n", t);

		long long L = N/2 - 2;
		long long Lb = 1 << L;

		for (int i = 0; i < Lb; i++)
		{
			long long half = 1;

			half <<= L;
			half |= i;
			half <<= 1;
			half |= 1;

			long long full = half;

			if (N%2) full <<= 1;
			full <<= L + 2;
			full |= half;

			f (full, half);

			K--;
			if (!K) break;
		}
	}
}