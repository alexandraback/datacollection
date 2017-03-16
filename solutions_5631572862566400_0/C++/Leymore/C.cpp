#include <bits/stdc++.h>

using namespace std;

const int maxn = 1010;

int T, n, f[maxn], d[maxn];
int l[maxn];
bool vis[maxn];
vector <int> G[maxn];
queue <int> Q;


int dfs(int u, bool ban) {
	int c = 1;
	vis[u] = 1;
	for(unsigned i = 0; i < G[u].size(); i ++) {
		int v = G[u][i];
		if(vis[v]) continue;
		if(ban && d[v] != 2) continue;
		c += dfs(v, ban);
	}
	return c;
}

int main() {
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("C.out", "w", stdout);
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++) {
		scanf("%d", &n);
		memset(d, 0, sizeof(d));
		for(int i = 1; i <= n; i ++) G[i].clear();
		for(int i = 1; i <= n; i ++) {
			scanf("%d", &f[i]);
			G[i].push_back(f[i]);
			G[f[i]].push_back(i);
			d[i] ++; d[f[i]] ++;
		}
	
		for(int i = 1; i <= n; i ++) if(d[i] == 1) Q.push(i);
		while(!Q.empty()) {
			int x = Q.front(); Q.pop();
			for(unsigned i = 0; i < G[x].size(); i ++) {
				int u = G[x][i];
				if((-- d[u]) == 1) Q.push(u);
			}
		}
		
		memset(l, 0, sizeof(l));
		for(int i = 1; i <= n; i ++) {
			memset(vis, 0, sizeof(vis));
			int x = i, c = 1;
			while(x != f[f[x]] && !vis[x]) {
				vis[x] = 1;
				c ++;
				x = f[x];
			}
			if(x == f[f[x]]) l[x] = max(l[x], c);
		}
		
		int sum = 0, res = 0;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= n; i ++) if(!vis[i]) {
			if(d[i] != 2) continue;
			if(i == f[f[i]]) {
				sum += l[i] + l[f[i]];
				vis[i] = vis[f[i]] = 1;
			} else res = max(res, dfs(i, 1));
		}
		res = max(res, sum);
		printf("Case #%d: %d\n", cas , res);
	}
	
	return 0;
}
