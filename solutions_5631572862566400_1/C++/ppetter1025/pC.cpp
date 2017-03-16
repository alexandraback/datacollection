#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#ifdef _DEBUG_
	#define debug(...) printf(__VA_ARGS__)
#else
	#define debug(...) (void)0
#endif
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;

const int MAXN = 1000 + 10;

VI e[MAXN], re[MAXN], e2[MAXN];
VI vs, vscc[MAXN];
int scc[MAXN];
int in[MAXN];
bool used[MAXN];

void dfs(int u) {
	scc[u] = 1;
	for(int v : e[u])
		if(scc[v] < 0)	dfs(v);
	vs.PB(u);
}

void rdfs(int u, int num) {
	scc[u] = num;
	vscc[num].PB(u);
	for(int v : re[u])
		if(scc[v] < 0)	rdfs(v, num);
}

int go(int u) {
	int ret = 0;
	used[u] = true;
	for(int v : e[u])
		if(!used[v])	ret = max(ret, go(v));
	return ret+1;
}

int main() {
	int T;
	scanf("%d", &T);
	for(int kase=1; kase<=T; kase++) {
		int n;
		scanf("%d", &n);
		for(int i=1; i<=n; i++) {
			int x;
			scanf("%d", &x);
			e[x].PB(i);
			re[i].PB(x);
		}
		
		fill(scc, scc+n+1, -1);
		for(int i=1; i<=n; i++)
			if(scc[i] < 0)	dfs(i);
		fill(scc, scc+n+1, -1);
		int n2 = 0;
		for(int i=SZ(vs)-1; i>=0; i--)
			if(scc[vs[i]] < 0)	rdfs(vs[i], ++n2);
		//for(int i=1; i<=n; i++)	printf("%d%c", scc[i], " \n"[i==n]);

		for(int u=1; u<=n; u++) {
			for(int v : e[u]) {
				if(scc[u] != scc[v]) {
					e2[scc[u]].PB(scc[v]);
					in[scc[v]]++;
				}
			}
		}

		int ans1 = 0, ans2 = 0;
		fill(used, used+n+1, false);
		fill(in, in+n+1, 0);
		for(int u=1; u<=n2; u++) {
			if(!in[u]) {
				if(SZ(vscc[u]) == 2) {
					int mx1 = 0, mx2 = 0;
					for(int v : e[vscc[u][0]]) {
						if(scc[v] != u)	mx1 = max(mx1, go(v));
					}
					for(int v : e[vscc[u][1]]) {
						if(scc[v] != u)	mx2 = max(mx2, go(v));
					}

					ans1 += mx1+mx2+2;
					//printf("mx1=%d, mx2=%d\n", mx1, mx2);
				}
				else	ans2 = max(ans2, SZ(vscc[u]));
			}
		}

		printf("Case #%d: ", kase);
		printf("%d\n", max(ans1, ans2));

		for(int i=1; i<=n; i++) {
			e[i].clear();
			re[i].clear();
			e2[i].clear();
			vscc[i].clear();
		}
		vs.clear();
	}
    
    return 0;
}
