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

const int N = 40 + 3;

int k, n;
int s[N];
int t[N];
vector<int> a[N];

inline bool read()
{
	if (scanf("%d%d", &k, &n) != 2) return false;
	
	forn(i, k) assert(scanf("%d", &s[i]) == 1), s[i]--;
	
	forn(i, n)
	{
		int cnt;
		assert(scanf("%d%d", &t[i], &cnt) == 2);
		t[i]--;
		a[i].resize(cnt);
		forn(j, cnt) assert(scanf("%d", &a[i][j]) == 1), a[i][j]--;
	}
	
	return true;
}

int cnt[N];
int u = 0, used[(1 << 20) + 3];
vector<int> ans;

bool dfs(int mask)
{
	if (mask == (1 << n) - 1) return true;
	
	if (used[mask] == u) return false;
	used[mask] = u;
	
	forn(i, n)
		if (!(mask & (1 << i)) && cnt[t[i]] > 0)
		{
			cnt[t[i]]--;
			forn(j, sz(a[i])) cnt[a[i][j]]++;
			if (dfs(mask | (1 << i)))
			{
				ans.pb(i);
				return true;
			}
			forn(j, sz(a[i])) cnt[a[i][j]]--;
			cnt[t[i]]++;
		}
	return false;
}

inline void solve(int test)
{
	printf("Case #%d:", test + 1);
	
	memset(cnt, 0, sizeof(cnt));
	forn(i, k) cnt[s[i]]++;
	
	u++;
	ans.clear();
	
	if (!dfs(0))
		puts(" IMPOSSIBLE");
	else
	{
		reverse(all(ans));
		forn(i, sz(ans)) printf(" %d", ans[i] + 1);
		puts("");
	}
	
	cerr << test + 1 << endl;
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
