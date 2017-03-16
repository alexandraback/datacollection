#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
int n,ans;
struct ty{char s[23];int len;}fir[1010],sec[1010],x[1010],y[1010];
int last[1010],to[1010],next[1010],fa[1010],top;
bool vis[1010];
bool operator < (ty c1,ty c2)
{
	if(c1.len!=c2.len)
		return c1.len<c2.len;
	for(int i=0;i<c1.len;++i)
		if(c1.s[i]!=c2.s[i])
			return c1.s[i]<c2.s[i];
	return 0;
}
bool operator == (ty c1,ty c2)
{
	if(c1.len!=c2.len)
		return 0;
	for(int i=0;i<c1.len;++i)
		if(c1.s[i]!=c2.s[i])
			return 0;
	return 1;
}
bool dfs(int now)
{
	vis[now]=1;
	for(int i=last[now];i;i=next[i])
		if(fa[to[i]]==0||(vis[fa[to[i]]]==0&&dfs(fa[to[i]])))
		{
			fa[to[i]]=now;
			return 1;
		}
	return 0;
}
int main()
{
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int t,tt;
	int i,j,numx,numy,tx=1,ty=1;
	scanf("%d",&tt);
	for(t=1;t<=tt;++t)
	{
		ans=0;
		tx=1;
		ty=1;
		memset(fa,0,sizeof(fa));
		memset(last,0,sizeof(last));
		top=0;
		scanf("%d",&n);
		for(i=1;i<=n;++i)
		{
			scanf("%s",fir[i].s);
			fir[i].len=strlen(fir[i].s);
			scanf("%s",sec[i].s);
			sec[i].len=strlen(sec[i].s);
			x[i]=fir[i];
			y[i]=sec[i];
		}
		sort(x+1,x+n+1);
		sort(y+1,y+n+1);
		for(i=2;i<=n;++i)
			if(!(x[i]==x[i-1]))
				x[++tx]=x[i];
		for(i=2;i<=n;++i)
			if(!(y[i]==y[i-1]))
				y[++ty]=y[i];
		for(i=1;i<=n;++i)
		{
			for(j=1;j<=tx;++j)
				if(fir[i]==x[j])
				{
					numx=j;
					break;
				}
			for(j=1;j<=ty;++j)
				if(sec[i]==y[j])
				{
					numy=j;
					break;
				}
			++top;
			to[top]=numy;
			next[top]=last[numx];
			last[numx]=top;
		}
		for(i=1;i<=tx;++i)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i))
				++ans;
		}
		printf("Case #%d: %d\n",t,n-(tx+ty-ans));
	}
	return 0;
}

