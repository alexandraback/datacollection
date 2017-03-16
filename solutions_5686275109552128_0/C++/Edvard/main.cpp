#undef NDEBUG
#ifdef SU2_PROJ
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

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

const int N = 1000 + 3;

int n, a[N];

inline bool read() {
	if (!(cin >> n)) return false;
	forn(i, n) assert(scanf("%d", &a[i]) == 1);
	return true;
}

inline int solve() {
	int ans = INF;
	forl(i, 1000) {
		int cur = 0;
		forn(j, n) {
			int x = a[j];
			while (x > i) x -= i, cur++;
		}
		//if (i + cur == 2) cerr << i << ' ' << cur << endl;
		ans = min(ans, i + cur);
	}
	return ans;
}

int main()
{
#ifdef SU2_PROJ
    assert(freopen("input.txt", "rt", stdin));
    assert(freopen("output.txt", "wt", stdout));
#endif
    
    cout << setprecision(10) << fixed;
    cerr << setprecision(5) << fixed;

	int tt;
	cin >> tt;
	forn(t, tt) {
		cerr << "Test #" << t + 1 << " is processing" << endl;
		printf("Case #%d:", t + 1);
		assert(read());
		printf(" %d\n", solve());
	}
	
    return 0;
}
