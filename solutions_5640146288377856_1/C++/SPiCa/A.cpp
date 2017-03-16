#include <cstdio>
int T,cas,R,C,W,ans,p,q;

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	for (cas=1; cas<=T; ++cas)
	{
		scanf("%d%d%d", &R, &C, &W);
		ans = 0;
		p = C;
		while (p > W*2-1)
		{
			++ans;
			p -= W;
		}
		if (p == W)
		{
			ans += W;
		} else
		{
			ans += W+1;
		}
		if (R > 1)
		{
			q = 0;
			p = C;
			while (p >= W)
			{
				++q;
				p -= W;
			}
			ans += q*(R-1);
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}

