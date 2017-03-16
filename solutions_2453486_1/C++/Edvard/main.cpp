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
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

char a[5][5];

inline bool read()
{
	forn(i, 4)
		assert(scanf("%s", a[i]) == 1);
		
	return true;
}

int dx[] = { 0, 1, 1, 1 };
int dy[] = { 1, 0, 1, -1 };

inline bool check(char c)
{
	forn(i, 4)
		forn(j, 4)
			forn(dir, 4)
			{
				int cnt = 0;
				
				while (true)
				{
					int x = i + dx[dir] * cnt, y = j + dy[dir] * cnt;
					if (!correct(x, y, 4, 4)) break;
					if (a[x][y] != c && a[x][y] != 'T') break;
					cnt++;
				}
				
				assert(cnt <= 4);
				if (cnt == 4) return true;
			}
	return false;
}

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);
	
	if (check('O')) puts("O won");
	else if (check('X')) puts("X won");
	else
	{
		forn(i, 4)
			forn(j, 4)
				if (a[i][j] == '.')
				{
					puts("Game has not completed");
					return;
				}
		puts("Draw");
	}
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
