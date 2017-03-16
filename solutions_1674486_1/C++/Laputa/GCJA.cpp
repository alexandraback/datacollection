#include<cstdio>
#include<cstring>
using namespace std;

struct edge_node
{
	int to,next;
}edge[500000];
int first[1005],edge_cnt;
bool reach[1005],got;

int n;

inline void dfs(int startat)
{
	reach[startat]=true;
	for(int e=first[startat];e;e=edge[e].next)
	{
		int v=edge[e].to;
		if(reach[v])
		{
			got=true;
			return;
		}
		if(got)
			return;
		dfs(v);
	}
}

int main()
{
	int T,tmp,temp,TT;
	scanf("%d",&T);
	TT=T;
	while(T--)
	{
		scanf("%d",&n);
		memset(first,0,sizeof(first));
		edge_cnt=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&tmp);
			for(int j=0;j<tmp;j++)
			{
				scanf("%d",&temp);
				++edge_cnt;
				edge[edge_cnt].to=temp;
				edge[edge_cnt].next=first[i];
				first[i]=edge_cnt;
			}
		}
		got=false;
		for(int i=1;i<n;i++)
		{
			memset(reach,0,sizeof(reach));
			dfs(i);
			if(got)
			{
				break;
			}
		}
		printf("Case #%d: ",TT-T);
		if(got)
			printf("Yes\n");
		else
			printf("No\n");

	}
	return 0;
}