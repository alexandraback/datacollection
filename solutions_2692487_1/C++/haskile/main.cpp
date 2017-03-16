#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
const int maxN = 1000;
int Armin, n;
int a[maxN], cost[maxN];

int Solve()
{
	scanf("%d%d", &Armin, &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	sort(a, a + n);
	if (Armin == 1)
		return n;
	for (int i = 0; i < n; ++i)
	{
		cost[i] = (i != 0?cost[i-1]:0);
		if (a[i] >= Armin)
		{
			while (a[i] >= Armin)
			{
				cost[i]++;
				Armin += (Armin - 1);
			}
		}
		Armin += a[i];
	}
	int ans = n;
	for (int i = 0; i < n; ++i)
	{
		int curr = cost[i] + n - i - 1;
		ans = min(ans, curr);
	}
	return ans;
}

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int test = 0; test < tests; test++)
	{
		int ans = Solve();
		printf("Case #%d: %d\n", test + 1, ans);
	}

	return 0;
}