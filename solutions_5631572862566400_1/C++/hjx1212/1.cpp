#include <bits/stdc++.h>
using namespace std;

vector<int> v[1005];
int f[1005],s1,s2;
int vis[1005];

int dfs(int x,int p,int d)
{
	if(vis[x]>0)
	{
		s2=max(s2,d-vis[x]);
		return 0;
	}
	int s=0;
	vis[x]=d;
	for(auto y:v[x])
		if(y!=p)
			s=max(s,dfs(y,x,d+1));
	vis[x]=-1;
	return s+1;
}

int main()
{
	freopen("C-large.in","r",stdin);
	freopen("0.out","w",stdout);
	int T,_,i,n;
	for(scanf("%d",&T),_=1;_<=T;_++)
	{
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			v[i].clear(),vis[i]=0;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&f[i]);
			v[f[i]].push_back(i);
		}
		s1=s2=0;
		for(i=1;i<=n;i++)
			if(!vis[i]&&f[f[i]]==i)
				s1+=dfs(i,f[i],1)+dfs(f[i],i,1);
		for(i=1;i<=n;i++)
			if(!vis[i])
				dfs(i,0,1);
		printf("Case #%d: %d\n",_,max(s1,s2));
	}
	return 0;
}
