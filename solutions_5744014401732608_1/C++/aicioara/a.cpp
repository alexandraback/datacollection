#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <cmath>
#include <bitset>
#include <list>
#include <queue>
#include <sstream>

using namespace std;

#define e '\n'
#define INF 1023456789
#define ll long long

//#define FILE "myFile"

#ifdef FILE
ifstream f(string (string(FILE) + ".in").c_str());
ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
#define f cin
#define g cout
#endif

ll mul_inv(ll a, ll b)
{
	ll b0 = b, t, q;
	ll x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}

ll t, n, rez, x, b, m;
int i, j, ii;
string s, s1, s2;

int v[55][55];

int main() {
	f >> t;

	for (int ii = 1; ii <= t; ii++) {
		f >> b >> m;

		ll maxMethods = 1l << (b - 2);

		if (m > maxMethods) {
			g << "Case #" << ii << ": IMPOSSIBLE" << e;
			continue;
		} else {
			g << "Case #" << ii << ": POSSIBLE" << e;
		}

		for (i = 1; i <= b; i++) {
			for (j = 1; j <= b; j++) {
				v[i][j] = 0;
			}
		}

		for (i = 2; i < b; i++) {
			for (j = i + 1; j <= b; j++) {
				v[i][j] = 1;
			}
		}

		m --;

		for (i = 1; i < b; i++) {
			if (m & (1l << (ll)(b - i - 1))) {
				v[1][i] = 1;
			}
		}

		v[1][b] = 1;

		for (i = 1; i <= b; i++) {
			for (j = 1; j <= b; j++) {
				g << v[i][j];
			}
			g << e;
		}

	}

}

