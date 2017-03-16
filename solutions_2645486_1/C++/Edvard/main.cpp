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
typedef pair<li, li> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 10 * 1000 + 3;

int e, r, n, v[N];

inline bool read()
{
	if (scanf("%d%d%d", &e, &r, &n) != 3) return false;
	r = min(r, e);
	forn(i, n) assert(scanf("%d", &v[i]) == 1);
	return true;
}

int maxv[N];

inline void solve(int test)
{
	printf("Case #%d: ", test + 1);
	
	maxv[n - 1] = v[n - 1]; ford(i, n - 1) maxv[i] = max(maxv[i + 1], v[i]);
	
	li ans = 0, cure = e;
	multiset<pt, greater<pt> > z;
	
	forn(i, n)
	{
		if (v[i] == maxv[i])
		{
			ans += cure * v[i];
			cure = 0;
		}
		else
		{
			li d = max(0ll, cure - (e - r));
			z.insert(mp(v[i], cure));
			cure -= d;
			
			while (d > 0)
			{
				pt p = *z.begin();
				z.erase(z.begin());
				
				li curd = min(d, p.sc);
				ans += p.ft * curd;
				d -= curd;
				p.sc -= curd;
				if (p.sc > 0) z.insert(p);
			}
		}
		
		cure += r;
		assert(cure <= e);
	}
	
	cout << ans << endl;
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
