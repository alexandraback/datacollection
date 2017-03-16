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

#define foreach(it, c) for (__typeof__((c).begin()) it=(c).begin(); it != (c).end(); ++it)
template <typename T> void print_container(ostream& os, const T& c) { const char* _s = " "; if (!c.empty()) { __typeof__(c.begin()) last = --c.end(); foreach (it, c) { os << *it; if (it != last) os << _s; } } }
template <typename T> ostream& operator<<(ostream& os, const vector<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const set<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const multiset<T>& c) { print_container(os, c); return os; }
template <typename T> ostream& operator<<(ostream& os, const deque<T>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const map<T, U>& c) { print_container(os, c); return os; }
template <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>& p) { os << "(" << p.first << ", " << p.second << ")"; return os; }

template <typename T> void print(T a, int n, const string& split = " ") { for (int i = 0; i < n; i++) { cout << a[i]; if (i + 1 != n) cout << split; } cout << endl; }
template <typename T> void print2d(T a, int w, int h, int width = -1, int br = 1) { for (int i = 0; i < h; ++i) { for (int j = 0; j < w; ++j) { if (width != -1) cout.width(width); cout << a[i][j] << ' '; } cout << endl; } while (br--) cout << endl; }
template <typename T> void input(T& a, int n) { for (int i = 0; i < n; ++i) cin >> a[i]; }
#define dump(v) (cerr << #v << ": " << v << endl)

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(a) (a).begin(), (a).end()
#define clr(a, x) memset(a, x, sizeof(a))
#define sz(a) ((int)(a).size())
#define mp(a, b) make_pair(a, b)
#define ten(n) ((long long)(1e##n))

template <typename T, typename U> void upmin(T& a, const U& b) { a = min<T>(a, b); }
template <typename T, typename U> void upmax(T& a, const U& b) { a = max<T>(a, b); }
template <typename T> void uniq(T& a) { sort(a.begin(), a.end()); a.erase(unique(a.begin(), a.end()), a.end()); }
template <class T> string to_s(const T& a) { ostringstream os; os << a; return os.str(); }
template <class T> T to_T(const string& s) { istringstream is(s); T res; is >> res; return res; }
void fast_io() { cin.tie(0); ios::sync_with_stdio(false); }
bool in_rect(int x, int y, int w, int h) { return 0 <= x && x < w && 0 <= y && y < h; }

typedef long long ll;
typedef pair<int, int> pint;

const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };


bool check(int w, int h, int m, const vector<string>& c)
{
    bool stop[64][64];
    clr(stop, 0);
    int mine = 0, cc = 0;
    int sx = -1, sy;
    rep(y, h) rep(x, w)
    {
        if (c[y][x] == 'c')
        {
            sx = x, sy = y;
            ++cc;
        }
        else if (c[y][x] == '*')
        {
            ++mine;

            for (int dy = -1; dy <= 1; ++dy)
            {
                for (int dx = -1; dx <= 1; ++dx)
                {
                    int tx = x + dx, ty = y + dy;
                    if (in_rect(tx, ty, w, h))
                        stop[ty][tx] = true;
                }
            }
        }
    }
    assert(mine == m);
    assert(cc == 1);

    bool visit[64][64];
    clr(visit, 0);
    queue<pint> q;
    q.push(pint(sx, sy));
    visit[sy][sx] = true;
    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        q.pop();
        if (stop[y][x])
            continue;

        for (int dy = -1; dy <= 1; ++dy)
        {
            for (int dx = -1; dx <= 1; ++dx)
            {
                int tx = x + dx, ty = y + dy;
                if ((dx != 0 || dy != 0)  && (in_rect(tx, ty, w, h) && c[ty][tx] != '*' && !visit[ty][tx]))
                {
                    visit[ty][tx] = true;
                    q.push(pint(tx, ty));
                }
            }
        }
    }

    rep(y, h) rep(x, w)
        if (c[y][x] != '*' && !visit[y][x])
            return false;
    return true;
}

char c[64][64];
bool by_dp(int w, int h, int m)
{
    if (w == 1)
    {
        clr(c, '.');
        rep(y, m)
            c[y][0] = '*';
        c[h - 1][0] = 'c';
        return true;
    }
    else if (m == w * h - 1)
    {
        rep(y, h) rep(x, w)
            c[y][x] = '*';
        c[0][0] = 'c';
        return true;
    }


    static int dp[55][3000][64];
    rep(y, h + 1) rep(used, m + 1) rep(u, w + 1)
        dp[y][used][u] = -1;
    dp[0][0][w] = 114514;
    rep(y, h) rep(used, m + 1) rep(u, w + 1)
    {
        if (dp[y][used][u] != -1)
        {
            rep(nu, u + 1)
                if (nu != w - 1 && (y != h - 1 || nu == u))
                    dp[y + 1][used + nu][nu] = u;
        }
    }

    int su = -1;
    rep(u, w + 1)
        if (dp[h][m][u] != -1)
            su = u;
    if (su == -1)
        return false;

    clr(c, '.');
    for (int y = h, used = m, u = su; y > 0; )
    {
        rep(x, u)
            c[y - 1][x] = '*';

        int pu = dp[y][used][u];
        used -= u;
        u = pu;
        --y;
    }
    c[h - 1][w - 1] = 'c';

    return true;
}
bool tete(int w, int h, int m)
{
    if (m == w * h - 1)
        return true;
    rep(mask, 1 << (w * h))
    {
        if (__builtin_popcount(mask) == m)
        {
            vector<string> c(h, string(w, '.'));
            rep(y, h) rep(x, w)
                if (mask >> (y * w + x) & 1)
                    c[y][x] = '*';

            int cx = -1, cy;
            rep(y, h) rep(x, w)
            {
                bool ok = true;
                for (int dy = -1; dy <= 1; ++dy)
                {
                    for (int dx = -1; dx <= 1; ++dx)
                    {
                        int tx = x + dx, ty = y + dy;
                        if (in_rect(tx, ty, w, h) && c[ty][tx] == '*')
                            ok = false;
                    }
                }
                if (ok)
                {
                    cx = x, cy = y;
                }
            }
            if (cx == -1)
                continue;

            c[cy][cx] = 'c';

            if (check(w, h, m, c))
            {
                return true;
                for (string& s : c)
                    cout << s << endl;
                cout << endl;
            }
        }
    }
    return false;
}
void test()
{
    for (int h = 1; h <= 5; ++h)
    {
        for (int w = 1; w <= 5; ++w)
        {
            rep(m, w * h)
            {
                printf("%d %d %d\n", w, h, m);
                assert((by_dp(w, h, m) || by_dp(h, w, m)) == tete(w, h, m));
            }
        }
    }
}
int main()
{
    int T;
    cin >> T;
    for (int C = 1; C <= T; ++C)
    {
        printf("Case #%d:\n", C);

        int h, w, m;
        cin >> h >> w >> m;

        vector<string> res;
        if (by_dp(w, h, m))
        {
            res = vector<string>(h, string(w, '@'));
            rep(y, h) rep(x, w)
                res[y][x] = c[y][x];
        }
        else if (by_dp(h, w, m))
        {
            res = vector<string>(h, string(w, '@'));
            rep(y, h) rep(x, w)
                res[y][x] = c[x][y];
        }

        if (res.empty())
            cout << "Impossible" << endl;
        else
        {
            for (string& s : res)
                cout << s << endl;

            assert(check(w, h, m, res));
        }
    }
}

