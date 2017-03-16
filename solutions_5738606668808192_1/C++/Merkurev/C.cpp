#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <numeric>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int n;

bool test(unsigned int x, int base, int d)
{
	if (base == 2)
		return x % d == 0;
	int ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		ans *= base;
		ans += ( (x >> i) & 1U);
		ans %= d;
	}
	return ans == 0;
}

int getCert(unsigned int x, int base)
{
	for (int i = 2; i < 100; i++)
		if (test(x, base, i) )
			return i;
	return 0;
}

int cert[11];

void printAns(unsigned int x)
{
	for (int i = n - 1; i >= 0; i--)
	{
		printf("%u", (x >> i) & 1U);
	}
	for (int i = 2; i <= 10; i++)
		printf(" %d", cert[i] );
	printf("\n");
}

void solve()
{
	int j;
	scanf("%d%d", &n, &j);
	long long cnt = 0;
	unsigned int limit = (1U << n);
	if (limit == 2)
		limit = 1;
	int cntWin = 0;
	for (unsigned int x = (1U << (n - 1) ) + 1; x != limit; x += 2)
	{
		cnt++;
		bool win = true;
		for (int i = 2; i <= 10; i++)
		{
			cert[i] = getCert(x, i);
			if (cert[i] == 0)
			{
				win = false;
				break;
			}
		}
		if (win)
		{
			cntWin++;
			printAns(x);
			if (cntWin == j)
				break;
		}
	}
	if (cntWin != j) throw;
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("outputBig.txt", "w", stdout);

	int nt;
	scanf("%d", &nt);
	for (int i = 1; i <= nt; i++)
	{
		printf("Case #%d:\n", i);
		eprintf("Case #%d .. %d\n", i, nt);
		solve();
	}


}

int main(int argc, char **)
{
	if (argc == 1)
		multitest();
	else
		solve();

	return 0;
}


