#include<stdio.h>
#include<set>
#include<string.h>
#include<time.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int post[110],vis[110];
int first[110],nxt[210000],vv[210000];

int sta[110],top;
int ind[110];

int cmp(int i,int j)
{
    return post[i]<post[j];
}
int st[110],tt,vvis[110];
void dfs1(int n)
{
    vvis[n]=1;
    for(int e=first[n];e;e=nxt[e])if(!vvis[vv[e]])
	dfs1(vv[e]);
}
int N;
int jud(int n)
{
    int u,v,i,j,e;
    memcpy(st,sta,sizeof(st));
    memcpy(vvis,vis,sizeof(vis));
    tt=top;

    for(i=tt;i>=1;i--)
    {
	int found=0;
	for(e=first[st[i]];e;e=nxt[e])if(vv[e]==n)
	{
	    found=1;
	    break;
	}
	if(found)
	    break;
    }
    if(i==0)
	return 0;
    while(tt>i)
	vvis[st[tt]]=2,tt--;
    for(i=1;i<=tt;i++)
	vvis[st[i]]=0;
    dfs1(n);
    for(i=1;i<=N;i++)if(!vvis[i])
	return 0;
    return 1;
}
void dfs(int n)
{
    printf("%d",post[n]);
    vis[n]=1;
    sta[++top]=n;
    for(int i=1;i<=N;i++)if(!vis[ind[i]]&&jud(ind[i]))
    {
	while(top>tt)
	    vis[sta[top--]]=2;
    	dfs(ind[i]);
	return;
    }
}
int main()
{
    int t,ii=0;
    int n,m,i,j,k,u,v,e;

    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);

    scanf("%d",&t);
    while(t--)
    {
	scanf("%d%d",&n,&m);
	memset(first,0,sizeof(first));
	e=2;

	for(i=1;i<=n;i++)
	    scanf("%d",&post[i]),ind[i]=i;
	sort(ind+1,ind+1+n,cmp);
	N=n;
	while(m--)
	{
	    scanf("%d%d",&u,&v);
	    nxt[e]=first[u],vv[e]=v,first[u]=e++;
	    nxt[e]=first[v],vv[e]=u,first[v]=e++;
	}
	m=2100000;
	for(i=1;i<=n;i++)
	    m=min(m,post[i]);
	printf("Case #%d: ",++ii);
	memset(vis,0,sizeof(vis));
	top=0;
	for(i=1;i<=n;i++)if(post[i]==m)
	    dfs(i);
	puts("");
    }
}
