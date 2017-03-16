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

const int N = 50 + 3;

int e, r, n;
li v[N];

inline bool read()
{
	if (scanf("%d%d%d", &e, &r, &n) != 3)
		return false;
		
	forn(i, n) assert(scanf("%I64d", &v[i]) == 1);
	
	return true;
}

li z[N][N];

li solve(int idx, int energy)
{
	li& ans = z[idx][energy];
	if (ans != -1) return ans;	
	if (idx == n) return ans = 0;
	
	ans = 0;
	fore(i, 0, energy)
	{
		int nen = min(e, energy - i + r);		
		ans = max(ans, i * 1LL * v[idx] + solve(idx + 1, nen));
	}
	
	return ans;
}

inline void solve(int test)
{
	memset(z, -1, sizeof z);
	printf("Case #%d: %I64d\n", test + 1, solve(0, e));
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