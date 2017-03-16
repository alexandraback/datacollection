#include <cstdio>
#include <cstring>
using namespace std;

int n;
int day[1010], att[1010], l[1010], r[1010], str[1010], dd[1010], dp[1010], ds[1010];
int h[2000000], nh[2000000];

int main()
{
	int T;
	scanf("%d", &T);
	for(int t=1; t<=T; t++)
	{
		scanf("%d", &n);
		for(int i=0; i<n; i++)
			scanf("%d%d%d%d%d%d%d%d", &day[i], &att[i], &l[i], &r[i], &str[i], &dd[i], &dp[i], &ds[i]);
		memset(h, 0, sizeof(h));
		memset(nh, 0, sizeof(nh));
		int ans = 0;
		while(1)
		{
			int today = 1e9;
			for(int i=0; i<n; i++) if(att[i] && today>day[i]) today = day[i];
			if(today == 1e9) break;
			for(int i=0; i<n; i++)
			{
				if(!att[i] || day[i]!=today) continue;
				bool suc = false;
				for(int pos=l[i]; pos<r[i]; pos++)
					if(h[pos+1000000]<str[i])
					{
						suc = true;
						if(nh[pos+1000000]<str[i]) nh[pos+1000000] = str[i];
					}
				if(suc) ans++;
				att[i]--;
				day[i] += dd[i];
				l[i] += dp[i]; r[i] += dp[i];
				str[i] += ds[i];
			}
			memcpy(h, nh, sizeof(h));
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}

