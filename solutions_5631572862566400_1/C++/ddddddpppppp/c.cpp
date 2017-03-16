#include<cstdio>
#include<cstring>
#include<string>
#include<cmath>
#include<iostream>
#include<algorithm>

using namespace std;

#define fo(i,a,b) for (int i=a;i<=b;i++)
#define fd(i,a,b) for (int i=a;i>=b;i--)
	
typedef long long ll;

const int maxn=2100;

int T,n,tot,ans,sum,bfn[maxn],f[maxn],head[maxn*2],next[maxn*2],g[maxn];

void link(int x,int y)
{
	head[++tot]=y;
	next[tot]=g[x];
	g[x]=tot;
}

int dfs(int pos,int dep,int oth)
{
	int ret=dep;
	for (int i=g[pos];i;i=next[i])
		if (head[i]!=oth) ret=max(ret,dfs(head[i],dep+1,oth));
	return ret;
}

int main()
{
	freopen("data.in","r",stdin);
	freopen("data.out","w",stdout);
	scanf("%d",&T);
	fo(id,1,T)
	{
		memset(g,0,sizeof(g));
		memset(bfn,0,sizeof(bfn));
		memset(f,0,sizeof(f));
		ans=tot=0;
		scanf("%d",&n);
		fo(i,1,n) 
		{
			scanf("%d",&f[i]);
			link(f[i],i);
		}
		tot=0;
		fo(i,1,n)
			if (!bfn[i])
			{
				int sta=++tot;
				int pos=i;
				bfn[i]=tot;
				while (!bfn[f[pos]]) bfn[pos=f[pos]]=++tot;
				if (bfn[f[pos]]>=sta) ans=max(ans,tot-bfn[f[pos]]+1);
			}
		sum=0;
		fo(i,1,n)
			if (f[f[i]]==i) sum+=dfs(i,1,f[i])+dfs(f[i],1,i);
		ans=max(ans,sum/2);
		printf("Case #%d: %d\n",id,ans);
	}
}