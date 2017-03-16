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

const int maxn = 100 ;
const int maxe = 100 ;

int V[maxn] ;
int E, R, N ;

int G[maxn][maxe] ;
int P(int n, int e)
{
	if (n >= N) return 0 ;

	int &g = G[n][e] ;
	if (g != -1) return g ;

	int r = 0 ;
	forn(i, e + 1) r = max(r, V[n] * i + P(n + 1, min(E, e - i + R))) ;

	return g = r ;
}

int main()
{
	int t ; cin >> t ;
	forn(z, t)
	{
		memset(G, -1, sizeof G) ;

		cin >> E >> R >> N ;
		forn(i, N) cin >> V[i] ;

		printf("Case #%d: %d\n", z + 1, P(0, E)) ;
	}

	return 0 ;
}

