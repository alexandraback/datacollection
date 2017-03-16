#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

typedef long double ld;
string keyboard, target, s;
int nmax;
ld r;

void search(int is) {
	if (is == s.size()) {
		int i, j, n = 0;

		for (i = 0; i + target.size() <= s.size(); i++) {
			for (j = 0; j < target.size(); j++) {
				if (target[j] != s[i + j]) break;
			}
			if (j == target.size()) n++;
		}

		nmax = max(nmax, n);
		r += 1. / pow(keyboard.size(), s.size()) * n;
	} else {
		for (char c: keyboard) {
			s[is] = c;
			search(is + 1);
		}
	}
}

int main() {
	int it, nt;

	cin >> nt;
	for (it = 1; it <= nt; it++) {
		int k, l, s;

		cin >> k >> l >> s;
		cin >> keyboard >> target;

		::s = string(s, 0);
		nmax = 0;
		r = 0;
		search(0);

		cout << "Case #" << it << ": " << setprecision(10) << fixed << nmax - r << endl;
	}
}
