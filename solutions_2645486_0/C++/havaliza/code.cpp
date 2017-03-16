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

int dp[20][20];

int main() {
	int tc;
	cin >> tc;
	FOR(l, 1, tc+1) {
		int E, R, N;
		cin >> E >> R >> N;
		R = min(E, R);
		vector<int> v(N);
		FOR(i, 0, N) cin >> v[i];
		memset(dp, -1, sizeof dp);
		dp[0][E] = 0;
		FOR(i, 0, N) FOR(amt, 0, 20) FOR(use, 0, amt+1)
			if (dp[i][amt] != -1)
				smax(dp[i+1][min(E, amt-use+R)], dp[i][amt]+use*v[i]);
		int tot = 0;
		FOR(i, 0, 20) smax(tot, dp[N][i]);
		cout << "Case #" << l << ": " << tot << endl;
	}
	return 0;
}

