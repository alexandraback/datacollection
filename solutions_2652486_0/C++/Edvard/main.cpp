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

int r, n, m, k;

inline bool read()
{
	return cin >> r >> n >> m >> k;
}

int a[20];
vector<string> ans;

void gen(int idx, string s, int f)
{
	if (idx == n)
	{
		set<int> cur;
		
		forn(mask, (1 << n))
		{
			int m = 1;
			
			forn(i, n)
				if (mask & (1 << i))
					m *= s[i] - '0';
					
			cur.insert(m);
		}
		
		forn(i, k) if (!cur.count(a[i])) return;
		ans.pb(s);
		return;
	}
	
	fore(i, f, m)
		gen(idx + 1, s + char('0' + i), i);
}

inline void solve(int test)
{
	printf("Case #%d:\n", test + 1);
	
	forn(t, r)
	{
		forn(i, k) assert(scanf("%d", &a[i]) == 1);
		ans.clear();
		gen(0, "", 2);
		assert(!ans.empty());
		random_shuffle(all(ans));
		puts(ans[0].c_str());
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
