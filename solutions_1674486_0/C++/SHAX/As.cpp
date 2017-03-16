#include <cstdio>
#include <cstring>
using namespace std;

bool map[100][100], vis[100]; //map[i][j]: i inherented from j
int T, n, m, temp;
bool flag;

bool dfs(int bg){
	vis[bg] = true;
	for (int i = 0; i < n; ++i)
		if (map[bg][i]){
			if (vis[i]) return true;
			vis[i] = true;
			if (dfs(i)) return true;
		}
	return false;
}

int main(){
	freopen("As.in", "r", stdin);
	freopen("As.out", "w", stdout);
	scanf("%d", &T);
	for(int cs = 1; cs <= T; ++cs){
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &m);
			for(int j = 0; j < m; ++j){
				scanf("%d", &temp);
				map[i][temp - 1] = true;
			}
		}
		flag = false;
		for(int i = 0; i < n; ++i){
			memset(vis, false, sizeof(vis));
			flag = dfs(i);
			if(flag) break;
		}
		printf("Case #%d: %s\n", cs, (flag ? "Yes" : "No"));
		memset(map, false, sizeof(map));
	}
	return 0;
}

