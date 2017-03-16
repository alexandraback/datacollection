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

int R, N, M, K, a[10], arr[10];

bool ok() {
	set<int> tmp;
	FOR(mask, 0, 1<<N) {
		int tot = 1;
		FOR(i, 0, N) if (mask&(1<<i)) tot *= arr[i];
		tmp.insert(tot);
	}
	FOR(i, 0, K) if (!in(tmp, a[i])) return false;
	return true;
}

void gen(int pos, int len) {
	if (pos == len) {
		if (ok()) throw -1;
		return;
	}
	FOR(i, pos?arr[pos-1]:2, M+1) {
		arr[pos] = i;
		gen(pos+1, len);
	}
}

void solve() {
	FOR(i, 0, K) cin >> a[i];
	try { gen(0, N); } catch (...) { }
	FOR(i, 0, N) cout << arr[i]; cout << endl;
}

int main() {
	int tc;
	cin >> tc;
	FOR(l, 1, tc+1) {
		cin >> R >> N >> M >> K;
		cout << "Case #" << l << ":" << endl;
		while (R--) solve();
	}
	return 0;
}

