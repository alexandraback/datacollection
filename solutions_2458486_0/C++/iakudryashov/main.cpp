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

int n, k;
int d[(1 << 20) + 13];
int keys[300], a[300];
int t[30];
vector <int> g[30];

inline bool read()
{
	if (scanf("%d%d", &k, &n) != 2)
		return false;
		
	memset(keys, 0, sizeof(keys));
		
	forn(i, k)
	{
		int t;
		assert(scanf("%d", &t) == 1);
		keys[t - 1]++;
		a[i] = t - 1;
	}
		
	forn(i, n)
	{
		assert(scanf("%d", &t[i]) == 1);
		t[i]--;
		g[i].clear();
		int cnt;
		assert(scanf("%d", &cnt) == 1);
		
		forn(j, cnt)
		{
			int t;
			assert(scanf("%d", &t) == 1);
			g[i].pb(t - 1);
		}
	}
	
	return true;
}

int ans[30], szans;

int can (int mask)
{
	int& res = d[mask];
	if (res != -1) return res;
	
	//cerr << mask << endl;
	
	if (mask == (1 << n) - 1) return res = 1;
	
	int cur[200];
	forn(i, 200) cur[i] = keys[i];
	
	forn(i, n) if (mask & (1 << i))
	{
		cur[t[i]]--;
		forn(j, sz(g[i])) cur[g[i][j]]++;
	}
	
	forn(i, n)
		if ((mask & (1 << i)) == 0 && cur[t[i]] > 0 && can(mask ^ (1 << i)))
		{
			ans[szans++] = i;
			return res = 1;
		}
		
	return res = 0;
}

inline void solve(int test)
{
	forn(i, (1 << n)) d[i] = -1;
	szans = 0;
	bool ansv = can(0);
	reverse(ans, ans + szans);
	
	if (ansv)
	{
		printf("Case #%d:", test + 1);
		forn(i, n) printf(" %d", ans[i] + 1);
		puts("");
	} else
		printf("Case #%d: IMPOSSIBLE\n", test + 1);
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
		cerr << test + 1 << ' ' << clock() / 1000.0 << endl;
	}
	
	return 0;
}
