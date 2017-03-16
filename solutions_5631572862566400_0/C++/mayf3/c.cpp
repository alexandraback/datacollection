#include <cstdio>

const int N = 2333;

int n;
int v[N];
int d[N];
int dep[N];
int col[N];

int sz[N];
int ma[N];

bool cir[N];

bool vis[N];
bool ok[N];

bool work(int u, int co, int lev){
	col[u] = co;
	dep[u] = lev;
	if (col[v[u]] == -1){
		work(v[u], co, lev + 1);
	}
	else if (col[v[u]] != co) return false;
	else{
		sz[co] = dep[u] - dep[v[u]] + 1;
		cir[u] = true;
		for(int i = v[u]; i != u; i = v[i]){
			cir[i] = true;
		}
		return true;
	}
}

int main(){
	int T;
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas++){
		scanf("%d", &n);
		printf("Case #%d: ", cas);
		for(int i = 1; i <= n; i++){
			col[i] = -1;
			cir[i] = false;
			ma[i] = 0;
			vis[i] = false;
		}
		for(int i = 1; i <= n; i++) scanf("%d", &v[i]);
		int m = 0;
		for(int i = 1; i <= n; i++){
			if (col[i] == -1){
				ok[m] = work(i, m, 0);
				m++;
			}
		}
		for(int i = 1; i <= n; i++){
			int now = i, l = 0;
			while(!cir[now]){
				l++;
				now = v[now];
			}
			if (l > ma[now]) ma[now] = l;
		}
		int ans = 0;
		for(int i = 0; i < m; i++){
			if (!ok[i]) continue;
			if (sz[i] > ans) ans = sz[i];
		}
		int tmp = 0;
		for(int i = 1; i <= n; i++){
			if (!cir[i]) continue;
			if (v[v[i]] != i) continue;
			if (v[i] < i) continue;
			tmp += 2;
			tmp += ma[i];
			tmp += ma[v[i]];
		}
		if (tmp > ans) ans = tmp;
		printf("%d\n", ans);
	}
}
