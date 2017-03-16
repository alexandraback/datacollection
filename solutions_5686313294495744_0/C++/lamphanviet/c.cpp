// lamphanviet@gmail.com
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define frr(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define repr(i,n) for (int i = (n) - 1; i >= 0; i--)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define EPS 1e-7
#define MAX 100111
#define MOD 1000000007

int n, a[MAX], b[MAX];
string sa, sb;
int cntA, cntB;
map<string, int> ia, ib;

int getIndex(string &s, map<string, int> &idx, int &cnt) {
	if (idx.count(s)) return idx[s];
	return idx[s] = cnt++;
}

int solve() {
	int res = INF;
	rep(stt, 1<<n) {
		int cnt = 0;
		set<int> va, vb;
		rep(i, n) if ((1 << i) & stt) {
			cnt++;
			va.insert(a[i]);
			vb.insert(b[i]);
		}
		if (va.size() == cntA && vb.size() == cntB) {
			if (cnt < res) res = cnt;
		}
	}
	return n - res;
}

int main() {
	//ios::sync_with_stdio(false);
	#ifndef ONLINE_JUDGE
		freopen("test.inp", "r", stdin);
		freopen("csmall.out", "w", stdout);
	#endif
	int cases, caseNo = 0;
	for (scanf("%d", &cases); cases--; ) {
		scanf("%d", &n);
		cntA = cntB = 0;
		ia.clear(); ib.clear();
		rep(i, n) {
			cin >> sa >> sb;
			a[i] = getIndex(sa, ia, cntA);
			b[i] = getIndex(sb, ib, cntB);
			//printf("%d %d\n", a[i], b[i]);
		}
		printf("Case #%d: %d\n", ++caseNo, solve());
	}
	return 0;
}

