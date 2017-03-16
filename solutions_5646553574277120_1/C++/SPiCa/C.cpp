#include <cstdio>
int T,cas,D,i,dt,ans;
long long C,V,d[111],r,nb;

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	scanf("%d", &T);
	for (cas=1; cas<=T; ++cas)
	{
		scanf("%I64d%d%I64d", &C, &D, &V);
		for (i=1; i<=D; ++i) scanf("%I64d", &d[i]);
		dt = 1;
		d[D+1] = 1000000007;
		r = 0;
		ans = 0;
		while (r < V)
		{
			while (d[dt] < r+1) ++dt;
			if (d[dt] == r+1)
			{
				r += d[dt]*C;
				++dt;
				while (dt<=D && d[dt]<=r)
				{
					r += d[dt]*C;
					++dt;
				}
			} else
			{
				++ans;
				nb = r+1;
				r += nb*C;
				while (dt<=D && d[dt]<=r)
				{
					r += d[dt]*C;
					++dt;
				}
			}
		}
		printf("Case #%d: %d\n", cas, ans);
	}
	return 0;
}
