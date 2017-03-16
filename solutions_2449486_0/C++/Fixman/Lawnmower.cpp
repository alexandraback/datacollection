#include <algorithm>
#include <bitset>
#include <cmath>
#include <climits>
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

const int maxn = 150 ;

int K[maxn][maxn] ;
bool P[maxn][maxn] ;

int N, M ;

void cut(int y, int x, int dy, int dx, int h)
{
	for (int i = y, u = x ; i < N && u < M ; i += dy, u += dx)
		if (K[i][u] > h) return ;

	for (int i = y, u = x ; i < N && u < M ; i += dy, u += dx)
		P[i][u] = true ;
}

bool caso()
{
	cin >> N >> M ;
	forn(i, N) forn(u, M) cin >> K[i][u] ;

	for (int h = maxn ; h > 0 ; h--)
	{
		memset(P, false, sizeof P) ;

		forn(i, N) cut(i, 0, 0, 1, h) ;
		forn(i, M) cut(0, i, 1, 0, h) ;

		forn(i, N) forn(u, M) if (K[i][u] <= h && !P[i][u]) return false ;
	}

	return true ;
}

int main()
{
	int t ; cin >> t ;
	forn(i, t) printf("Case #%d: %s\n", i + 1, caso() ? "YES" : "NO")  ;

	return 0 ;
}

