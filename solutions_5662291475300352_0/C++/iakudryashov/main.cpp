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
const ld EPS = 1e-6, PI = 3.1415926535897932384626433832795;

struct group {
    int start, cnt, m;
    group (int start, int cnt, int m) : start(start), cnt(cnt), m(m) {}
};

inline bool operator < (const group& a, const group& b) { 
    if (a.start != b.start) return a.start < b.start;
    return a.m > b.m;
}

vector<group> v;

inline bool read() {
    int n;
    cin >> n;
    v.clear();
    forn(i, n) {
        int start, cnt, m;
        cin >> start >> cnt >> m;
        v.pb(group(start, cnt, m));
    }
	return true;
}

ld start[2], vel[2];

inline int solve() {
    sort(all(v));
    int totalcnt = 0;
    forn(i, sz(v)) {
        totalcnt += v[i].cnt;
    }
    if (totalcnt < 2) return 0;
    if (sz(v) == 1) {
        start[0] = start[1] = v[0].start;
        vel[0] = 360.0 / (v[0].m + 1);
        vel[1] = 360.0 / (v[0].m);
    } else {
        start[0] = v[0].start;
        start[1] = v[1].start;
        vel[0] = 360.0 / v[0].m;
        vel[1] = 360.0 / v[1].m;
    }

    assert(start[0] <= start[1] + EPS);

    if (vel[0] > vel[1]) {
        ld x = (start[1] - start[0] + 360) * vel[1] / (vel[0] - vel[1]);
        start[1] += vel[1] * x;
        if (start[1] >= 360) return 0;
        start[0] = start[1];
        swap(vel[0], vel[1]);
    }

    if (abs(vel[0] - vel[1]) < EPS) return 0;

    assert(vel[0] < vel[1]);

    ld x = 360 * vel[0] / (vel[1] - vel[0]);
    ld pos = start[0] + vel[0] * x;
    if (pos >= 360) return 0;
    return 1;
}

int main() {
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);

	cout << setprecision(10) << fixed;
	cerr << setprecision(5) << fixed;

	int testCount;
	cin >> testCount;

	forl(test, testCount) {
#ifdef SU2_PROJ
		cerr << "=== test: " <<  test << ", time: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif
		assert(read());
		printf("Case #%d: %d\n", test, solve());
	}
	
#ifdef SU2_PROJ
	cerr << "=== TOTAL TIME: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif

	return 0;
}
