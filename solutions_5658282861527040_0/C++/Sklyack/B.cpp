#include <cstdio>

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int ncases, t;
	scanf("%d", &ncases);
	for(t = 1; t <= ncases; ++t)
	{
		int a, b, k;
		int x, y, c;
		int ans = 0;
		scanf("%d%d%d", &a, &b, &k);
		for(x = 0; x < a; ++x)
			for(y = 0; y < b; ++y)
			{
				c = (x & y);
				ans += (0 <= c && c < k);
			}
			printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}
