#include <bits/stdc++.h>
using namespace std;

int modulo(string s, int base, int mod) {
	int result = 0;
	for (char c : s) {
		result = (result * base + (c - '0')) % mod;
	}
	return result;
}

string bin(int n, int len) {
	string result;
	for (int i = 0; i < len; i++) {
		result = string(1, n % 2 + '0') + result;
		n /= 2;
	}
	return result;
}

void solve() {
	int n, J;
	cin >> n >> J;

	vector<string> ans;
	for (int i = 100; ans.size() < J; i++) {
		if (~i & 1) continue;
		string s = "1" + bin(i, n - 1);

		bool ok = true;
		for (int j = 2; j <= 10; j++) {
			if (modulo(s, j, j + 1) != 0) {
				ok = false;
			}
		}
		if (ok) {
			ans.push_back(s);
		}
	}

	for (int i = 0; i < J; i++) {
		cout << ans[i];
		for (int j = 2; j <= 10; j++) {
			cout << " " << j + 1;
		}
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	for (int ii = 1; ii <= T; ii++) {
		printf("Case #%d:\n", ii);
		solve();
	}
}