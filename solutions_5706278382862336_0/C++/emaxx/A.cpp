#define _SECURE_SCL 0
#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;


typedef long long int64;
#define double long double
const int INF = (int) 1E9;
const int64 INF64 = (int64) 1E18;
const double EPS = 1E-9;
const double EPS_ANG = 1E-16;
const double PI = acos((double)0) * 2;

#define forn(i,n)  for (int i=0; i<int(n); ++i)
#define ford(i,n)  for (int i=int(n)-1; i>=0; --i)
#define all(a)  a.begin(), a.end()
#define fs  first
#define sc  second
#define mp  make_pair
#define pb  push_back


int64 p, q;


void read() {
	char c;
	cin >> p >> c >> q;
}


int64 gcd(int64 a, int64 b) {
	return a ? gcd(b % a, a) : b;
}


void solve() {
	int64 g = gcd(p, q);
	p /= g;
	q /= g;

	if (!(q & (q - 1))) {
		forn(i, 40) {
			if (q % 2)
				throw;
			if (p * 2 >= q) {
				printf("%d\n", i + 1);
				return;
			}
			q /= 2;
		}
	}
	puts("impossible");
}


int main() {
#ifdef SU2_PROJ
	freopen ("input.txt", "rt", stdin);
	freopen ("output.txt", "wt", stdout);
#endif

	int ts;
	cin >> ts;
	forn(tt, ts) {
		cerr << "Case #" << tt + 1 << "..." << endl;
		read();
		printf("Case #%d: ", tt + 1);
		solve();
	}
	cerr << "Finish." << endl;

	return 0;
}
