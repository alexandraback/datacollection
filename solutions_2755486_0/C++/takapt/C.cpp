#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cfloat>
#include <ctime>
#include <cassert>
#include <map>
#include <utility>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <complex>
#include <stack>
#include <queue>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <bitset>
   
using namespace std;
   
 
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
#define rforeach(it, c) for (__typeof__((c).rbegin()) it=(c).rbegin(); it != (c).rend(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CL(arr, val) memset(arr, val, sizeof(arr))
#define COPY(dest, src) memcpy(dest, src, sizeof(dest))
#define ten(n) ((long long)(1e##n))
#define bin(n) (1LL << (n))
#define erep(i, n) for (int i = 0; i <= (int)(n); ++i)
#define revrep(i, n) for (int i = (n); i >= 0; --i)
#define pb push_back

template <class T> void chmax(T& a, const T& b) { a = max(a, b); }
template <class T> void chmin(T& a, const T& b) { a = min(a, b); }

template <class T> void uniq(T& c) { sort(c.begin(), c.end()); c.erase(unique(c.begin(), c.end()), c.end()); }
 
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }

template <typename T> void print_container(ostream& os, const T& c) { const char* _s = " "; if (!c.empty()) { __typeof__(c.begin()) last = --c.end(); foreach (it, c) { os << *it; if (it != last) cout << _s; } } }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const deque<T>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "( " << p.first << ", " << p.second << " )"; return os; }

template <class T> void print(T a, int n, const string& deli = " ", int br = 1) { for (int i = 0; i < n; ++i) { cout << a[i]; if (i + 1 != n) cout << deli; } while (br--) cout << endl; }
template <class T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) {    if (width != -1) cout.width(width); cout << a[i][j] << ' '; } cout << endl; } while (br--) cout << endl; }

template <class T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
template <class T> void input(T* a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }

void fix_pre(int n) { cout.setf(ios::fixed, ios::floatfield); cout.precision(10); }
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
#define trace(x) (cout << #x << ": " << (x) << endl)
 
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }


typedef long long ll;
typedef pair<int, int> pint;
 
// y(v): v>^<  y(^): ^>v<
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

const double PI = acos(-1.0);
#define mp make_pair



// d, n, w, e, s, d_d, d_p, d_s
ll solve()
{
    // const int M = 16;
    // ll d[M], days[M], w[M], e[M], s[M], d_d[M], d_p[M], d_s[M];

    const int offset = 1000;
    const ll last = ten(6);
    typedef pair<pint, ll> AT;
    static vector<AT> at[last];
    rep(i, last)
        at[i].clear();

    int n;
    cin >> n;
    rep(c, n)
    {
        ll d, days, w, e, s, d_d, d_p, d_s;
        cin >> d >> days >> w >> e >> s >> d_d >> d_p >> d_s;
        w *= 2, e *= 2, d_p *= 2;
        w += offset, e += offset;
        while (days-- > 0)
        {
            at[d].pb(AT(pint(w, e), s));
            
            d += d_d;
            w += d_p, e += d_p;
            s += d_s;
        }
    }

    ll h[2 * offset] = {};

    // In the first case, the first tribe attacks three times: on day 0 it hits the interval [0,2] at height 10, on day 2 it hits [3,5] at height 8 and on day 4 it hits [6,8] at height 6; all three attacks succeed.
    //Then the second tribe attacks three times, each time at height 8 - on day 10 it hits [2,3] (this succeeds, for example at position 2.5, where the Wall has still height 0), on day 17 it hits [4,5] (this fails, the Wall is already of height 8 in the interval [3, 5], which covers [4, 5]), and on day 24 it hits [6,7] (this succeeds, as the Wall there was of height 6).
    ll succ = 0;
    rep(day, last)
    {
        if (day <= 40 && false)
        {
            vector<int> hh;
            for (int x = offset; x <= offset + 20; ++x)
                printf("%2lld ", h[x]);
            puts("");
        }
        foreach (it, at[day])
        {
            int w = it->first.first, e = it->first.second;
            int s = it->second;
            assert(w >= 0);
            assert(e < 2 * offset);

            bool ok = false;
            for (int x = w; x <= e; ++x)
                if (h[x] < s)
                    ok = true;
            // printf("%3d: (%3d, %3d) %d", day, w - offset, e - offset, s);
            if (ok)
            {
                // printf(" !!!!");
                ++succ;
            }
            // puts("");
        }
        foreach (it, at[day])
        {
            int w = it->first.first, e = it->first.second;
            int s = it->second;
            for (int x = w; x <= e; ++x)
                if (h[x] < s)
                    chmax<ll>(h[x], s);
        }
    }
    return succ;
}
int main()
{
    int tt;
    cin >> tt;
    for (int T = 1; T <= tt; ++T)
    {
        ll res = solve();
        cout << "Case #" << T << ": ";
        cout << res << endl;
    }
}
