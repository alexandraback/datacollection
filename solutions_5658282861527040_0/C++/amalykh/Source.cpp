#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <assert.h>
#include <queue>
#include <unordered_map>

using namespace std;

typedef long long ll;
#define mp make_pair

ll a, b, k;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int tests;
	scanf("%d", &tests);
	for (int q = 0; q < tests; q++)
	{
		scanf("%lld %lld %lld", &a, &b, &k);
		ll ans = 0;
		for (int i = 0; i < a; i++)
		{
			for (int j = 0; j < b; j++)
			if ((i & j) < k)
				ans++;
		}
		printf("Case #%d: ", q + 1);
		printf("%lld\n", ans);
	}
	return 0;
}