#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int T,Case,n,i,j,k,u,v,ans,sum,Max,l1,l2,l;
int f[1000005],fa[100005],len[100005];
int vis[1000005];
bool incir[1000005];

int get(int x){return fa[x]==x?x:fa[x]=get(fa[x]);}
int cir_len(int x)
{
	int i,j,k;
	for(i=1;i<=n;++i)vis[i]=0;
	for(k=1;x;x=f[x],++k)
	{
		if(vis[x])break;
		vis[x]=k;
	}
	k-=vis[x];
	incir[x]=true;
	for(i=f[x];i!=x;i=f[i])incir[i]=true;
	return k;
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	scanf("%d",&T);
	for(;T;--T)
	{
		scanf("%d",&n);
		ans=sum=Max=0;
		for(i=1;i<=n;++i)scanf("%d",&f[i]),fa[i]=i,incir[i]=false;
		for(i=1;i<=n;++i)
		{
			u=get(i);v=get(f[i]);
			fa[u]=v;
		}
		for(i=1;i<=n;++i)
		{
			len[i]=cir_len(i);
			if(len[i]>ans)ans=len[i];
		}
		for(i=1;i<=n;++i)
		if(fa[i]==i&&len[i]==2)
		{
			for(u=i;!incir[u];u=f[u]);
			v=f[u];
			l1=l2=0;
			for(j=1;j<=n;++j)
			if(get(j)==i&&!incir[j])
			{
				for(k=j,l=0;!incir[k];k=f[k],++l);
				if(k==u)
				{
					if(l>l1)l1=l;
				}
				else
				{
					if(l>l2)l2=l;
				}
			}
			if(l1<l2)swap(l1,l2);
			sum+=l1+2;
			if(l2>Max)Max=l2;
		}
		if(sum+Max>ans)ans=sum+Max;
		++Case;
		printf("Case #%d: %d\n",Case,ans);
	}
}
