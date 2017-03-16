#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <utility>
#include <cassert>
#include <numeric>
#include <sstream>
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

vi dx = {0, 1, -1, 0, 0};
vi dy = {0, 0, 0, 1, -1};

struct Point
{
    int x, y;
};

const int NMAX = 200;
int used[NMAX][NMAX];
int itUs;

bool intersects(const Point& p, const vector<Point>& pts)
{
    return used[100 + p.x][100 + p.y] == itUs;
}

vector<Point> build(int n, int mask)
{
    ++itUs;
    vector<Point> pts;
    forn(i, n) {
        Point q = {0, 20};
        int turn = (mask >> i) & 1;
        while (true) {
            if (q.y == 0) break;
            q.y--;
            if (!intersects(q, pts)) continue;
            q.y++;
            if (turn) {
                q.x++;
                if (!intersects(q, pts)) continue;
                q.x -= 2;
                if (!intersects(q, pts)) continue;
                q.x++;
                break;
            } else {
                q.x--;
                if (!intersects(q, pts)) continue;
                q.x += 2;
                if (!intersects(q, pts)) continue;
                q.x--;
                break;
            }
        }
        pts.pb(q);
        forv(j, dx) {
            int x = dx[j] + q.x;
            int y = dy[j] + q.y;
            used[100 + x][100 + y] = itUs;
        }
    }
    return pts;
}

vector<Point> tPts;
vi ns;
vector<ld> anss;

bool covers(const Point& p, const vector<Point>& ps)
{
    for (const auto& q : ps) {
        if (p.x == q.x && p.y == q.y) return true;
    }
    return false;
}

void solve()
{
    anss.resize(ns.size());
    set<int> rns(all(ns));
    for (int n : rns) {
        cerr << n << endl;
        vi ids;
        forv(i, ns) if (ns[i] == n) ids.pb(i);
        forn(mask, 1 << n) {
            vector<Point> ps = build(n, mask);
            forv(j, ids) {
                if (covers(tPts[ids[j]], ps)) {
                    anss[ids[j]] += 1.0 / (1 << n);
                }
            }
        }
    }
}


void solveAll()
{
    int tc; cin >> tc;
    forn(it, tc) {
        Point p;
        int n; cin >> n;
        cin >> p.x >> p.y;
        tPts.pb(p);
        ns.pb(n);
    }
    solve();
    cout.precision(10);
    cout << fixed;
    forn(it, tc) {
        cout << "Case #" << it + 1 << ": " << anss[it] << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    solveAll();
    return 0;
}
