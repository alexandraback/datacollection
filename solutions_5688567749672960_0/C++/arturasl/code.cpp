#include      <algorithm>
#include      <cmath>
#include      <cstdarg>
#include      <cstdio>
#include      <cstdlib>
#include      <iomanip>
#include      <iostream>
#include      <iterator>
#include      <limits>
#include      <list>
#include      <map>
#include      <set>
#include      <queue>
#include      <vector>
#define endl '\n'
#define each(c, e) for (typeof(c.begin()) e = c.begin(); e != c.end(); ++e)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const ll oo = numeric_limits<ll>::max() - 10;

ll rev(ll n) {
	ll r = 0;
	while (n) {
		r = r * 10 + n % 10;
		n /= 10;
	}
	return r;
}

ll MEMO[2000000];
ll solve() {
	ll n;
	cin >> n;

	for (ll s = 0; s <= n; s += 1) MEMO[s] = +oo;
	MEMO[n] = 1;
	for (ll s = n - 1; s >= 1; s -= 1) {
		const ll r = rev(s);
		MEMO[s] = 1 + min(r > n || r <= s ? +oo : MEMO[r], MEMO[s + 1]);
	}

	return MEMO[1];
}

int main(int argc, char **argv) {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t += 1) {
		cout << "Case #" << t << ": " << solve() << endl;
	}
	return 0;
}
