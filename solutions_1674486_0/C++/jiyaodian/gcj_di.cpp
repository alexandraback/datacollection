#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 1010;
int m[N];
vector<int> g[N];
bool flag[N];

bool dfs(int start)
{
	if(flag[start]) return true;
	flag[start] = true;
	for(int i = 0; i < g[start].size(); i ++){
		if(dfs(g[start][i])) return true;
	}
	return false;
}
bool check(int start){
	memset(flag, 0, sizeof(flag));
	for(int i = 0; i < g[start].size(); i ++){
		if(dfs(g[start][i])) return true;
	}	
	return false;
}
int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int t=1; t <= T; t++){
		bool ret = false;
		printf("Case #%d: ", t);
		int n;
		scanf("%d", &n);
		for(int i = 1; i <= n; i ++){
			scanf("%d", m+i);
			g[i].clear();
			for(int j = 0, f; j < m[i]; j ++){
				scanf("%d", &f);
				g[i].push_back(f);
			}
		}
		for(int i = 0; i < n; i ++){
			if(m[i] > 1 && check(i)){
				ret = true;
				break;
			}
		}
		if(ret) puts("Yes");
		else puts("No");
	}
	return 0;
}
