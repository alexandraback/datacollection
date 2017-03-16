#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;

int N;
int a[MAXN];
int vis[MAXN], g[MAXN], f[MAXN];
int cnt, ans, cur, anstmp;
vector<int> V[MAXN];
bool flag[MAXN];


void bfs(int x) {
	flag[x] = true;
	f[x] = 1;
	for (int i = 0; i < (int)V[x].size(); i++) {
		int y = V[x][i];
		if (!flag[y]) {
			bfs(y);
			f[x] = max(f[x], f[y] + 1);
		}
	}
}

void dfs(int x, int y) {
	flag[x] = flag[y] = true;
	bfs(x);
	bfs(y);
	ans = max(ans, anstmp + f[x] + f[y]);
	anstmp += max(f[x], f[y])+1;
	ans = max(ans, f[x] + f[y]);
}

int check(int v, int p) {
	vis[v] = cnt;
	g[v] = p;
	if (vis[a[v]] == vis[v]) {
		int Cir = g[v] - g[a[v]] + 1;
		ans = max(ans, Cir);
		if (Cir == 2){
			dfs(v, a[v]);
		}
		return 0;
	}
	else if (!vis[a[v]]) {
		check(a[v], p + 1);
	}
	return 0;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) scanf("%d", a + i);
		for (int i = 1; i <= N; i++) V[i].clear();
		for (int i = 1; i <= N; i++) V[a[i]].push_back(i);
		memset(vis, 0, sizeof(vis));
		memset(flag, 0, sizeof(flag));
		cnt = 1;
		ans = 0;
		anstmp = 0;
		for (int i = 1; i <= N; i++) 
			if (!vis[i] && !flag[i]) {
				cur = i;
				check(i, 0);
				cnt++;
			}
		/*
		for (int i = 1; i <= N; i++) {
			cout << g[i] << endl;
		}
		*/
		ans = max(ans, anstmp);
		printf("Case #%d: %d\n", tt, ans);
	}
	return 0;
}

