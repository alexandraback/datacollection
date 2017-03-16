#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <valarray>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": "  << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template<class T>
class IsIterable__ {static void f(...); template<class U> static typename U::const_iterator f(const U&);
public:const static bool value = !std::is_same<void, decltype(f(std::declval<T>()))>::value;};

template <class F, class S> ostream& operator << (ostream& o, const pair<F,S>& p) {
return o << "(" << p.first << ", " << p.second << ")";}

template<class C>void O__(ostream& o, const C& c) {
bool f = 1; for(const auto& x: c) {if (!f) o << ", "; if (IsIterable__<decltype(x)>::value) o << "\n"; f = 0; o << x;}}

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {o << "[";O__(o, v);o << "]";return o;}

template <class T, class V>
ostream& operator << (ostream& o, const map<T, V>& v) {o << "{";O__(o, v);o << "}"; return o;}

template <class T>
ostream& operator << (ostream& o, const set<T>& v) {o << "{";O__(o, v);o << "}";return o;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

#if GCC_VERSION > 40900
// supports find_by_order(int) and order_of_key(Key)
template<class Key, class Value>
using MapWithOrderStatistics = tree<Key, Value,
      std::less<Key>, rb_tree_tag /*splay_tree_tag*/,
      tree_order_statistics_node_update>;
#endif

typedef vector<vector<bool>> P;
set<P> pieces;
set<P> was;
vector<P> piecesVector;
vector<int> used;

int c(const P& p) {
    int t = 0;
    for (auto & x : p)
        for (auto y: x) {
            if (y)
                ++t;
        }
    return t;
}

void go(P& p, int n) {
    if (was.count(p)) {
        return;
    }
    was.insert(p);
    if (c(p) == n) {
        pieces.insert(p);
        return;
    }
    for (int i = 0; i < p.size(); ++i)
        for (int j = 0; j < p.size(); ++j) {
            if (!p[i][j])
                continue;
            for (int dx = -1; dx <= +1; ++dx) {
                for (int dy = -1; dy <= +1; ++dy) {
                    if ((dx == 0) ^ (dy == 0)) {
                        int ni = i + dx;
                        int nj = j + dy;
                        if (ni < 0 || nj < 0 || ni == p.size() || nj == p.size())
                            continue;
                        if (!p[ni][nj]) {
                            p[ni][nj] = 1;
                            go(p, n);
                            p[ni][nj] = 0;
                        }
                    }
                }
            }
        }
}

void ref(P& p) {
    while(std::count(all(p.front()), true) == 0) {
        p.erase(p.begin());
    }
    while(std::count(all(p.back()), true) == 0) {
        p.erase(std::prev(p.end()));
    }
    int r = 0;
    while(r < p[0].size()) {
        bool ok = 1;
        for (const auto& x: p){
            ok = ok && (x[r] == false);
        }
        if (ok)
            ++r;
        else
            break;
    }
    for (auto& x: p){
        x.erase(x.begin(), x.begin() + r);
    }
    r = (int)p[0].size() - 1;
    while(r >= 0) {
        bool ok = 1;
        for (const auto& x: p){
            ok = ok && (x[r] == false);
        }
        if (ok)
            --r;
        else
            break;
    }
    for (auto& x: p){
        x.erase(x.begin()+r+1, x.end());
    }

}

void print(P p) {
    ref(p);
    for (const auto& x: p) {
        for (bool y: x) {
            cerr << (y? '#':'.');
        }
        cerr << "\n";
    }
}

bool possible(const vector<string>& plan, int order) {
    vector<int> area;
    int c = 0;
    const int n = (int)plan.size();
    const int m = (int)plan[0].size();
    vector<bool> was(n*m);
    for (int i = 0; i < n*m; ++i) {
        if (was[i])
            continue;
        if (plan[i % n][i / n] == '#')
            continue;
        was[i] = 1;
        area.push_back(0);
        queue<int> Q;
        Q.push(i);
        while(!Q.empty()) {
            int v = Q.front();
            int x = v % n;
            int y = v / n;
            Q.pop();
            area[c] += 1;
            //debug(x);
            //debug(y);
            for (int dx = -1; dx <= +1; ++dx) {
                for (int dy = -1; dy <= +1; ++dy) {
                    if ((dx == 0) ^ (dy == 0)) {
                        int nx = x + dx;
                        int ny = y + dy;
                        if (nx < 0 || ny < 0 || nx == n || ny == m ||
                                plan[nx][ny] == '#' ||
                                was[nx + n * ny])
                            continue;
                        was[nx + n * ny] = 1;
                        Q.push(nx + n * ny);
                    }
                }
            }
        }
        ++c;
    }
    //debug(area);
    for (int x: area) {
        if (x % order != 0)
            return false;
    }
    return true;
}

bool can(vector<string>& plan, int order) {
    if (!possible(plan, order)) {
        return false;
    }
    int x,y;
    x=y=0;
    for (x = 0; x < plan.size(); ++x)
        for (y = 0; y < plan[x].size(); ++y)
            if (plan[x][y] == '.')
                break;
    //debug(x);
    //debug(y);
    //debug(plan);
    if (x == plan.size())
        return true;

    for (int i = 0; i < piecesVector.size(); ++i) {
        int X = (int)piecesVector[i].size();
        int Y = (int)piecesVector[i][0].size();
        if (x + X - 1 < plan.size() && y + Y - 1 < plan[0].size()) {
            bool ok = 1;
            for (int a = 0; ok && a < X; ++a)
                for (int b = 0; ok && b < Y; ++b) {
                    if (piecesVector[i][a][b] && plan[x+a][y+b] == '#') {
                        ok = 0;
                    }
                }
            if (ok) {
                used[i] += 1;
                for (int a = 0; a < X; ++a)
                    for (int b = 0; b < Y; ++b) {
                        if (piecesVector[i][a][b]) {
                            plan[x+a][y+b] = '#';
                        }
                    }
                if (can(plan, order)) {
                    return true;
                }
                used[i] -= 1;
                for (int a = 0; a < X; ++a)
                    for (int b = 0; b < Y; ++b) {
                        if (piecesVector[i][a][b]) {
                            plan[x+a][y+b] = '.';
                        }
                    }
            }
        }

    }
    return false;
}

P rot(const P& p) {
    P pr(p[0].size(), vector<bool>(p.size()));
    for (size_t i = 0; i < p.size(); ++i)
        for (size_t j = 0; j < p[0].size(); ++j)
            pr[j][p.size() - 1 - i] = p[i][j];
    return pr;
}

P transpose(const P& p) {
    P pt(p[0].size(), vector<bool>(p.size()));
    for (size_t i = 0; i < p.size(); ++i)
        for (size_t j = 0; j < p[0].size(); ++j)
            pt[j][i] = p[i][j];
    return pt;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    int tests;
    cin >> tests;
    for (int id =0; id < tests; ++id) {
        was.clear();
        pieces.clear();

        cout << "Case #"<<id+1<<": ";

    int n;
    cin >> n;
    P i(n+1+n, vector<bool>(n+n+1));
    i[n][n]=1;
    go(i, n);
    {
        auto pieces2 = pieces;
        pieces.clear();
        for (auto p: pieces2) {
            ref(p);
            pieces.insert(p);
        }
    }
    for (auto x: pieces) {
        print(x);
        cerr << "-\n";
    }
    debug(pieces.size());
    piecesVector.assign(all(pieces));
    used.assign(pieces.size(), 0);

    int m;
    cin >> n >> m;

    vii al(pieces.size());
    for (int i = 0; i <  piecesVector.size(); ++i) {
        P p = piecesVector[i];
        for (int t = 0;t < 2; ++t){
            p = transpose(p);
            for (int r = 0; r < 4; ++r) {
                p = rot(p);
                al[i].push_back(int(find(all(piecesVector), p) - piecesVector.begin()));
            }
        }
        assert(al[i].size() == 8);
    }

    for (int i = 0; i < piecesVector.size(); ++i) {
        if (used[i])
            continue;
        debug(i);
        bool ok = 0;
        vector<string> plan(n, string(m, '.'));
        int it = 0;
        do {
            int X = (int)piecesVector[i].size();
            int Y = (int)piecesVector[i][0].size();
            if (X > (int)plan.size() ||
                    Y > (int)plan[0].size())
                break;

            ++it;
            plan.assign(n, string(m , '.'));
            int x = rand() % int(plan.size() - X + 1);
            int y = rand() % int(plan[0].size() - Y + 1);

            for (int a = 0; a < X; ++a) {
                for (int b = 0; b < Y; ++b) {
                    if (piecesVector[i][a][b]) {
                        plan[x+a][y+b] = '#';
                    }
                }
            }
            //debug(plan);
            ok = can(plan, c(piecesVector[i]));
        } while(!ok && it < 3 * n * m);
        if (ok) {
            for (int j: al[i])
                used[j] += 1;
        }
    }
    cout << (count(all(used), 0) ? "RICHARD" : "GABRIEL") << "\n";
    cerr << (count(all(used), 0) ? "can not" : "can") << "\n";
    }

    return 0;
}
