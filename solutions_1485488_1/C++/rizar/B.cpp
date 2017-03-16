#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <cstring>
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <complex>
#include <ctime>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <queue>
#include <iterator>

typedef long long LL;
typedef long double LD;

using namespace std;

const int DI [] = {1, -1, 0, 0};
const int DJ [] = {0, 0, 1, -1};

const int INF = (int)1e9;
const int START = (int)1e6;

enum {COME, CHANGE};

enum {FAST = 10, SLOW = 100};

struct Event {
    int t, type;

    int u, d, cost;

    Event(int t_, int type_, int u_, int d_ = -1, int cost_ = -1)
        : t(t_), type(type_), u(u_), d(d_), cost(cost_)
    {
    }
    
    bool operator< (Event o) const {
        if (t != o.t)
            return t > o.t;
        if (type != o.type)
            return type > o.type;
        return cost > o.cost;
    }
};
ostream& operator<< (ostream& ostr, Event e) {
    ostr << e.t << ' ' << e.type << ' ' << e.u << ' ' << e.d << ' ' << e.cost;
    return ostr;
}

const int MAX_N = 110;

int h, n, m;
vector< pair<int, int> > g [MAX_N * MAX_N];
int ans [MAX_N * MAX_N];
int top [MAX_N][MAX_N], bottom [MAX_N][MAX_N];

int number(int i, int j) {
    return i * m + j;
}

int main() {
#ifndef LOCAL
//  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

    int nTests;
    cin >> nTests;
    for (int test = 1; test <= nTests; test++) {
        cin >> h >> n >> m;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                cin >> top[i][j];
                ans[number(i, j)] = INF;
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> bottom[i][j];

        priority_queue<Event> es;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int u = number(i, j);
                g[u].resize(4);

                for (int d = 0; d < 4; d++) {
                    int ci = i + DI[d];
                    int cj = j + DJ[d];
                    g[u][d] = make_pair(number(ci, cj), -1);

                    if (ci < 0 || cj < 0 || ci >= n || cj >= m)
                        continue;
                    if (top[ci][cj] - bottom[i][j] < 50 
                        || top[ci][cj] - bottom[ci][cj] < 50 
                        || top[i][j] - bottom[ci][cj] < 50)
                        continue;

                    int t1 = 50 - (top[ci][cj] - h);
                    if (t1 < 0)
                        t1 = 0;
                    if (t1 > 0)
                        t1 += START;

                    int t2 = h - bottom[i][j] - 20;
                    if (t2 < 0)
                        t2 = 0;
                    if (t2 > 0)
                        t2 += START;
                    t2 = max(t2, t1);
#ifdef DEBUG
                    // cerr << "t1 " << t1 << " t2 " << t2 << '\n';
#endif

                    if (h - bottom[i][j] >= 20 
                        && top[ci][cj] - bottom[i][j] >= 70)
                        es.push(Event(t1, CHANGE, u, d, FAST));
                    es.push(Event(t2, CHANGE, u, d, SLOW));
                }
            }

        es.push(Event(0, COME, 0));

        while (!es.empty()) {
            Event e = es.top();
            es.pop();
#ifdef DEBUG
            cerr << "Event " << e << '\n';
#endif
            
            if (e.type == CHANGE) {
                g[e.u][e.d].second = e.cost;
                
                if (ans[e.u] < INF) {
                    int v = g[e.u][e.d].first;
                    int w = g[e.u][e.d].second;
                    es.push(Event(e.t + w, COME, v));
                }
            }
            else {
                if (ans[e.u] < INF)
                    continue;
                ans[e.u] = e.t;

                for (int d = 0; d < 4; d++) {
                    int v = g[e.u][d].first;
                    int w = g[e.u][d].second;
                    if (w < 0)
                        continue;
                    es.push(Event(e.t + w, COME, v));
                }
            }
        }

        cout << "Case #" << test << ": "  << fixed << setprecision(1) << 0.1 * max(0, ans[n * m - 1] - START) << '\n';
    }

    return 0;
}


