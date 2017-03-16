//============================================================================
// Author	   : LAM PHAN VIET - lamphanviet@gmail.com
// Problem Name :
// Time Limit   : .000s
// Description  :
//============================================================================
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define uint64 unsigned long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define sqr(x) ((x) * (x))

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI	3.1415926535897932385
#define EPS	1e-7
#define MOD	1000000007
#define INF	1000111222
#define MAX	100

int n, M;
string code[MAX], res;
vi adj[MAX], order, s;

void recursive(int mask) {
	if (order.size() == 0) return;
	if (mask == M) {
		string tmp = "";
		rep(i, s.size()) tmp += code[s[i]];
		//cout << tmp << endl;
		if (res == "x" || tmp < res) res = tmp;
		return;
	}
	
	int u = order.back();
	
	order.pop_back();
	recursive(mask);
	order.pb(u);
	
	rep(i, adj[u].size()) {
		int v = adj[u][i];
		if (mask & BIT(v - 1)) continue;
		order.pb(v); s.pb(v);
		recursive(mask | BIT(v - 1));
		order.pop_back(); s.pop_back();
	}
	
}

void solve() {
	M = BIT(n) - 1;
	res = "x";
	order.clear();
	fr(i, 1, n) {
		order.pb(i);
		s.pb(i);
		recursive(BIT(i - 1));
		order.pop_back();
		s.pop_back();
	}
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("testCSmall.inp", "r", stdin);
		freopen("testCSmall.out", "w", stdout);
	#endif
	int cases, caseNo = 0, m, u, v;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d %d", &n, &m);
		fr(i, 1, n) cin >> code[i];
		fr(i, 1, n) adj[i].clear();
		while (m--) {
			scanf("%d %d", &u, &v);
			adj[u].pb(v);
			adj[v].pb(u);
		}
		printf("Case #%d: ", ++caseNo);
		solve();
		cout << res << endl;
	}
	return 0;
}

