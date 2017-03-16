#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n;
	cin >> n;

	vector<string> us(n), vs(n);
	map<string, int> mp;
	for (int i = 0; i < n; i++) {
		cin >> us[i] >> vs[i];
		mp[us[i]] = 0;
		mp[vs[i]] = 0;
	}

	int rank = 0;
	for (auto &kv : mp) kv.second = rank++;

	vector<int> u(n), v(n);
	for (int i = 0; i < n; i++) {
		u[i] = mp[us[i]];
		v[i] = mp[vs[i]];
	}

	int ans = 0;
	for (int i = 0; i < 1 << n; i++) {
		set<int> first, second;
		for (int j = 0; j < n; j++) if (i & 1 << j) {
			first.insert(u[j]);
			second.insert(v[j]);
		}
		bool ok = true;
		for (int j = 0; j < n; j++) if (~i & 1 << j) {
			if (first.count(u[j]) == 0 || second.count(v[j]) == 0) ok = false;
		}
		if (ok) ans = max(ans, n - __builtin_popcount(i));
	}
	cout << ans << endl;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		solve();
	}
}