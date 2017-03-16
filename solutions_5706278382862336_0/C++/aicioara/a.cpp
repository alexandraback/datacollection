#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>

using namespace std;

#define e '\n'
#define INF 1023456789
#define ll long long

//#define FILE "seif"

#ifdef FILE
ifstream f(string (string(FILE) + ".in").c_str());
ofstream g(string (string(FILE) + ".out").c_str());
#endif
#ifndef FILE
#define f cin
#define g cout
#endif

ll gcd(ll x, ll y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}

long long t, ii, x, y, z;
int rez;
long long i, j, k;
string s;

int main() {

	f >> t;
	for (ii=1; ii<=t; ii++) {

		f >> s;
		x = 0;
		y = 0;
		i = 0;
		while (s[i] != '/') {
			x = x * 10 + (s[i] - '0');
			i++;
		}
		i++;
		while (s[i] >='0' && s[i] <= '9') {
			y = y * 10 + (s[i] - '0');
			i++;
		}

		k = gcd(x, y);
		x /= k;
		y /= k;

		k = y;

		while (k  % 2 == 0) {
			k /= 2;
		}

		if (k != 1) {
			g << "Case #" << ii << ": " << "impossible" << e;
			continue;
		}


		rez = 0;
		while (x < y) {
			rez ++;
			x *= 2;
		}

		g << "Case #" << ii << ": " << rez << e;
	}


	return 0;

}
