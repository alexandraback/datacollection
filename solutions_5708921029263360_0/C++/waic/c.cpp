#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;
int a[MAXN], b[MAXN], c[MAXN];
int t1[MAXN][MAXN], t2[MAXN][MAXN], t3[MAXN][MAXN];
bool vis[MAXN], res[MAXN];

int J, P, S, K;
int ans;
int tot;

void dfs(int v, int q) {
	if (q + tot - v <= ans || ans == tot) return;
	if (v == tot) {
		if (q > ans) {
			ans = q;
			memcpy(res, vis, sizeof(vis));
		}
		return;
	}
	int i = a[v], j = b[v], k = c[v];
	if(t1[i][j] < K && t2[i][k] < K && t3[j][k] < K){
		t1[i][j]++;
		t2[i][k]++;
		t3[j][k]++;
		vis[v] = true;
		dfs(v+1, q+1);
		if (ans == tot) return;
		t1[i][j]--;
		t2[i][k]--;
		t3[j][k]--;
		vis[v] = false;
	}
	dfs(v+1, q);
}
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		scanf("%d%d%d%d", &J, &P, &S, &K);
		tot = 0;
		for(int k = S; k >= 1; k--)
			for(int j = P; j >= 1; j--)
				for (int i = J; i >= 1; i--){
					a[tot] = i;
					b[tot] = j;
					c[tot] = k;
					tot++;
				}
		ans = 0;
		memset(vis, 0, sizeof(vis));
		memset(t1, 0, sizeof(t1));
		memset(t2, 0, sizeof(t2));
		memset(t3, 0, sizeof(t3));
		dfs(0, 0);
		printf("Case #%d: %d\n", tt, ans);
		for (int i = 0; i < tot; i++) 
			if (res[i]) {
				printf("%d %d %d\n", a[i], b[i], c[i]);
			}
	}
	return 0;
}
