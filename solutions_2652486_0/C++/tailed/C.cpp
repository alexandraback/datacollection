#include <iostream>
#include <cstdio>
#include <cassert>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <cstdlib>
#include <numeric>
#include <bitset>
using namespace std;

#define REP(i, m, n) for(int i=(m); i<int(n); ++i)
#define rep(i, n) for(int i=0; i<int(n); ++i)
#define each(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); ++it)
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define pb push_back                                                                          
#define mp make_pair
#define def(a, x) __typeof(x) a = x
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> PI;
const int dx[] = {1, 0, -1, 0, 1, 1, -1, -1}, dy[] = {0, 1, 0, -1, 1, -1, 1, -1};


set<int> A[1000];
int R, N, M, K;
#include <debug.h>
int id_of(vector<int> v) {
	sort(all(v));
	int res = 0;
	rep(i, sz(v))
		res = res * 10 + v[i];
	return res;
}
void rec(vector<int> cur) {
	if (sz(cur) < N) {
		for(int i=2; i<=M; i++) {
			vector<int> temp = cur;
			temp.pb(i);
			rec(temp);
		}
		return;
	}
	int id = id_of(cur);
	rep(k, 1<<N) {
		int p = 1;
		rep(i, N) if (k>>i&1) p *= cur[i];
		A[p].insert(id);
	}
}
void solve() {
	cin >> R >> N >> M >> K;
	vector<int> dummy;
	rec(dummy);
	rep(r, R) {
		set<int> can;
		rep(i, 1000) can.insert(i);
		rep(k, K) {
			int p;
			cin >> p;
			set<int> next;
			each(it, A[p]) {
				if (can.count(*it)) next.insert(*it);
			}
			swap(next, can);
//			cout << "read " << p << endl;
//			each(it, next) cout << *it << " "; cout << endl;
		}
		cout << *can.begin() << endl;
	}
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++) {
		cout << "Case #" << t << ":" << endl;
		solve();
	}
}

