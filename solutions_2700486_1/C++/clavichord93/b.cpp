#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <ctime>
#include <climits>
#include <cassert>
#include <string>
#include <bitset>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <numeric>
#define Fill(a, b) memset(a, b, sizeof(a))
#define Copy(a, b) memcpy(a, b, sizeof(b))
#define NPOS string::npos
#define rep(i, a, b) for (int i = a; i <= b; i++)
#define rrep(i, a, b) for (int i = a; i >= b; i--)
#define erep(j, a) for (Tedge *j = a; j; j = j -> next)
#define irep(i,a) for (__typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define sqr(a) ((a) * (a))
#define sf scanf
#define pf printf
#define pb push_back
#define ppb pop_back
#define pft push_front
#define ppf pop_front
#define mp make_pair
#define vec vector
#define it iterator
#define fir first
#define sec second
#define x first
#define y second
#define all(a) a.begin(),a.end()
#define sz(a) (int)(a.size())
#define bg(a) (a).begin()
#define en(a) (a).end()
#define clr(a) (a).clear()
#define dbg(x) cerr << __LINE__ << ": " << #x << " = " << (x) << endl
#define bin_cnt(x) __builtin_popcount((unsigned)x)
#define gcd(a, b) __gcd(a, b)
using namespace std;
template<class T> inline bool gmin(T &a, T b) { if (a > b) return a = b, true; return false; }
template<class T> inline bool gmax(T &a, T b) { if (a < b) return a = b, true; return false; }
template<class T> T exgcd(T a, T b, T &x, T &y) { if (!b) return x = (T)1, y = (T)0, a; else { T d = exgcd(b, a % b, y, x); return y -= a / b * x, d; } }
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vec<int> vi;
typedef vec<double> vd;
typedef istringstream iss;
typedef ostringstream oss;
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
const double DINF = 1e10;
const double EPS = 1e-9;
const double PI = 3.14159265358979323846264338327950288;
inline int dcmp(const double &a) { return a > EPS ? 1 : (a < -EPS ? -1 : 0); }

const int MAXN = 3005;

int n, x, y;
double f[MAXN][MAXN];

int main() {
    int T;
    sf("%d", &T);
    rep (cas, 1, T) {
        sf("%d %d %d", &n, &x, &y);
        int m = (abs(x) + abs(y)) / 2;
        n -= (2 * m - 1) * m;
        m++;
        if (n >= 4 * m - 3) printf("Case #%d: %.16f\n", cas, 1.0);
        else {
            if (n > 0 && y + 1 <= n) {
                Fill(f, 0); f[0][0] = 1.0;
                int k = 2 * m - 1;
                rep (p, 1, n) rep (i, 0, min(k, p)) {
                    int j = p - i;
                    if ((i == k && j != k - 1) || (j == k && i != k - 1)) continue;
                    if (j) {
                        if (i != k - 1) f[i][j] += f[i][j - 1] * 0.5;
                        else f[i][j] += f[i][j - 1];
                    }
                    if (i) {
                        if (j != k - 1) f[i][j] += f[i - 1][j] * 0.5;
                        else f[i][j] += f[i - 1][j];
                    }
                }
                double ans = 0;
                rep (i, y + 1, k) if (i <= n && n - i <= n) ans += f[i][n - i];
                pf("Case #%d: %.16f\n", cas, ans);
            }
            else pf("Case #%d: %.16f\n", cas, 0.0);
        }
    }

	return 0;
}
