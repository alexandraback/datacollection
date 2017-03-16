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

long long x, n, t;
string s;
int i, j, ii;

int main() {
	f >> t;

	for (int ii = 1; ii <= t; ii++) {
		f >> s;

		string rez;
		rez += s[0];

		char best = s[0];
		for (int i = 1; i < s.length(); i++) {
			if (s[i] >= best) {
				rez = s[i] + rez;
				best = s[i];
			} else {
				rez += s[i];
			}
		}

		g << "Case #" << ii << ": " << rez << e;

	}

}

