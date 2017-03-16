#include <bits/stdc++.h>
using namespace std;

void solve() {
	string c, j;
	cin >> c >> j;
	int best, diff = 1000;
	for(int digits = 0; digits < 1000000; ++digits) {
		string tempc = c, tempj = j;
		int temp = digits;
		for(int i = j.size() - 1; i >= 0; --i) {
			if(j[i] == '?') {
				tempj[i] = temp % 10 + '0';
				temp /= 10;
			}
		}
		for(int i = c.size() - 1; i >= 0; --i) {
			if(c[i] == '?') {
				tempc[i] = temp % 10 + '0';
				temp /= 10;
			}
		}
		int cnum = 0, jnum = 0;
		for(char digit : tempc) {
			cnum = cnum * 10 + digit - '0';
		}
		for(char digit : tempj) {
			jnum = jnum * 10 + digit - '0';
		}
		if(abs(cnum - jnum) < diff) {
			best = digits;
			diff = abs(cnum - jnum);
		}
	}
	for(int i = j.size() - 1; i >= 0; --i) {
		if(j[i] == '?') {
			j[i] = best % 10 + '0';
			best /= 10;
		}
	}
	for(int i = c.size() - 1; i >= 0; --i) {
		if(c[i] == '?') {
			c[i] = best % 10 + '0';
			best /= 10;
		}
	}
	cout << ' ' << c << ' ' << j << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	int cases;
	cin >> cases;
	for(int i = 1; i <= cases; ++i) {
		cout << "Case #" << i << ':';
		solve();
	}
	return 0;
}
