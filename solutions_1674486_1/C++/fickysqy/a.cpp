#include <iostream>
#include <stdio.h>
#include <queue>
#include <memory.h>

using namespace std;

#define N 1001
#define INF 100000000

int t,n,list[N],dis[N];
bool vis[N];
struct ab
{
	int des,next;
}e[10*N];
struct node
{
	int v,d;
	node (int vv=0,int dd=0):v(vv),d(dd){}
	bool operator < (const node &other) const
	{
		if(d!=other.d)
			return d>other.d;
		return v>other.v;
	}
};

void add(int st,int ed,int i)
{
	e[i].des = ed;
	e[i].next = list[st];
	list[st] = i;
}
bool dij(int s)
{
	int i,j,k;
	priority_queue<node> q;
	for(i=0; i<n; i++)
		dis[i] = INF;
	memset(vis,0,sizeof(vis));
	dis[s] = 0;
	vis[s] = 1;
	q.push(node(s,0));
	while(!q.empty())
	{
		node u = q.top();
		vis[u.v] = 1;
		q.pop();
		for(i=list[u.v]; i!=-1; i=e[i].next)
		{
			k = e[i].des;
			if(dis[k]!=INF)
				return 1;
			if(dis[k]>dis[u.v]+1)
			{
				dis[k] = dis[u.v]+1;
				q.push(node(k,dis[k]));
			}
		}
		while(!q.empty() && vis[q.top().v])
			q.pop();
	}
	return 0;
}
int main()
{
	freopen("A-large.in","r",stdin);
	freopen("output.out","w",stdout);
	int i,j,cas=1,m,k,cnt;
	scanf("%d",&t);
	while(t--)
	{
		printf("Case #%d: ",cas++);
		memset(list,-1,sizeof(list));
		scanf("%d",&n);
		cnt = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d",&m);
			while(m--)
			{
				scanf("%d",&k);
				add(i,k-1,cnt++);
			}
		}
		for(i=0; i<n; i++)
			if(dij(i))
			{
				puts("Yes");
				break;
			}
		if(i>=n)
			puts("No");
	}
}
