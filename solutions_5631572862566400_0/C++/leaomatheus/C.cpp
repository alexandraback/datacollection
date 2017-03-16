#include <bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii, ii>
#define vvi vector<vi>
#define MAXN 105
#define MAXE 10005
#define FOR(x,n) for(int x = 0; x < n; x++)
#define FOR1e(x,n) for(int x = 1; x <= n; x++)
#define MOD 1000000007

int filho[1005];
int par[1005];
int nivel[1005];

int dfs(int node, int lvl) {
	nivel[node] = lvl;
	if(nivel[filho[node]] == 0) return dfs(filho[node], lvl+1);
	
	if(nivel[node] == nivel[filho[node]] + 1) {
		par[node] = max(par[node], lvl-1);
	}
	return nivel[node] - nivel[filho[node]] + 1;
}
int main() {
	int n, t, ciclo, n1, tmp;
	scanf("%d", &t);
	FOR1e(caso, t) {
		scanf("%d", &n);
		FOR(x, n) {
			scanf("%d", &filho[x]);
			filho[x]--;
		}
		ciclo = 0;
		memset(par, 0, sizeof(par));
		FOR(x, n) {
			memset(nivel, 0, sizeof(nivel));
			tmp = dfs(x, 1);
			ciclo = max(ciclo, tmp);
		}

		tmp = 0;
		FOR(x, n) {
			if(par[x] != 0) {
				tmp += par[x];
			}
		}
		printf("Case #%d: %d\n", caso, max(ciclo, tmp));

	}
	return 0;
}