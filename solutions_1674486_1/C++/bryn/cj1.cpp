#include <cstdio>
#include <vector>
using namespace std;

vector<int> nbrs[1010];
int visited[1010];
int count[1010];
int start[1010];

bool dfs(int now, int root)
{
	visited[now] = root;
	for(int i = 0; i < nbrs[now].size(); i++)
	{
		if(visited[nbrs[now][i]] != root)
		{
			if(dfs(nbrs[now][i], root)) return true;
		}
		else return true;
	}
	return false;
}

int main()
{
	int z;
	scanf("%d",&z);
	for(int cnr = 1; cnr <= z; cnr++)
	{
		int n;
		scanf("%d",&n);
		for(int i = 0; i < n; i++) count[i] = 0;
		for(int i = 0; i < n; i++)
		{
			visited[i] = -1;
			nbrs[i].clear();
			int m;
			scanf("%d",&m);
			while(m--)
			{
				int x;
				scanf("%d",&x);
				nbrs[i].push_back(--x);
				count[x]++;
			}
		}
		int j = 0;
		for(int i = 0; i < n; i++)
		{
			if(!count[i]) start[j++] = i;
		}
		bool brk = false;
		for(int i = 0; i < j; i++)
		{
			if(dfs(start[i], start[i]))
			{
				printf("Case #%d: Yes\n",cnr);
				brk = true;
				break;
			}
		}
		if(!brk)
		{
			printf("Case #%d: No\n",cnr);
		}
	}
	return 0;
}