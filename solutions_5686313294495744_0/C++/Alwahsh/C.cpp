#include <bits/stdc++.h>

using namespace std;

#define ll long long

int t;


void solve();

int main() {
	ios::sync_with_stdio(0);

	bool file = true;
	if (file) {
		freopen("C-small-attempt1.in","r", stdin);
		freopen("output.out", "w", stdout);
	}

	cin >> t;
	for (int z = 1; z<= t; z++) {
		cout << "Case #" << z << ": ";
		solve();
		cout << endl;
	}
	return 0;
}

void solve() {
	int n;
	cin >> n;
	vector < pair <string, string> > s(n);
	for (int i = 0; i < n; i++) {
		cin >> s[i].first >> s[i].second;
	}
	int res = 0;
	for (int i = 0; i < (1<<n); i++) {
		int cur = __builtin_popcount(i);
		if (cur <= res)
			continue;
		bool valid = true;
		for (int j = 0; j < n; j++) {
			if ( i & (1<<j) ) {
				bool a = false;
				bool b = false;
				for (int k = 0; k < n; k++) {
					if ( i & (1<<k))
						continue;
					if (s[k].first == s[j].first)
						a = true;
					if (s[k].second == s[j].second)
						b = true;
				}
				if (!a || !b)
					valid = false;
			}
		}
		if (valid)
			res = cur;
	}
	cout << res;
}
