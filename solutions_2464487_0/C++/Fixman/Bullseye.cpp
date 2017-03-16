#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
 
using namespace std ;

#define all(n) n.begin(), n.end()
#define fore(i, n) forn (i, n.size())
#define fori(i, n) for (typeof (n.begin()) i = n.begin() ; i != n.end() ; i++)
#define forn(i, n) forsn (i, 0, n)
#define forsn(i, s, n) for (int i = s ; i < n ; i++)
#define LOG cerr << "[" << __LINE__ << "] "
#define pb push_back

typedef long long tint ;
typedef long double tdouble ;

inline tdouble sq(tdouble n) { return n * n ; }

const tdouble eps = 1e-18L ;

tdouble f(tdouble r, tdouble t)
{
	tdouble a = -.5L * r + .25L + sqrtl(sq(2 * r - 1) / 16 + .5L * t)  ;
	return a ;
}

tint ceili(tint a, tint b) { return a / b + !!(a % b) ; }

tint q(tint d, tint r)
{
	return 2 * d + 2 * r - 1 ;
}

int main()
{
	int t ; cin >> t ;
	forn(z, t)
	{
		tint r, t ; cin >> r >> t ;

		tint n = 0, m = (1ll << 30) ;
		while (n + 1 < m)
		{
			tint s = (n + m) / 2 ;
			if (q(s, r) <= t / s /*ceili(t, s)*/) n = s ;
			else m = s ;
		}

		//cout << n << ' ' << q(n, r) << endl ;
		printf("Case #%d: %lld\n", z + 1, n) ;

		//printf("%.32Lf\n", f(r, t)) ;
		//printf ("Case #%d: %lld\n", z + 1, (tint)(floorl(f(r, t) - eps))) ;
	}

	return 0 ;
}

