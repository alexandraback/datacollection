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
const int N = 60;
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

void printAns(bool yes = false)
{
    if (yes) {
        forn(i, r) {
            forn(j, c) cout << a[i][j];
            cout << endl;
        }
    } else {
        cout << "Impossible" << endl;
    }
}

void solveTest()
{
    cin >> r >> c >> m;
    if (r * c - 1 == m) {
        forn(i, r) forn(j, c) a[i][j] = '*';
        a[0][0] = 'c';
        printAns(true);
        return;
    }
    forn(i, r) forn(j, c) a[i][j] = '.';
    if (r == 1) {
        forn(i, m) a[0][i] = '*';
        a[0][c - 1] = 'c';
        printAns(true);
        return;
    }
    if (c == 1) {
        forn(i, m) a[i][0] = '*';
        a[r - 1][0] = 'c';
        printAns(true);
        return;
    }
    forn(i, r - 2) {
        if (!m) break;
        forn(j, c - 2) {
            if (!m) break;
            --m;
            a[i][j] = '*';
        }
    }
    if (m > 0 && m % 2 == 1 && r > 2 && c > 2) {
        a[r - 3][c - 3] = '.';
        ++m;
    }
    if (m % 2 == 1) {
        printAns(false);
        return;
    }
    forn(i, r - 3) {
        if (!m) break;
        a[i][c - 2] = a[i][c - 1] = '*';
        m -= 2;
    }
    forn(j, c - 3) {
        if (!m) break;
        a[r - 1][j] = a[r - 2][j] = '*';
        m -= 2;
    }
    if (r > 2 && c > 2 && a[r - 3][c - 3] == '*') {
        a[r - 3][c - 3] = '.';
        ++m;
    }
    if (r == 2 || c == 2) {
        m += 3;
        if (r * c == 4) m += 2;
    }
    if (m == 2 || m == 4 || m == 6 || m == 7) {
        printAns(false);
        return;
    }
    forn(i, 3) {
        if (!m) break;
        if (r - 3 >= 0 && c - 3 + i >= 0) {
            a[r - 3][c - 3 + i] = '*';
        }
        --m;
    }
    forn(i, 2) {
        if (!m) break;
        if (r - 2 + i >= 0 && c - 3 >= 0)
            a[r - 2 + i][c - 3] = '*';
        --m;
    }
    if (m > 0) {
        assert(m == 3);
        a[r - 2][c - 2] = '*';
        a[r - 2][c - 1] = '*';
        a[r - 1][c - 2] = '*';
        m -= 3;
    }
    assert(m == 0);
    a[r - 1][c - 1] = 'c';
    printAns(true);
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
