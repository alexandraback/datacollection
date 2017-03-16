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

const int N = 4 + 3;

const int n = 4;
char a[N][N];

inline bool read()
{
	forn(i, n)
		assert(scanf("%s", a[i]) == 1);
		
	return true;
}

const int dx[] = { 1, 0, 1, -1 };
const int dy[] = { 0, 1, 1, 1 };

inline void solve(int test)
{
	forn(i, n)
		forn(j, n)
			forn(k, 4)
			{
				if (!correct(i + dx[k] * 3, j + dy[k] * 3, n, n)) continue;
				
				int winX = true, winO = true;
				
				forn(len, 4)
				{
					int x = i + dx[k] * len, y = j + dy[k] * len;
					
					if (a[x][y] == '.') winX = false, winO = false;
					else if (a[x][y] == 'O') winX = false;
					else if (a[x][y] == 'X') winO = false;
				}
				
				assert(!winX || !winO);
				
				if (winX)
				{
					printf("Case #%d: X won\n", test + 1);
					return;
				}
				
				if (winO)
				{
					printf("Case #%d: O won\n", test + 1);
					return;
				}
			}
			
	bool filled = true;
	forn(i, n) forn(j, n) if (a[i][j] == '.') filled = false;
	
	if (filled)
		printf("Case #%d: Draw\n", test + 1);
	else
		printf("Case #%d: Game has not completed\n", test + 1);
}

int main()
{
#ifdef SU2_PROJ
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
#endif
        
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