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

char M[5][5] ;

int va(int y, int x, int dy, int dx)
{
	char g = M[y][x] ;
	if (g == 'T') g = M[y + dy][x + dx] ;

	if (g == '.') return 0 ;
	for (; y < 4 && x < 4 ; y += dy, x += dx)
		if (M[y][x] != g && M[y][x] != 'T') return 0 ;

	return g == 'X' ? 1 : 2 ;
}

int caso()
{
	bool e = false ;
	forn(i, 4) forn(u, 4)
	{
		cin >> M[i][u] ;
		if (M[i][u] == '.') e = true ;
	}

	int r = 0 ;
	forn(i, 4) r |= va(i, 0, 0, 1) ;
	forn(i, 4) r |= va(0, i, 1, 0) ;
	r |= va(0, 0, 1, 1) ;
	r |= va(0, 3, 1, -1) ;

	if (r & 1) return 0 ;
	if (r & 2) return 1 ;
	return e + 2 ;
}

int main()
{
	const char *ans[] = {"X won", "O won", "Draw", "Game has not completed"} ;

	int t ; cin >> t ;
	forn(i, t) printf("Case #%d: %s\n", i + 1, ans[caso()])  ;

	return 0 ;
}

