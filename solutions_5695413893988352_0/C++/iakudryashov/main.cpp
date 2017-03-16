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

string s[2];

inline bool read() {
    forn(i, 2) cin >> s[i];
	return true;
}

li ansa, ansb, mind;

inline void checkans(li a, li b) {
    if (abs(a - b) < mind || (abs(a - b) == mind && a < ansa) || (abs(a - b) == mind && a == ansa && b < ansb)) {
        ansa = a;
        ansb = b;
        mind = abs(a - b);
    }
}

inline void print(li a) {
    int digits = 0;
    li olda = a;
    while (a > 0) {
        digits++;
        a /= 10;
    }
    digits = max(digits, 1);
    assert(digits <= sz(s[0]));
    forn(i, sz(s[0]) - digits) putchar('0');
    cout << olda;
}

inline li f(const string& s, int dig) {
    li res = 0;
    forn(i, sz(s)) {
        int val = s[i] == '?' ? dig : (s[i] - '0');
        res *= 10;
        res += val;
    }
    return res;
}

inline bool check(li a, string s) {
    string sa = "";
    while (a > 0) {
        sa.pb(a % 10 + '0');
        a /= 10;
    }
    reverse(all(sa));
    while (sz(sa) < sz(s)) sa = "0" + sa;
    forn(i, sz(sa)) {
        if (s[i] != '?' && s[i] != sa[i]) return false;
    }
    return true;
}

inline void naive(li& ansa, li& ansb) {
    li maxv = 1;
    forn(i, sz(s[0])) maxv *= 10;

    for (li a = 0; a < maxv; a++) {
        if (!check(a, s[0])) continue;
        for (li b = 0; b < maxv; b++) {
            if (!check(b, s[1])) continue;
            checkans(a, b);
        }
    }
    ansa = ::ansa;
    ansb = ::ansb;
}

inline void solve() {
    string olds[2];
    forn(i, 2) olds[i] = s[i];
    mind = 2e18;
    li naive_a, naive_b;
    //naive(naive_a, naive_b);

    mind = 2e18;
    forn(i, sz(s[0])) {
        if (s[0][i] != s[1][i] && s[0][i] != '?' && s[1][i] != '?') {
            li a = f(s[0], s[0][i] > s[1][i] ? 0 : 9);
            li b = f(s[1], s[0][i] > s[1][i] ? 9 : 0);
            checkans(a, b);
            break;
        }
        if (s[0][i] == '?' && s[1][i] == '?') {
            forn(j, 2) {
                s[j][i] = '0';
                s[j ^ 1][i] = '1';
                li a = f(s[j], 9);
                li b = f(s[j ^ 1], 0);
                if (j == 1) swap(a, b);
                checkans(a, b);
            }
            s[0][i] = s[1][i] = '0';
            continue;
        }
        if (s[0][i] != '?' && s[1][i] != '?') continue;
        int iter = s[0][i] == '?' ? 0 : 1;
        for (int dig = s[iter ^ 1][i] - 1; dig <= s[iter ^ 1][i] + 1; dig += 2) {
            if (dig < '0' || dig > '9') continue;
            s[iter][i] = (char)dig;
            li a = f(s[0], s[0][i] > s[1][i] ? 0 : 9);
            li b = f(s[1], s[0][i] > s[1][i] ? 9 : 0);
            checkans(a, b);
        }
        s[iter][i] = s[iter ^ 1][i];
    }
    li a = f(s[0], 0);
    li b = f(s[1], 0);
    checkans(a, b);
    
    print(ansa);
    putchar(' ');
    print(ansb);
    puts("");

    /*if (ansa != naive_a || ansb != naive_b) {
        cerr << "test = " << olds[0] << ' ' << olds[1] << endl;
        cerr << "naive = " << naive_a << ' ' << naive_b << endl;
        cerr << "ans = " << ansa << ' ' << ansb << endl;
    }*/
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
		printf("Case #%d: ", test);
		solve();
	}
	
#ifdef SU2_PROJ
	cerr << "=== TOTAL TIME: " << clock() / CLOCKS_PER_SEC << " ===" << endl;
#endif

	return 0;
}
