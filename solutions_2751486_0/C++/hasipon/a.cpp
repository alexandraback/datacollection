#include <iostream>
using namespace std;
int f(const string& s) {
	int x = 0;
	int r = 0;
	for (unsigned i = 0; i < s.length(); ++ i) {
		if (s[i] == 'a' || s[i] == 'i' || s[i] == 'u' || s[i] == 'e' || s[i] == 'o') {
			x = 0;
		} else {
			r = max(r, ++ x);
		}
	}
	return r;
}
int solve() {
	string s;
	int n;
	cin >> s >> n;
	int r = 0;
	for (unsigned i = 0; i < s.length(); ++ i) {
		for (unsigned j = i+1; j <= s.length(); ++ j) {
			if (f(s.substr(i, j-i)) >= n) ++ r;
		}
	}
	return r;
}
int main() {
	int T;
	cin >> T;
	for (int tt = 1; tt <= T; ++ tt) {
		cout << "Case #" << tt << ": " << solve() << endl;
	}
}
