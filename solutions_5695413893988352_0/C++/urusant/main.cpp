#include <bits/stdc++.h>
using namespace std;

string to_str(int x, int len) {
	string ans = "";
	for (int i = 0; i < len; ++i) {
		ans += x % 10 + '0';
		x /= 10;
	}
	reverse(ans.begin(), ans.end());
	return ans;
}

bool match(string s, string a) {
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] == '?' || a[i] == '?') {
			continue;
		}
		if (s[i] != a[i]) {
			return 0;
		}
	}
	return 1;
}

void solve() {
	string s, t;
	cin >> s >> t;
	int lim = 1;
	for (int i = 0; i < s.size(); ++i) {
		lim *= 10;
	}
	int ans_a = -1, ans_b = -1;
	for (int i = 0; i < lim; ++i) {
		for (int j = 0; j < lim; ++j) {
			string a = to_str(i, s.size());
			string b = to_str(j, s.size());
			if (!match(a, s) || !match(b, t)) {
				continue;
			}
			if (ans_a == -1) {
				ans_a = i, ans_b = j;
				continue;
			}
			if (abs(ans_a - ans_b) > abs(i - j) || abs(ans_a - ans_b) == abs(i - j) && ans_a > i) {
				ans_a = i, ans_b = j;
				continue;
			}
		}
	}
	cout << to_str(ans_a, s.size()) << ' ' << to_str(ans_b, s.size());
}

int main() {
	int t;
	cin >> t;
	for (int test = 1; test <= t; ++test) {
		cout << "Case #" << test << ": ";
		solve();
		cout << endl;
	}
	return 0;
}