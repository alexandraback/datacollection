#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
#include <limits>
using namespace std;

#define REQUIRE(cond, message) \
    do { \
        if (!(cond)) { \
            std::cerr << message << std::endl; \
            assert(false); \
        } \
    } while (false)

#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define for1(i, n) for (int i = 1; i <= int(n); ++i)
#define forv(i, v) forn(i, (v).size())
#define pb push_back
#define mp make_pair
#define all(v) (v).begin(), (v).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long long ll;
typedef vector<ll> vl;
typedef pair<int, int> pii;
typedef vector<string> vs;
typedef long double ld;

template<typename T>
inline int popcount(T t) {
    if (std::numeric_limits<T>::digits <=
                            std::numeric_limits<unsigned int>::digits) {
        return __builtin_popcount(t);
    } else {
        return __builtin_popcountll(t);
    }
}

const ld EPS = 1e-8;
const ld PI = acosl(0.0) * 2;
const int N = 8;
int r, c;
int m;
char a[N][N];
bool found;

const int dx[] = {1, 1, 0, -1, -1, -1, 0, 1};
const int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

bool inside(int x, int y)
{
    return x >= 0 && y >= 0 && x < r && y < c;
}

int qx[N * N + 10];
int qy[N * N + 10];
int used[N][N];
int nu;

void revert()
{
    forn(i, r) forn(j, c) {
        if (a[i][j] != '*') a[i][j] = '.';
    }
}

bool check()
{
    forn(i, r) forn(j, c) {
        if (a[i][j] == '*') continue;
        char ch = '0';
        forn(k, 8) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y) && a[x][y] == '*') ++ch;
        }
        a[i][j] = ch;
    }
    int nz = 0, nnz = 0;
    int zx = -1, zy = -1;
    forn(i, r) forn(j, c) {
        bool f = false;
        if (a[i][j] == '*') continue;
        if (a[i][j] == '0') {
            zx = i;
            zy = j;
            ++nz;
            continue;
        } else {
            ++nnz;
        }
        forn(k, 8) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (inside(x, y) && a[x][y] == '0') {
                f = true;
                break;
            }
        }
        if (f) {
            --nnz;
        }
    }
    if (nz == 0) {
        if (nnz > 1) {
            revert();
            return false;
        }
        assert(nnz > 0);
        return true;
    }
    if (nnz > 0) {
        revert();
        return false;
    }
    int h = 0, t = 0;
    qx[t] = zx;
    qy[t++] = zy;
    ++nu;
    used[zx][zy] = nu;
    int cnt = 1;
    while (h < t) {
        int x = qx[h];
        int y = qy[h++];
        forn(i, 8) {
            int xx = x + dx[i];
            int yy = y + dy[i];
            if (inside(xx, yy) && a[xx][yy] == '0' && used[xx][yy] != nu) {
                used[xx][yy] = nu;
                qx[t] = xx;
                qy[t++] = yy;
                ++cnt;
            }
        }
    }
    if (cnt != nz) {
        revert();
        return false;
    }
    return true;
}

void rec(int x, int y, int m)
{
    if (found) return;
    if (y == c) {
        ++x;
        y = 0;
    }
    if (x == r) {
        if (m == 0 && check()) {
            found = true;
        }
        return;
    }
    rec(x, y + 1, m);
    if (found) return;
    if (m > 0) {
        a[x][y] = '*';
        rec(x, y + 1, m - 1);
        if (found) return;
        a[x][y] = '.';
    }
}

void solveTest()
{
    cin >> r >> c >> m;
    forn(i, r) forn(j, c) a[i][j] = '.';
    found = false;
    rec(0, 0, m);
    if (!found) cout << "Impossible" << endl;
    else {
        int sx = -1, sy = -1;
        forn(i, r) forn(j, c) {
            if (a[i][j] == '*') continue;
            assert(a[i][j] != '.');
            if (sx == -1 || a[sx][sy] > a[i][j]) {
                sx = i;
                sy = j;
            }
        }   
        assert(sx != -1);
        revert();
        a[sx][sy] = 'c';
        forn(i, r) {
            forn(j, c) {
                cout << a[i][j];
            }
            cout << endl;
        }
    }
}

void solve()
{
    int numTests; cin >> numTests;
    for1(testId, numTests) {
        cerr << testId << endl;
        cout << "Case #" << testId << ":" << endl;
        solveTest();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solve();
    return 0;
}
