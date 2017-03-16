#include<bits/stdc++.h>

using namespace std;

typedef long long llint;
int T,n,du[1010],d[1010],sp[1010],l,r,p[1010];
int mask[1010];

int main()
{
	freopen("C.in","r",stdin);
	
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		printf("Case #%d: ", tt);
		scanf("%d",&n);
		memset(du,0,sizeof du);
		for(int i=1;i<=n;i++) scanf("%d",&p[i]),du[p[i]]++,d[i]=0;
		l=1; r=0;
		for(int i=1;i<=n;i++) if (du[i]==0) sp[++r] = i;
		for(;l<=r;l++)
		{
			du[p[sp[l]]]--;
			d[p[sp[l]]] = max(d[p[sp[l]]], d[sp[l]] + 1);
			if (du[p[sp[l]]] == 0) sp[++r]=p[sp[l]];
		}
		int ans=0, tot=0;
		memset(mask, 0, sizeof mask);
		for(int i=1;i<=n;i++) if (du[i] && !mask[i])
		{
			int now = p[i];
			mask[i] = 1;
			int cnt=1;
			while(now != i)
			{
				mask[now] = 1;
				now = p[now];
				cnt += 1;
			}
			if (cnt > 2) ans = max(ans, cnt);
			else tot += d[i] + d[p[i]] + 2;
		}
		printf("%d\n", max(ans, tot));
	}
	return 0;
}