#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int r, c, w;

int solve()
{
	return c / w + w - (c % w == 0);
}

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int q = 0; q < t; q++)
	{
		scanf("%d%d%d", &r, &c, &w);
		int ans = (r - 1) * (c / w);
		ans += solve();
		printf("Case #%d: %d\n", q + 1, ans);
	}
	return 0;
}