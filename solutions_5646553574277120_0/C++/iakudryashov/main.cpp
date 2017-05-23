#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define foreach(it, a) for(__typeof((a).begin()) it = (a).begin(); it != (a).end(); it++)
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
template<typename X, typename Y> inline ostream& operator<< (ostream& out, const pair <X, Y>& p) { return out << '(' << p.x << ", " << p.y << ')'; }
template<typename X> inline ostream& operator<< (ostream& out, const vector<X>& p) { forn(i, sz(p)) { if (i != 0) out << ' '; out << p[i]; } return out; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

const int N = 30 + 3;

int c, n, maxv, a[N];

inline bool read()
{
    if (scanf("%d%d%d", &c, &n, &maxv) != 3) return false;
    forn(i, n) assert(scanf("%d", &a[i]) == 1);
	return true;
}

int used[N];

inline void prepare ()
{
    memset(used, 0, sizeof(used));
    used[0] = true;
    forn(i, n) ford(j, maxv) if (used[j] && j + a[i] <= maxv) used[j + a[i]] = true;
}

int ans;
int have[N];
int curused[10][N];

void go (int val, int cnt) {
    if (cnt >= ans) return;
    if (have[val]) return go(val + 1, cnt);
    if (val > maxv) return;
    ford(i, maxv + 1) {
        curused[cnt + 1][i] = curused[cnt][i];
        if (curused[cnt][i] && i + val <= maxv) curused[cnt + 1][i + val] = true;
    }
    bool ok = true;
    forl(i, maxv) if (!curused[cnt + 1][i]) { ok = false; break; }
    if (ok) {
        ans = min(ans, cnt + 1);
        return;
    }
    go(val + 1, cnt + 1);

    go(val + 1, cnt);
}

inline void solve()
{
    prepare();
    memset(have, 0, sizeof(have));
    forn(i, n) have[a[i]] = true;
    memset(curused, 0, sizeof(curused));
    bool ok = true;
    forn(i, maxv + 1) {
        if (!used[i]) ok = false;
        curused[0][i] = used[i];
    }
    if (ok) ans = 0;
    else ans = 5;
    go(1, 0);
    cout << ans << endl;
}

int main()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	int testCount;
	cin >> testCount;

	forl(test, testCount)
	{
#ifdef SU2_PROJ
		cerr << "=== test: " <<  test << ", time: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif
		assert(read());
		printf("Case #%d: ", test);
		solve();
	}
	
#ifdef SU2_PROJ
	cerr << "=== TOTAL TIME: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif

	return 0;
}