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


ll solve() {
	ll r, t;
	cin >> r >> t;
	ll lb = 0, ub = t+1;
	while(ub-lb > 1) {
		ll m = (lb+ub)/2;
		double d = (2.0*r+1.0)*m+2.0*m*(m-1.0);
		ll res = (2*r+1)*m + 2*m*(m-1);
		(d <= t + 1e10 && res <= t ? lb : ub) = m;
	}
	return lb;
}

int main() {
	int T; cin >> T;
	for(int t=1; t<=T; t++)
		cout << "Case #" << t << ": " << solve() << endl;
}

