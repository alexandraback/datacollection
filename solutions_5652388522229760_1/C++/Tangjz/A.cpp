#include <cstdio>
#include <cstring>
const int maxt = 100, maxn = 1000000, maxd = 10;
int t, n, cnt, now, ans;
bool vis[maxd];
int main()
{
	scanf("%d", &t);
	for(int Case = 1; Case <= t; ++Case)
	{
		scanf("%d", &n);
		if(!n)
		{
			printf("Case #%d: INSOMNIA\n", Case);
			continue;
		}
		cnt = 0;
		memset(vis, 0, sizeof vis);
		for(ans = n; cnt < maxd; ans += n)
			for(now = ans; now && cnt < maxd; now /= 10)
				if(!vis[now % 10])
				{
					vis[now % 10] = 1;
					++cnt;
				}
		ans -= n;
		printf("Case #%d: %d\n", Case, ans);
	}
	return 0;
}
