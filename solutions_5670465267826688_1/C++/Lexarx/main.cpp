#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

int l;
ll x;
char a[10000];
int ii, ki;

char mul(char a, char b) {
	char ma = abs(a);
	char mb = abs(b);
	char sa = (a > 0 ? 1 : -1);
	char sb = (b > 0 ? 1 : -1);
	char r = 0;
	if (ma == '1') {
		r = mb;
	} else if (mb == '1') {
		r = ma;
	} else if (ma == mb) {
		r = -'1';
	} else {
		if (ma == 'i') {
			r = mb == 'j' ? 'k' : -'j';
		} else if (ma == 'j') {
			r = mb == 'i' ? -'k' : 'i';
		} else if (ma == 'k') {
			r = mb == 'i' ? 'j' : -'i';
		}
	}
	return r * sa * sb;
}

bool fi() {
	char s = '1';
	forn(t, 4) {
		for (ii = 0; ii < l; ii++) {
			s = mul(s, a[ii]);
			if (s == 'i') {
				return true;
			}
		}
		if (x == 0) {
			return false;
		}
		x--;
	}
	return false;
}

bool fk() {
	char s = '1';
	forn(t, 4) {
		int m = x == 1 ? ii + 2 : 0;
		for (ki = l - 1; ki >= m; ki--) {
			s = mul(a[ki], s);
			if (s == 'k') {
				return true;
			}
		}
		if (x == 1) {
			return false;
		}
		x--;
	}
	return false;
}

bool fj() {
	char s = '1';
	if (x == 1) {
		for (int i = ii + 1; i < ki; i++) {
			s = mul(s, a[i]);
		}
	} else {
		for (int i = ii + 1; i < l; i++) {
			s = mul(s, a[i]);
		}
		
		if (x > 2) {
			char t = '1';
			for (int i = 0; i < l; i++) {
				t = mul(t, a[i]);
			}
			if (t == -'1') {
				ll r = (x - 2) % 2;
				if (r == 0) {
					t = '1';
				}
			} else if (t != '1') {
				ll r = (x - 2) % 4;
				if (r == 0) {
					t = '1';
				} else if (r == 2) {
					t = -'1';
				} else if (r == 3) {
					t = -t;
				}
			}
			s = mul(s, t);
		}
		
		for (int i = 0; i < ki; i++) {
			s = mul(s, a[i]);
		}
	}
	return s == 'j';
}

string f() {
	if (!fi()) {
		return "NO";
	}
	if (!fk()) {
		return "NO";
	}
	if (!fj()) {
		return "NO";
	}
	return "YES";
}

char ai[10000], ak[10000];

string g() {
	int n = l * x;
	for (int i = l; i < n; i++) {
		a[i] = a[i - l];
	}
	char s = '1';
	for (int i = 0; i < n; i++) {
		s = mul(s, a[i]);
		ai[i] = s;
	}
	s = '1';
	for (int i = n - 1; i >= 0; i--) {
		s = mul(a[i], s);
		ak[i] = s;
	}
	for (int i = 0; i < n - 2; i++) {
		if (ai[i] != 'i') {
			continue;
		}
		for (int k = n - 1; k >= i + 2; k--) {
			if (ak[k] != 'k') {
				continue;
			}
			if (mul(ai[i], 'j') == ai[k - 1]) {
				return "YES";
			}
		}
	}
	return "NO";
}

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		cin >> l >> x;
		forn(i, l) {
			cin >> a[i];
		}
		cout << "Case #" << tc << ": ";
		cout << f();
		//cout << g();
		cout << endl;
	}
	return 0;
}
