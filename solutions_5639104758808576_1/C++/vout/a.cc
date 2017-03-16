#include <iostream>
#include <string>

using namespace std;

bool gao(int addi, string &s) {
	int g = addi + s[0];
	for (int i = 1; i < s.length(); ++i) {
		if (g >= i) {
			g += s[i];
		} else {
			return false;
		}
	}
	return true;
}

int main() {
	int T;
	cin >> T;
	for (int re = 1; re <= T; ++re) {
		int n;
		string s;
		cin >> n >> s;

		for (int i = 0; i < s.length(); ++i) {
			s[i] -= '0';
		}

		int l = 0, h = s.length();
		int ans = (l + h) / 2;
		while (h > l) {
			ans = (l + h) / 2;
			if (gao(ans, s)) {
				h = ans;
			} else {
				l = ans + 1;
			}
		}

		cout << "Case #" << re << ": " << h << endl;
	}
	return 0;
}