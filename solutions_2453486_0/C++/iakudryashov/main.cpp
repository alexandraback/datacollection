#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>
#include <numeric>
#include <functional>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define x first
#define y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int n = 4;
char f[5][5];

inline bool read()
{
	forn(i, 4) assert(scanf("%s", f[i]) == 1);
	return true;
}

inline bool win (char x)
{
	forn(i, n)
	{
		int cntx = 0, cntt = 0;
		forn(j, n) if (f[i][j] == x) cntx++; else if (f[i][j] == 'T') cntt++;
		if (cntx == 4 || (cntx == 3 && cntt == 1)) return true;
		cntx = 0, cntt = 0;
		forn(j, n) if (f[j][i] == x) cntx++; else if (f[j][i] == 'T') cntt++;
		if (cntx == 4 || (cntx == 3 && cntt == 1)) return true;
	}
	
	int cntx = 0, cntt = 0;
	forn(i, n) if (f[i][i] == x) cntx++; else if (f[i][i] == 'T') cntt++;
	if (cntx == 4 || (cntx == 3 && cntt == 1)) return true;
	cntx = 0, cntt = 0;
	forn(i, n) if (f[i][n - 1 - i] == x) cntx++; else if (f[i][n - 1 - i] == 'T') cntt++;
	if (cntx == 4 || (cntx == 3 && cntt == 1)) return true;
	return false;
}

inline bool draw () { forn(i, n) forn(j, n) if (f[i][j] == '.') return false; return true; }

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);
	
	if (win('X')) puts("X won");
	else if (win('O')) puts("O won");
	else if (draw()) puts("Draw");
	else puts("Game has not completed");
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	
	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{
    	assert(read());
    	solve(test);
	}
	
	return 0;
}
