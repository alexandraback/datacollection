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
#include <bitset>
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

const int V = 1000;

bitset<V> dp;

void add(int val, int c)
{
	for (int i = 0; i < c; i++)
		dp |= (dp << val);
}

int solve()
{
	dp.reset();
	dp[0] = 1;
	
	int c, d, v;
	scanf("%d%d%d", &c, &d, &v);
	for (int i = 0; i < d; i++)
	{
		int a;
		scanf("%d", &a);
		add(a, c);
	}

	int ans = 0;
	for (int i = 1; i <= v; i++)
	{
		if (dp[i])
			continue;
		add(i, c);
		ans++;
	}

	return ans;
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; i++)
		printf("Case #%d: %d\n", i + 1, solve());

	return 0;
}
