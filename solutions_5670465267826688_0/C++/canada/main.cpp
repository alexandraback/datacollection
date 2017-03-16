#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

char abs(char c) { return c < 0 ? -c : c; }

char times(char a, char b) {
	char sgn = ((a < 0) ^ (b < 0)) ? -1 : 1;
	a = abs(a), b = abs(b);
	if (a == '1') return sgn * b;
	if (b == '1') return sgn * a;
	if (a == b) return sgn * -1 * '1';
	return ((((a - 'i') + 1) % 3 == b - 'i') ? 1 : -1) * sgn * ('i' ^ 'j' ^ 'k' ^ a ^ b);
}

char expt(char c, int n) {
	switch (c) {
	case '1': return '1';
	case -'1': return n % 2 ? -'1' : '1';
	case 'i': case 'j': case 'k': return (n % 4 >= 2 ? -1 : 1) * (n % 2 ? c : '1');
	case -'i': case -'j': case -'k': return ((n + 1) % 4 >= 2 ? -1 : 1) * (n % 2 ? -c : '1');
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int t; cin >> t;
	for (int cas = 1; cas <= t; ++cas) {
		bool k = false;
		int l, x; cin >> l >> x;
		string s; cin >> s;
		char cur = '1';
		for (char c : s) cur = times(cur, c);
		if (expt(cur, x) != -'1') goto out;
		int i;
		char c = '1';
		if (x <= 10) {
			string tmp = "";
			for (i = 0; i < x; ++i) tmp += s;
			for (i = 0; i < tmp.length(); ++i) {
				c = times(c, tmp[i]);
				if (c == 'i') break;
			}
			++i;
			if (i >= tmp.length()) goto out;
			c = '1';
			for (; i < tmp.length(); ++i) {
				c = times(c, tmp[i]);
				if (c == 'j') break;
			}
			k = i < tmp.length();
		} else {
			string tmp = s + s + s + s;
			for (i = 0; i < tmp.length(); ++i) {
				c = times(c, tmp[i]);
				if (c == 'i') break;
			}
			if (i >= tmp.length()) goto out;
			c = '1';
			for (i = tmp.length() - 1; i >= 0; --i) {
				c = times(tmp[i], c);
				if (c == 'k') break;
			}
			k = i >= 0;
		}
out:	cout << "Case #" << cas << ": " << (k ? "YES" : "NO") << endl;
	}
}
