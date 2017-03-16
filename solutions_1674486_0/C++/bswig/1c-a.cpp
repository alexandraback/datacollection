#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

int ntest;
int N, M;
int indeg[1005];
bool visit[1005], flag;
vector<int> next[1005];

void dfs(int u)
{
	for(int j = 0;j < (int)next[u].size();++j)
	{
		int v = next[u][j];
		if(!visit[v])
		{
			visit[v] = 1;
			dfs(v);
		}
		else
			flag = 1;
	}
}

int main()
{
	scanf("%d", &ntest);
	for(int test = 1;test <= ntest;++test)
	{
		scanf("%d", &N);
		memset(indeg, 0, sizeof(indeg));
		for(int i = 0;i < N;++i)
			next[i].clear();
		for(int i = 0;i < N;++i)
		{
			scanf("%d", &M);
			for(int j = 0;j < M;++j)
			{
				int temp;
				scanf("%d", &temp);
				--temp;
				next[i].push_back(temp);
				++indeg[temp];
			}
		}
		flag = 0;
		for(int i = 0;i < N;++i)
			if(indeg[i] == 0)
			{
				memset(visit, 0, sizeof(visit));
				visit[i] = 1;
				dfs(i);
				if(flag)
					break;
			}
		printf("Case #%d: %s\n", test, flag ? "Yes" : "No");
	}
}
