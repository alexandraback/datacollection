#include <bits/stdc++.h>

using namespace std;
#define DEBUG_ON 1

#define INF 0x3f3f3f3f
#define NSYNC ios::sync_with_stdio(false)
#define FOR(i,a,b) for(int i=a; i<(b); ++i)
#define FOR0(i,b) for(int i=0; i<(b); ++i)
#define TRAV(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define RTRAV(it,c) for(__typeof((c).rbegin()) it=(c).rbegin(); it!=(c).rend(); ++it)
#define DBG(x) if(DEBUG_ON) cout << #x << " == " << x << endl
#define DBGP(x) if(DEBUG_ON) cout << "(" << (x).first << ", " << (x).second << ")" << endl
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define CLR(v) memset(v, 0, sizeof(v))
#define SET(v) memset(v, -1, sizeof(v))

typedef long long ll;
typedef int int_type;
typedef pair<int_type, int_type> pii;
typedef vector<int_type> vi;
typedef vector<vi> vii;

int n,val;
bool v[40];
bool dp[40][40];
int inscoins;

bool solvedp() {
	CLR(dp);
	dp[0][0] = true;
	vi coins;
	FOR(i, 1, val+1) if(v[i]) coins.pb(i);
	FOR(i,1,coins.size()+1) FOR0(j,val+1) {
		dp[i][j] = dp[i-1][j];
		if(!dp[i][j] && j>=coins[i-1]) dp[i][j] = dp[i-1][j-coins[i-1]];
	}
	// TRAV(it, coins) cout << *it << " ";
	// FOR(i,0,val+1) cout << " dp[" << i << "] = " << dp[coins.size()][i];
	// cout << "\n";
	FOR(i,1,val+1) if(!dp[coins.size()][i]) return false;
	return true;
}


bool aux(vi nc) {
	if(nc.size() == inscoins) {
		TRAV(it,nc) v[*it] = true;
		if(solvedp()) return true;
		TRAV(it,nc) v[*it] = false;
		return false;
	}
	int beg = (nc.size() ? nc.back()+1 : 1);
	FOR(i, beg, val+1) if(!v[i]) {
		vi auxnc(nc);
		auxnc.pb(i);
		if(aux(auxnc)) return true;
	}
	return false;
}

int solve() {
	for(inscoins = 0; inscoins<=val; ++inscoins) {
		vi nc;
		if(aux(nc)) return inscoins;
	}
	return -1;
}

int main() {
	NSYNC;
	int tests;
	cin >> tests;
	FOR(t, 1, tests+1) {
		int c;
		cin >> c;
		CLR(v);
		cin >> n >> val;
		FOR0(i,n) {
			int x;
			cin >> x;
			if(x<=val) v[x] = true;
		}
		cout << "Case #" << t << ": " << solve() << "\n";
	}
	return 0;
} 