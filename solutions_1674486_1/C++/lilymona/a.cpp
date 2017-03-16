#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

int n;
vector<int> edge[1010];

void init()
{
	int k,t;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&k);
		edge[i].clear();
		while(k--)
		{
			scanf("%d",&t);
			edge[i].push_back(t);
		}
	}
}

bool visited[1010],ans;
void DFS(int k)
{
	visited[k]=true;
	for(int i=0;i<edge[k].size();i++)
	{
		if(visited[edge[k][i]]) ans=true;
		else DFS(edge[k][i]);
	}
}

bool work()
{
	for(int i=1;i<=n;i++)
	{
		ans=false;
		memset(visited,0,sizeof(visited));
		DFS(i);
		if(ans) return true;
	}
	return false;
}

int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		init();
		printf("Case #%d: ",i);
		if(work()) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
