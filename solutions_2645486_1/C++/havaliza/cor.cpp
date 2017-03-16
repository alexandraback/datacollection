#include <algorithm>
#include <iostream>
#include <valarray>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <numeric>
#include <complex>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>

using namespace std;

#define FOREACH(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
#define FOR(i, a, n) for (int i = (a); i < int(n); ++i)
#define error(x) cout << #x << " = " << (x) << endl;
#define all(n) (n).begin(), (n).end()
#define Size(n) ((int)(n).size())
#define mk make_pair
#define pb push_back
#define F first
#define S second
#define X real()
#define Y imag()

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef complex<double> point;

template <class P, class Q> void smin(P &a, Q b) { if (b < a) a = b; }
template <class P, class Q> void smax(P &a, Q b) { if (b > a) a = b; }
template <class P, class Q> bool in(const P &a, const Q &b) { return a.find(b) != a.end(); }

const int MAXN = 11*1000;

ll ans;
int tot, mx[MAXN];
vector<int> v;
set<pii> energy;

void add(int amt, int ind) {
	tot += amt;
	energy.insert(pii(ind, amt));
}

int get_max(int x, int y) {
	int res = 0;
	while (x < y-100) {
		smax(res, mx[y]);
		y -= 100;
	}
	while (y >= x) {
		smax(res, v[y]);
		y--;
	}
	return res;
}

void consume(int amt, int ind) {
	while (amt > 0) {
		if (energy.empty() || energy.begin()->F > ind) break;
		pii tmp = *energy.begin();
		energy.erase(energy.begin());
		int value = get_max(tmp.F, ind);
		int use = min(tmp.S, amt);
		amt -= use; tmp.S -= use; tot -= use;
		if (tmp.S > 0) energy.insert(tmp);
		ans += 1LL*use*value;
	}
}

int main() {
	int tc;
	cin >> tc;
	FOR(l, 1, tc+1) {
		v.clear();
		energy.clear();
		ans = 0; tot = 0;
		memset(mx, 0, sizeof mx);

		int E, R, N;
		cin >> E >> R >> N;
		R = min(E, R);
		v.resize(N);
		FOR(i, 0, N) cin >> v[i];
		FOR(i, 0, N) FOR(j, 0, 100) smax(mx[i+j], v[i]);
		add(E, 0);
		FOR(i, 0, N) {
			add(R, i+1);
			if (tot > E) consume(tot-E, i);
		}
		consume(tot, N-1);
		cout << "Case #" << l << ": " << ans << endl;
	}
	return 0;
}

