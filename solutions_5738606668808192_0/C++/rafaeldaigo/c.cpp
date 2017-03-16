#include<cstdio>
#include<cstring>
#include<queue>
#include<utility>
#include<vector>
#include<algorithm>

using namespace std;
int primes[1000000];
int pcount;

bool test(long long binary, int size, int base, int divisor)
{
	int rem = 0;
	long long numtest = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		if (numtest <= divisor)
			numtest *= base;
		rem = (rem * base) % divisor;
		if (binary & (1LL << i))
		{
			rem = (rem + 1) % divisor;
			if (numtest <= divisor)
				numtest++;
		}
	}
	return numtest > divisor && rem == 0;
}

int main()
{
	int t, teste;
	scanf("%d\n", &teste);

	primes[0] = 2;
	pcount = 1;
	for (int a = 3; a < (1 << 10); a += 2)
	{
		bool failed = false;
		for (int b = 1; b < pcount; b++)
		{
			if (primes[b] * primes[b] > a)
			{
				break;
			}
			if (a % primes[b] == 0)
			{
				failed = true;
				break;
			}
		}
		if (failed == false)
		{
			primes[pcount++] = a;
		}
	}

	for (int t = 0; t < teste; t++)
	{
		long long i;
		int n, j;
		scanf("%d %d\n", &n, &j);

		printf("Case #%d:\n", t + 1);
		int count = 0;
		int divisors[11];
		for (i = (1LL << (n - 1)) + 1; i < (1LL << n); i += 2)
		{
			int a;
			for (a = 2; a <= 10; a++)
			{
				int b;
				for (b = 0; b < pcount; b++)
				{
					if (test(i, n, a, primes[b]))
					{
						break;
					}
				}
				if (b >= pcount)
					break;
				divisors[a] = primes[b];
			}
			if (a > 10)
			{
				count++;
				for (int b = n - 1; b >= 0; b--)
				{
					if (i & (1LL << b))
						printf("1");
					else
						printf("0");
				}
				for (a = 2; a <= 10; a++)
				{
					printf(" %d", divisors[a]);
				}
				printf("\n");
			}
			if (count == j)
				break;
		}
	}
	return 0;
}
