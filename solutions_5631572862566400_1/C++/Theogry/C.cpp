#include <bits/stdc++.h>

#define FOR(i, s, t) for (int i = s; i < t; i++)
#define FOE(i, s, t) for (int i = s; i <= t; i++)

using namespace std;

int n, a[6001];
int vis[6001], res;
int dist[2001][2001], P[2001];

void DFS(int id, int len){
	if (vis[id]) return;
	vis[id] = len;
	
	if (vis[a[id]] > 0){
		res = max(res, vis[id] - vis[a[id]] + 1);
	} else if (vis[a[id]] == 0) DFS(a[id], len + 1);
	
}

void GO(int u, int tar, int len){
	if (dist[u][tar] != -1) return;
	dist[u][tar] = len;
	if (a[a[u]] == u) return;
	GO(a[u], tar, len + 1);
}

int nt[6001];

void solve(){
	scanf("%d", &n);
	FOE(i, 1, n) scanf("%d", &a[i]);
	
	res = 1;
	
	FOE(i, 1, n) vis[i] = 0;
	
	FOE(i, 1, n) FOE(j, 1, n) dist[i][j] = -1;
	
	FOE(i, 1, n) {
		GO(i, i, 0);
	}
	
	FOE(i, 1, n){
		sort(dist[i] + 1, dist[i] + n + 1);	
		nt[i] = dist[i][n];
	}
	
	FOE(i, 1, n) if (!vis[i]){
		DFS(i, 1);	
		FOE(j, 1, n) if (vis[j] > 0) vis[j] = -1;
	}
	
	int rem = 0;
	FOE(i, 1, n) FOE(j, i + 1, n) if (a[i] == j && a[j] == i){
		int ret = 0;
		rem += (2 + nt[i] + nt[j]);	
		
	}
	
	res = max(res, rem);
	
	printf("%d\n", res);
	
}

int main(){
	freopen("CL.in", "r", stdin);
	freopen("CL.out", "w", stdout);
	int tc; scanf("%d", &tc);
	FOE(i, 1, tc){
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
