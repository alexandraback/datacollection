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

void rec(string s, string is, int idx)
{
	if (idx == sz(s)) return ans.pb(s);
	
	if (is[idx] == '1') return rec(s, is, idx + 1);
	
	fore(i, 2, m)
	{
		string ss(s);
		ss[idx] = char('0' + i);
		rec(ss, is, idx + 1);
	}
}

void gen(string s, string is)
{
	if (sz(s) == n)
	{
		forn(i, k) if (a[i] != 1) return;
		rec(s, is, 0);
		return;
	}
	
	vector<pt> cur(m - 1);
	
	fore(i, 2, m)
	{
		cur[i - 2].sc = i;
		
		forn(j, k)
			if (a[j] % i == 0)
				cur[i - 2].ft++;
	}
	
	sort(all(cur), greater<pt> ());
	
	int M = sz(s) <= 2 ? 3 : sz(s) <= 5 ? 2 : 1;
	
	forn(i, min(sz(cur), M))
	{
		if (cur[i].sc == 0 && cur[i].ft != 2) continue;
		int d = cur[i].sc;
		vector<int> pos; forn(j, k) if (a[j] % d == 0) a[j] /= d, pos.pb(j);
		gen(s + char('0' + d), is + char('0' + !pos.empty()));
		forn(j, sz(pos)) a[pos[j]] *= d;
	}
}

inline void solve(int test)
{
	printf("Case #%d:\n", test + 1);
	
	int bad = 0;
	
	forn(t, r)
	{
		forn(i, k) assert(scanf("%d", &a[i]) == 1);
		ans.clear();
		gen("", "");
		if (ans.empty()) ans.pb(string(n, '2')), bad++;
		random_shuffle(all(ans));
		puts(ans[0].c_str());
		if (t % 100 == 99) cerr << "After " << t + 1 << " cases clock = " << clock() << endl;
		//cerr << sz(ans) << endl;
	}
	
	cerr << bad << endl;
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
