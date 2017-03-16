#include <cstdio>
#include <cstring>

int conn[100][100];
bool vis[100];

int cases = 0;
int T;
int n;

bool dfs(int a)
{
	if(vis[a] == true)
		return true;

	vis[a] = true;
	for(int i=0; i<n; i++){
		if(conn[a][i] == 1 && dfs(i))
			return true;
	}

	return false;
}

int main()
{
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("out.txt", "w", stdout);

	scanf("%d", &T);
	while(cases < T){
		cases ++;

		scanf("%d", &n);
		memset(conn, 0, sizeof(conn));
		for(int i=0; i<n; i++){
			int m, t;
			scanf("%d", &m);
			for(int j=0; j<m; j++){
				scanf("%d", &t);
				conn[i][t-1] = 1;
			}
		}

		bool flag = false;
		for(int i=0; i<n; i++){
			memset(vis, 0, sizeof(vis));
			if(dfs(i)){
				flag = true;
				break;
			}
		}

		if(flag)
			printf("Case #%d: Yes\n", cases);
		else
			printf("Case #%d: No\n", cases);
	}
}