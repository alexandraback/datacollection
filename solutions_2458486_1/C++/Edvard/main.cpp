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

const int N = 400 + 3;

int k, n;
int s[N], t[N];
vector<int> a[N];
vector<int> g[N];

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
	
	forn(i, n)
	{
		g[i].clear();
		
		forn(j, n)
		{
			bool ok = false;
			
			forn(k, sz(a[i]))
				if (a[i][k] == t[j])
					ok = true;
					
			if (ok) g[i].pb(j);
		}
	}
	
	return true;
}

int used[N];
int u = 0, us[N];
vector<int> path;

bool dfs(int v, int t)
{
	if (used[v] || us[v] == u) return false;
	us[v] = u;
	
	forn(i, sz(a[v]))
		if (a[v][i] == t)
		{
			path.pb(v);
			return true;
		}
		
	forn(i, sz(g[v]))
		if (dfs(g[v][i], t))
		{
			path.pb(v);
			return true;
		}
		
	return false;
}

int cnt[N];

inline bool check(const vector<int>& ans)
{
	memset(cnt, 0, sizeof(cnt));
	memset(used, 0, sizeof(used));
	
	forn(i, k) cnt[s[i]]++;
	
	forn(i, sz(ans))
	{
		if (used[ans[i]]) return false;
		used[ans[i]] = true;
		assert(cnt[t[ans[i]]] > 0);
		cnt[t[ans[i]]]--;
		
		forn(j, sz(a[ans[i]]))
			cnt[a[ans[i]][j]]++;
	}
	
	return sz(ans) == n;
}

inline void solve(int test)
{
	printf("Case #%d:", test + 1);
	
	memset(cnt, 0, sizeof(cnt));
	memset(used, 0, sizeof(used));
	
	forn(i, k) cnt[s[i]]++;
	
	vector<int> ans;
	
	while (sz(ans) < n)
	{
		forn(i, n)
			if (!used[i] && cnt[t[i]] > 0)
			{
				u++;
				path.clear();
				
				if (dfs(i, t[i]))
				{
					reverse(all(path));
					
					forn(j, sz(path))
					{
						int v = path[j];
						used[v] = true;
						ans.pb(v);
						
						assert(--cnt[t[v]] >= 0);
						
						forn(k, sz(a[v]))
							cnt[a[v][k]]++;
					}
					
					goto end;
				}
			}
			
		forn(i, n)
			if (!used[i] && cnt[t[i]] > 0)
			{
				used[i] = true;
				ans.pb(i);
				
				assert(--cnt[t[i]] >= 0);
				
				forn(j, sz(a[i]))
					cnt[a[i][j]]++;
					
				goto end;
			}
			
		puts(" IMPOSSIBLE");
		return;
		
		end:;
	}
	
	forn(i, sz(ans)) printf(" %d", ans[i] + 1); puts("");
	
	cerr << test + 1 << endl;
	assert(check(ans));
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
