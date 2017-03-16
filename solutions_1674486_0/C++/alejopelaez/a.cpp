#include <cstdio>
#include <vector>

using namespace std;

vector< vector<int> > g;
bool visited[1005];

bool dfs(int node){
	if(visited[node])
		return true;
	visited[node] = true;
	bool ans = false;
	for(int i = 0; i < g[node].size(); ++i)
		if(dfs(g[node][i]))
			ans = true;
	return ans;
}

int main(int argc, char *argv[])
{
	int t;
	int kase = 0;
	scanf("%d", &t);
	while(t--){
		int n;
		scanf("%d", &n);
		g = vector< vector<int> >(n);
		for(int i = 0; i < n; ++i){
			int m;
			scanf("%d", &m);
			for(int j = 0; j < m; ++j){
				int c;
				scanf("%d", &c);
				g[i].push_back(c-1);
			}
		}

		bool ans = false;
		for(int i = 0; i < n; ++i){
			for(int j = 0; j < 1005; ++j)
				visited[j] = false;

			if(dfs(i))
				ans = true;
		}

		if(ans)
			printf("Case #%d: Yes\n", ++kase);
		else
			printf("Case #%d: No\n", ++kase);

	}
    return 0;
}


