#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE

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
#define X first
#define Y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

int a, b;

inline bool read()
{
	return cin >> a >> b;
}

int u = 0, used[10 * 1000 * 1000 + 3];
char s[20];

inline void solve(int test)
{
	cerr << test << endl;
	
	int ans = 0;
	
	fore(i, a, b)
	{
		int sz = 0, x = i;
		
		while (x)
			s[sz++] = x % 10, x /= 10;
			
		reverse(s, s + sz);
		
		u++;
		
		forn(j, sz)
		{
			int y = 0;
			
			forn(k, sz)
				y = y * 10 + s[(j + k) % sz];
				
			if (i < y && used[y] != u && a <= y && y <= b)
			{
				//cerr << i << ' ' << y << endl;
				used[y] = u;
				ans++;
			}
		}
	}
	
	printf("Case #%d: %d\n", test + 1, ans);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    
    int testCount;
    cin >> testCount;
    
    forn(test, testCount)
    {
        assert(read());
        solve(test);
    }
    
    return 0;
}
