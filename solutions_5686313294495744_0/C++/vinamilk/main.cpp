#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

const int nm = 30;

int n;
string a[nm], b[nm];

bool kt(int mask) {
	set<string> x, y;
	for (int i = 1; i <= n; ++i) {
		if (((mask >> (i - 1)) & 1) == 0) {
			x.insert(a[i]);
			y.insert(b[i]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		if ((mask >> (i - 1)) & 1) {
			if (x.find(a[i]) == x.end() || y.find(b[i]) == y.end())
				return 0;
		}
	}
	return 1;
}

void solve(int test) {
	cout << "Case #" << test << ": ";
	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i] >> b[i];
	int res = 0;
	for (int mask = 1; mask < (1 << n); ++mask)
		if (__builtin_popcount(mask) > res && kt(mask))
			res = __builtin_popcount(mask);
	cout << res << "\n";
}

int main() {
#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
	freopen("C-small-attempt0 (2).in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i)
		solve(i);
}
