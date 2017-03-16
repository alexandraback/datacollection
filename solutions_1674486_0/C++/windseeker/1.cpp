#include<iostream>
#include<cstdio>

using namespace std;

const int Maxv=1100;
int bo[Maxv];
int n;
int head[Maxv];
int etot;
bool vis[Maxv];

struct Edge
{
	int to,next;
}edge[Maxv*Maxv];

void Init()
{
	memset(head,-1,sizeof(head));
	etot=0;
}

bool dfs(int u)
{
//	cout<<u<<" "<<vis[u]<<endl;
	if(vis[u])
	return true;
	int i;
	vis[u]=true;
	for(i=head[u];i!=-1;i=edge[i].next)
	{
		int v=edge[i].to;
		if(dfs(v))
		return true;
	}
	return false;
}

void add_edge(int u,int v)
{
//	cout<<u<<" "<<v<<endl;
	edge[etot].to=v;
	edge[etot].next=head[u];
	head[u]=etot++;
}

int main()
{
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A-small-attempt1.out","w",stdout);
	int i,j;
	int c;
	scanf("%d",&c);
	int tc=1;
	while(c--)
	{
		Init();
		bool flag=false;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
		{
			int t,v;
			scanf("%d",&t);
			while(t--)
			{
				scanf("%d",&v);
				add_edge(i,v);
			}
		}
		for(i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i))
			{
				//cout<<" *"<<i<<endl;
				flag=true;
				break;
			}
		}
		printf("Case #%d: ",tc++);
		if(flag)
		cout<<"Yes"<<endl;
		else
		cout<<"No"<<endl;
	}
	return 0;
}