#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define lli long long int

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("ans.out", "w", stdout);
	int tc, r, c, w, ans;
	scanf("%d", &tc);
	for (int t = 1; t <= tc; t++)
	{
		scanf("%d%d%d", &r, &c, &w);
		ans = 0;
		if (r == 1) {
			ans += c / w;
			if (c % w == 0)
				ans--;
			ans += w;
		}
		else
		{
			ans = c / w;
			ans *= r;
			if (c % w == 0)
				ans--;
			ans += w;
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}