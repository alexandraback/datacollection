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

const int big = 1000000000 ;

int solve()
{
	int a, n ; cin >> a >> n ;

	vector <int> q(n) ;
	fore(i, q) cin >> q[i] ;
	sort(all(q)) ;

	int r = big ;
	int p, w ;

	int l = -1 ;
	for (p = 0, w = 0 ; a != l ; a = 2 * a - 1, p++)
	{
		if (a == l) break ;
		l = a ;

		for (; w < q.size() && q[w] < a ; w++) a += q[w] ;
		r = min(r, p + n - w) ;
	}
	r = min(r, p + n - w) ;

	return r ;
}

int main()
{
	int t ; cin >> t ;
	forn(z, t) printf("Case #%d: %d\n", z + 1, solve()) ;

	return 0 ;
}

