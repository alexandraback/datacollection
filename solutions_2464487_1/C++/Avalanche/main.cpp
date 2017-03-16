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

li r, t;

inline bool read()
{
	return scanf("%I64d%I64d", &r, &t) == 2;
}

inline bool check(li k)
{
	li res = 2 * r * (k + 1) + (1 + 2 * k) * (k + 1);
	ld ans = 2 * ld(r) * ld(k + 1) + ld(1 + 2 * k) * ld(k + 1);

	if (ans > 6e18) return false;	
	return res <= t;	
}

inline void solve(int test)
{
	li lf = 0, rg = li(4e18);
	
	while (lf != rg)
	{
		li mid = (lf + rg + 1) >> 1;
		
		if (check(mid))
			lf = mid;
		else
			rg = mid - 1;
	}
	
	printf("Case #%d: %I64d\n", test + 1, lf + 1);
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