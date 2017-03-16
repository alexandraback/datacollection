#pragma comment(linker, "/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cassert>
#include <cstdio>
#include <ctime>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <algorithm>
#include <stack>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(v) v.begin(), v.end()

#define forn(i, n) for (int i = 0; i < (int)(n); i++)
#define for1(i, n) for (int i = 1; i <= (int)(n); i++)
#define forv(i, v) forn(i, v.size())

typedef pair<int, int> pii;
typedef long long ll;

const double EPS = 1e-10;
const double INF = 1e9;

#define NMAX 105

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

struct Point
{
    int x, y;
    Point() {};
    Point(int x, int y) : x(x), y(y) {};
};

int f[NMAX][NMAX], c[NMAX][NMAX];
int h0;
int n, m;
double d[NMAX][NMAX];
bool used[NMAX][NMAX];

struct cmp
{
    bool operator()(const Point& p1, const Point& p2) const
    {
        if (fabs(d[p1.x][p1.y] - d[p2.x][p2.y]) > EPS) return d[p1.x][p1.y] < d[p2.x][p2.y];
        if (p1.x != p2.x) return p1.x < p2.x;
        return p1.y < p2.y;
    }
};

bool valid(int x, int y)
{
    return (x >= 0) && (x < n) && (y >= 0) && (y < m);
}

set<Point, cmp> heap;

bool can(int x1, int y1, int x2, int y2, double h)
{
    if (f[x2][y2] > c[x2][y2] - 50) return false;
    if (f[x2][y2] > c[x1][y1] - 50) return false;
    if (f[x1][y1] > c[x2][y2] - 50) return false;
    if (c[x2][y2] < 50) return false;

    return h < c[x2][y2] - 50 + EPS;
}

double calc_time(int x1, int y1, int x2, int y2, double h)
{
    if (!can(x1, y1, x2, y2, 0.0)) return INF;

    double ret = 0;

    if (!can(x1, y1, x2, y2, h))
    {
        ret += (h - c[x2][y2] + 50) / 10.0;
        h = c[x2][y2] - 50;
    }

    assert(can(x1, y1, x2, y2, h));

    if (h - f[x1][y1] > 20 - EPS) ret += 1.0; else ret += 10.0;

    return ret;
}

void solve(int tc)
{
    cerr << tc << endl;
    printf("Case #%d: ", tc);
    cin >> h0 >> n >> m;
    forn(i, n)
    {
        forn(j, m) cin >> c[i][j];
    }

    forn(i, n)
    {
        forn(j, m) cin >> f[i][j];
    }

    memset(used, 0, sizeof(used));

    used[0][0] = true;
    queue<Point> q;
    q.push(Point(0, 0));

    while (!q.empty())
    {
        Point u = q.front(), v;
        q.pop();

        forn(i, 4)
        {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];

            if (!valid(v.x, v.y)) continue;
            if (used[v.x][v.y]) continue;

            if (can(u.x, u.y, v.x, v.y, h0))
            {
                used[v.x][v.y] = true;
                q.push(v);    
            }
        }
    }

    if (used[n - 1][m - 1])
    {
        cout << 0 << endl;
        return;
    }

    forn(i, n)
    {
        forn(j, m)
        {
            if (used[i][j]) d[i][j] = 0; else d[i][j] = INF;
        }
    }

    memset(used, 0, sizeof(used));

    heap.clear();

    forn(i, n)
    {
        forn(j, m)
        {
            heap.insert(Point(i, j));
        }
    }

    while (!heap.empty())
    {
        Point u = *heap.begin(), v;
        heap.erase(u);

        if (d[u.x][u.y] > INF / 2) break;

        used[u.x][u.y] = true;

        forn(i, 4)
        {
            v.x = u.x + dx[i];
            v.y = u.y + dy[i];

            if (!valid(v.x, v.y)) continue;
            if (used[v.x][v.y]) continue;

            double t = calc_time(u.x, u.y, v.x, v.y, max(0.0, h0 - 10 * d[u.x][u.y])) + d[u.x][u.y];

            if (d[v.x][v.y] > t)
            {
                heap.erase(v);
                d[v.x][v.y] = t;
                heap.insert(v);
            }
        }
    }

    printf("%.9lf\n", d[n - 1][m - 1]);
}

int main()
{
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
    int tc;
    cin >> tc;
    forn(it, tc) solve(it + 1);
    return 0;
}
