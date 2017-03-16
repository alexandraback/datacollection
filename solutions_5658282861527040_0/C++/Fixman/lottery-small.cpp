#include <algorithm>
#include <bitset>
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
#include <string>
#include <utility>
#include <vector>
 
using namespace std ;
 
#define forsn(i, s, n) for (int i = s ; i < n ; i++)
#define forn(i, n) forsn(i, 0, n)
#define fore(i, n) forn(i, n.size())
#define fori(i, n) for (auto i = n.begin() ; i != n.end() ; i++)
#define all(n) n.begin(), n.end()
#define pb push_back

typedef long long tint ;

tint solve(tint a, tint b, tint k)
{
	tint r = 0 ;
	forn(i, a) forn(u, b) if ((i & u) < k) r++ ;
	return r ;
}

int main()
{
	int t ; cin >> t ;
	forn(z, t)
	{
		tint a, b, k ; cin >> a >> b >> k ;
		printf("Case #%d: %lld\n", z + 1, solve(a, b, k)) ;
	}

	return 0 ;
}

