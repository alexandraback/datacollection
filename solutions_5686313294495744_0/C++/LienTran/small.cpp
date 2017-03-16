#include <bits/stdc++.h>

using namespace std;

string s[1000], f[1000];

void solve() {
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 0; i < n; ++i) cin >> s[i] >> f[i];
	for(int mask = 0; mask < (1 << n); ++mask) {
		set<string> ss, ff;
		for(int i = 0; i < n; ++i)
		if ((mask >> i) & 1) {
			ss.insert(s[i]);
			ff.insert(f[i]);
		}
		int cur = 0;
		for(int i = 0; i < n; ++i)
		if (!((mask >>i) & 1)) {
			if (ss.find(s[i]) != ss.end() && ff.find(f[i]) != ff.end()) ++cur;
		}
		if (ans < cur) ans = cur;
	}
	cout << ans << endl;
}

int main() {
	int ntest;
	cin >> ntest;
	for(int tc = 1; tc <= ntest; ++tc) {
		cout << "Case #" << tc << ": ";
		solve();
	}
	return 0;
}