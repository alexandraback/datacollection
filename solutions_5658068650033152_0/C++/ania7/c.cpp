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
#define ll lolng long
#define SZ(x) int((x).size())
#define DBG(v) cerr << #v << " = " << (v) << endl;
#define FOREACH(i,t) for (auto i = t.begin(); i != t.end(); ++i)
#define fi first
#define se second

const int maxn = 22;
const int inf = 1000100;

int n,m,k;
bool vis[maxn][maxn*maxn][maxn][2];
int dp[maxn][maxn*maxn][maxn][2];

int rec(int pos, int rem, int last, bool up) {
	if (rem <= 0) return 0;
	if (pos == m+1) return inf;
	if (vis[pos][rem][last][up]) return dp[pos][rem][last][up];
	vis[pos][rem][last][up] = true;
	//FOR(i,pos) printf("\t");
	//printf("dp (%d %d %d %d)\n", pos, rem, last, up);
	int res = inf;
	if (up) {
		for (int cur = last; cur <= n; cur++) {
			res = min(res, rec(pos+1, rem-cur, cur, true) + max(2, cur-last));
			res = min(res, rec(pos+1, rem-cur, cur, false) + max(2, cur-last));
		}
	} else {
		for (int cur = last; cur >= 1; cur--) {
			res = min(res, rec(pos+1, rem-cur, cur, false) + max(2, last-cur));
		}
	}
	//FOR(i,pos) printf("\t");
	//printf("dp (%d %d %d %d) = %d\n", pos, rem, last, up, res);
	return dp[pos][rem][last][up] = res;
}

void test() {
	scanf("%d%d%d", &n, &m, &k);
	FOR(i,maxn) FOR(j,maxn*maxn) FOR(kk,maxn) FOR(l,2) vis[i][j][kk][l] = 0;
	printf("%d\n", rec(0,k,0,true));
}

int main() {
	int tt;
	scanf("%d", &tt);
	for (int te = 1; te <= tt; te++) {
		printf("Case #%d: ", te);
		test();
	}
}
