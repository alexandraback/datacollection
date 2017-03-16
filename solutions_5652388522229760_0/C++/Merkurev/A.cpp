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


bool used[10];

void solve()
{
	long long n;
	scanf("%lld", &n);
	memset(used, false, sizeof used);
	long long x = n;
	if (x == 0)
	{
		printf("INSOMNIA\n");
		return;
	}
	while (true)
	{
		long long y = x;
		while (y != 0)
		{
			used[y % 10] = true;
			y /= 10;
		}
		bool win = true;
		for (int i = 0; i < 10; i++)
			if (!used[i] )
				win = false;
		if (win) break;
		x += n;
	}
	printf("%lld\n", x);
}

void multitest()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);


	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		printf("Case #%d: ", i);
		eprintf("Case #%d .. %d\n", i, n);
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


