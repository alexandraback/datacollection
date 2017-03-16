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

//const int maxn = 3333;

//int n, n0, n1;
char s[33], t[33];
//pii e[maxn];
//vi g[maxn];
//bool vis[maxn];

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


const int N = 2026;
int nn, cap[N][N];   // INPUT
int flow[N][N];     // OUTPUT
int edmonds (int s, int t) {
    int b, e, q[nn], p[nn], d, res = 0;
    FOR(i,nn) FOR(j,nn) flow[i][j]=0;
    while(1) {
        FOR(i,nn) p[i] = -1;
        for(q[b=e=0] = s; b <= e; ++b)
            FOR(v,nn) 
                if (flow[q[b]][v] < cap[q[b]][v] && p[v]<0)
                    p[q[++e]=v] = q[b];
        if (p[t] < 0) break;
        d = cap[p[t]][t] - flow[p[t]][t];
        for(int i=t; i!=s; i=p[i]) d = min(d, cap[p[i]][i] - flow[p[i]][i]);
        for(int i=t; i!=s; i=p[i]) {
            flow[p[i]][i] += d;
            flow[i][p[i]] -= d;
        }
        res += d;
    }
    return res;
}

void test() {
	int n;
	scanf("%d", &n);
	nn = 2*n+2;
	map<string,int> M[2];
	int N0 = 0, N1 = 0;
	FOR(i,2*n+2) {
		//g[i].clear();
		//vis[i] = false;
	}
	FOR(i,nn) FOR(j,nn) cap[i][j] = 0;
	FOR(i,n) {
		scanf("%s%s", s, t);
		if (M[0].find(s) == M[0].end()) {
			//g[2*n].push_back(N0);
			//g[N0].push_back(2*n);
			M[0][s] = N0++;
		} else {
			cap[2*n][M[0][s]]++;
			cap[M[0][s]][2*n]++;
		}
		if (M[1].find(t) == M[1].end()) {
			//g[2*n+1].push_back(N1+n);
			//g[N1+n].push_back(2*n+1);
			M[1][t] = N1++;
		} else {
			cap[2*n+1][M[1][t]+n]++;
			cap[M[1][t]+n][2*n+1]++;
		}
		cap[M[0][s]][M[1][t]+n] = 1;
		cap[M[1][t]+n][M[0][s]] = 1;
		//g[M[0][s]].push_back(M[1][t]+n);
		//g[M[1][t]+n].push_back(M[0][s]);
		//e[i] = {M[0][s], M[1][t]+n};
	}
	/*
	FOR(i,nn) {
		printf("%d : ", i);
		FOR(j,nn) printf("%d ", cap[i][j]);
		printf("\n");
	}*/
	int fl = edmonds(2*n, 2*n+1);
	/*
	int res = n;
	FOR(i,N0) {
		if (!vis[i]) {
			n0=n1=0;
			dfs(i);
			res -= max(n0, n1);
		}
	}*/
	/*
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
	}*/
	printf("%d\n", fl);
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
