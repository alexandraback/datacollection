#include <windows.h>
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

const int N = 1000 * 1000 + 13;

int r, n, m, k;
int a[N];

inline bool read()
{
	return scanf("%d%d%d%d", &r, &n, &m, &k) == 4;
}

inline int gcd(int a, int b) { return a == 0 ? b : gcd(b % a, a); }
inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

int sz;
int ans[N];

bool solve(int x, int cnt, int last)
{
	if (x == 1) return cnt == n;
	
	fore(i, 2, last)
		if (x % i == 0 && solve(x / i, cnt + 1, i))
		{
			ans[sz++] = i;
			return true;
		}
		
	return false;
}

inline void solve(int test)
{
	printf("Case #%d:\n", test + 1);
	
	forn(i, r)
	{
		int l = 1;
		
		forn(j, k)
		{
			assert(scanf("%d", &a[i]) == 1);			
			l = lcm(l, a[i]);
		}
		
		sz = 0;
		
		if (solve(l, 0, m))
		{
			assert(sz == n);
			forn(i, sz) printf("%d", ans[i]);
		}
		else
			forn(i, n) printf("%d", 2);
			
		puts("");
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
	
	srand(GetTickCount());
	
	int testCount;
	cin >> testCount;
	
	forn(test, testCount)
	{        
		assert(read());
		solve(test);
	}
        
	return 0;
}