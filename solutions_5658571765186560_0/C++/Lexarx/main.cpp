#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

int x, r, c;

string f() {
	if (r * c % x) {
		return "RICHARD";
	}
	if (r > c) {
		int t = r;
		r = c;
		c = t;
	}
	// r <= c
	if (x > c) {
		return "RICHARD";
	}
	int mx;
	if (r == 1) {
		mx = 3;
	} else if (r == 2) {
		mx = 4;
	} else if (r == 3) {
		mx = 6;
	} else {
		mx = 7;
	}
	return x >= mx ? "RICHARD" : "GABRIEL";
}

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		cin >> x >> r >> c;
		cout << "Case #" << tc << ": ";
		cout << f();
		cout << endl;
	}
	return 0;
}
