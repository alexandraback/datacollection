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
ll rez;
long long i, j, k;
string s;
bool impos;
int sm;
ll n;
char bb, ee;
char c[10000];

map <char, int> stuck;
map <char, int> beg;
map <char, int> end;
map <char, int> same;

#define NMOD 1000000007

ll fact(ll x) {
	ll r = 1;
	while (x > 0) {
		r = (r * x) % NMOD;
		x --;
	}
	return r;
}

int main() {

	f >> t;
	for (ii=1; ii<=t; ii++) {

		for (i='a'; i<='z'; i++) {
			stuck[i] = beg[i] = end[i] = same[i] = 0;
		}
		impos = false;
		rez = 1;

		f >> n;
		for (i=1; i<=n; i++) {
			f >> s;
			c[0] = 0;
			c[++c[0]] = s[0];
			for (j=1; j<s.length(); j++) {
				while (s[j] == s[j-1] && j<s.length()) {
					j++;
				}
				if (j<s.length()) {
					c[++c[0]] = s[j];
				}
			}

//			g << s << " " << (int) c[0] << ": ";
//			for (j = 1; j<=c[0]; j++) {
//				g << c[j];
//			}
//			g << e;

			if (c[0] == 1) {
				same[s[0]] ++;
			} else {
				bb = s[0];
				ee = s[s.length()-1];
				beg[bb] ++;
				end[ee] ++;
				for (j=2; j<c[0]; j++) {
					stuck[c[j]]++;
				}
			}
		}

//		for (i='a'; i<='z'; i++) {
//			if (stuck[i] > 0) {
//				g << (char) i << stuck[i] << e;
//			}
//		}
//
//		g << e << e;
//
//
//		continue;

		for (i='a'; i<='z'; i++) {
			if (stuck[i] > 0 && (end[i] > 0 || beg[i] > 0 || same[i] > 0)) {
				impos = 1;
			}
			if (end[i] > 1 || beg[i] > 1) {
				impos = 1;
			}
		}


		int coupled = 0;

		if (! impos) {
			for (i='a'; i<='z'; i++) {
				if (beg[i] || end[i] || same[i]) {
//					g << ii << " " << (char) i << " " << rez << e;
					coupled += beg[i] + end[i] + same[i] - 1;
					rez = (rez * fact(same[i])) % NMOD;
				}
			}
		}

//		g << ii << " " << n-coupled << " " << e;
		rez = (rez * fact(n-coupled)) % NMOD;


		if (impos) {
			g << "Case #" << ii << ": " << "0" << e;
		} else {
			g << "Case #" << ii << ": " << rez << e;
		}
	}


	return 0;

}
