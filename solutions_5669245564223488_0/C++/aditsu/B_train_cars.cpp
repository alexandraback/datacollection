#include <iostream>
#include <algorithm>

using namespace std;

bool isValid(string s) {
	bool f[26];
	for (int i = 0; i < 26; ++i) {
		f[i] = false;
	}
	for (int i = 0; i < s.length(); ++i) {
		char c = s[i];
		if (f[c - 'a'] && c != s[i - 1]) {
			return false;
		}
		f[c - 'a'] = true;
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	for (int i = 1; i <= t; ++i) {
		int n;
		cin >> n;
		string a[n];
		int p[n];
		for (int j = 0; j < n; ++j) {
			cin >> a[j];
			p[j] = j;
		}
		int r = 0;
		do {
			string s = "";
			for (int j = 0; j < n; ++j) {
				s += a[p[j]];
			}
			if (isValid(s)) {
				r++;
			}
		} while (next_permutation(p, p + n));
		cout << "Case #" << i << ": " << r << endl;
	}
}
