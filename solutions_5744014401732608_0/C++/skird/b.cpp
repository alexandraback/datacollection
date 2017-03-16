#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define pb emplace_back

using namespace std;

typedef long long ll;

void solve() {
	ll n, m;
	cin >> n >> m;
	ll oldm = m;
	if (m > (1LL << (n - 2))) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	cout << "POSSIBLE\n";
	vector< vector<int> > a(n, vector<int>(n));
	for (int i = 1; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			a[i][j] = 1;
		}
	}
	if (m == (1LL << (n - 2))) {
			a[0][n - 1] = 1;
			m--;
	}
	for (int i = n - 2; i >= 1; --i, m /= 2) {
		if (m & 1) {
			a[0][i] = 1;
		}
	}
	for (int i = 0; i < n; ++i, cout << '\n') {
		for (int j = 0; j < n; ++j) {
			cout << a[i][j];
		}
	}
	vector<ll> dp(n);
	dp[n - 1] = 1;
	for (int i = n - 2; i >= 0; --i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i][j]) dp[i] += dp[j];
		}
	}
	cerr << dp[0] << endl;
	assert(dp[0] == oldm);
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i) {
		cout << "Case #" << i + 1 << ": ";
		solve();
	}
  return 0;
}
