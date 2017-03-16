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
using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

typedef long long int int64;

int solve()
{
	int r, c, w;
	scanf("%d%d%d", &r, &c, &w);
	int ans = (c / w) * r + (w - 1);
	if (c % w != 0)
		ans++;
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
