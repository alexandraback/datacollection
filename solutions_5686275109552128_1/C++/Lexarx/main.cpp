#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include "math.h"

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define fori(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

using namespace std;

int d;
int p[10000];

int f() {
	int max = 0;
	forn(i, d) {
		if (p[i] > max) {
			max = p[i];
		}
	}
	int min = max;
	for (int i = 1; i < max; i++) {
		int t = i;
		forn(j, d) {
			t += p[j] <= i ? 0 : ceil(1.0 * p[j] / i) - 1;
		}
		if (t < min) {
			min = t; 
		}
	}
	return min;
}

int main() {
	int ntc;
	cin >> ntc;
	fori(tc, 1, ntc) {
		cin >> d;
		forn(i, d) {
			cin >> p[i];
		}
		cout << "Case #" << tc << ": ";
		cout << f();
		cout << endl;
	}
	return 0;
}
