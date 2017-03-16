#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <complex>

using namespace std;

#define INF 1000000001
#define INFL 1000000000000000001ll
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define sz(x) ((int) (x).size())

typedef long long ll;
typedef long double ld;
typedef complex <ld> point;

#define NAME "cookie_clicker"

void solve(int test) {
	ld c, f, x;
	cin >> c >> f >> x;
	ld cur = 0;
	ld delta = 2;
	ld T = 0;
	while (cur < x) {
		if (cur < c) {
			ld d = min(x - cur, c - cur);
			T += d / delta;
			cur = min(x, c);
			//~ cerr << "Q\n";
			continue;
		}
		if ((x - cur) / delta <= (x - cur + c) / (delta + f)) {
			T += (x - cur) / delta;
			cur = x;
			//~ cerr << "W\n";
			continue;
		}
		//~ cerr << "E\n";
		cur -= c;
		delta += f;
	}
	cout << "Case #" << test << ": " << T << '\n';
}

int main() {
	srand(time(0));
	cout.setf(ios::fixed);
	cout.precision(7);
	#ifdef _GEANY
	assert(freopen(NAME ".in", "r", stdin));
	#endif
	int tn;
	cin >> tn;
	for (int i = 0; i < tn; ++i)
		solve(i + 1);
}
