#include <bits/stdc++.h>
using namespace std;
#define REP(i,a,b) for (int i = (a); i <= (b); ++i)
#define REPD(i,a,b) for (int i = (a); i >= (b); --i)
#define FORI(i,n) REP(i,1,n)
#define FOR(i,n) REP(i,0,int(n)-1)
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define ll long long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)
#define fi first
#define se second

const int maxn = 3333;

int n, n0, n1;
char s[33], t[33];
pii e[maxn];
//vi g[maxn];
bool vis[maxn];

/*
void dfs(int u) {
	if (u<n) n0++;
	else n1++;
	vis[u] = true;
	FOR(i,SZ(g[u])) {
		int v = g[u][i];
		if (!vis[v]) dfs(v);
	}
}*/

void test() {
	scanf("%d", &n);
	map<string,int> M[2];
	int N0 = 0, N1 = 0;
	FOR(i,2*n) {
		//g[i].clear();
		vis[i] = false;
	}
	FOR(i,n) {
		scanf("%s%s", s, t);
		if (M[0].find(s) == M[0].end()) M[0][s] = N0++;
		if (M[1].find(t) == M[1].end()) M[1][t] = N1++;
		//g[M[0][s]].push_back(M[1][t]+n);
		//g[M[1][t]+n].push_back(M[0][s]);
		e[i] = {M[0][s], M[1][t]};
	}
	/*
	int res = n;
	FOR(i,N0) {
		if (!vis[i]) {
			n0=n1=0;
			dfs(i);
			res -= max(n0, n1);
		}
	}*/
	int res = 0;
	FOR(i,(1<<n)) {
		FOR(j,2*n) vis[j] = false;
		FOR(j,n) if (i & (1<<j)) {
			vis[e[j].fi] = true;
			vis[e[j].se+n] = true;
		}
		bool ok=true;
		FOR(j,N0) if (!vis[j]) ok=false;
		FOR(j,N1) if (!vis[j+n]) ok=false;
		if (ok) {
			res = max(res, n-__builtin_popcount(i));
		}
	}
	printf("%d\n", res);
}

int main() {
	int ttn;
	scanf("%d", &ttn);
	for (int i = 1; i <= ttn; i++) {
		printf("Case #%d: ", i);
		test();
	}
	return 0;
}
