#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include<queue>
#include<stack>
#include<map>
using namespace std;
const int INF=1<<30;
const int maxn=100005;
int n,m,a[maxn],dr[4][2]={0,1,1,0,-1,0,0-1},head[1005],pos,ans,tr[1005],in[1005];
bool vd[10005];
struct egde
{
	int v,next;
}eg[1000000];
void add(int x,int y)
{
	eg[pos].v=y,eg[pos].next=head[x];
	head[x]=pos++;
}
void dfs(int u)
{
	if(ans==1)return ;
	vd[u]=1;
	for(int i=head[u];i>=0;i=eg[i].next)
	{
		int v=eg[i].v;
		if(!vd[v])
		{
			dfs(v);
		}
		else 
		{
			ans=1;
		}
	}
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("ans.out","w",stdout);
	int T,x,y;
	scanf("%d",&T);
	for(int t=1;t<=T;t++)
	{
		scanf("%d",&n);
		memset(head,-1,sizeof(head));
		pos=0;
		memset(in,0,sizeof(in));
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&m);
			for(int j=0;j<m;j++)
			{
				scanf("%d",&x);
				add(i,x);
				in[x]++;
			}
		}
		memset(vd,0,sizeof(vd));
		memset(tr,-1,sizeof(tr));
		ans=0;
		for(int i=1;i<=n;i++)
		{
			memset(vd,0,sizeof(vd));
			dfs(i);
			if(ans==1)break;
		}
		if(ans)
			printf("Case #%d: Yes\n",t);
		else
			printf("Case #%d: No\n",t);
	}
	return 0;
}