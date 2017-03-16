#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cassert>
#if __cplusplus > 201103L
#include <initializer_list>
#include <unordered_map>
#include <unordered_set>
#endif

using namespace std;

#ifdef LOCAL
#define DEBUG
#endif

#define oo 0x3F3F3F3F
#define fst first
#define snd second
#define PB push_back
#define SZ(x) (int)((x).size())
#define ALL(x) (x).begin(), (x).end()
#define FOR(i, a, b) for (int _end_ = (b), i = (a); i <= _end_; ++i)
#define ROF(i, a, b) for (int _end_ = (b), i = (a); i >= _end_; --i)

typedef unsigned int uint;
typedef long long int64;
typedef unsigned long long uint64;
typedef long double real;

int64 fpm(int64 b, int64 e, int64 m) { int64 t = 1; for (; e; e >>= 1, b = b * b % m) e & 1 ? t = t * b % m : 0; return t; }
template<class T> inline bool chkmin(T &a, T b) {return a > b ? a = b, true : false;}
template<class T> inline bool chkmax(T &a, T b) {return a < b ? a = b, true : false;}
template<class T> inline T sqr(T x) {return x * x;}
template <typename T> T gcd(T x, T y) {for (T t; x; ) t = x, x = y % x, y = t; return y; }

template<class edge> struct Graph {
    vector<vector<edge> > adj;
    Graph(int n) {adj.clear(); adj.resize(n + 5);}
    Graph() {adj.clear(); }
    void resize(int n) {adj.resize(n + 5); }
    void add(int s, edge e){adj[s].push_back(e);}
    void del(int s, edge e) {adj[s].erase(find(iter(adj[s]), e)); }
    vector<edge>& operator [](int t) {return adj[t];}
};

const int N = 55;

int G[N][N], code[N], ans[N], o[N];
int n, m, dist[N], pre[N], bak[N];

bool cmp(int a, int b) {
    return code[a] < code[b];
}

void BFS(int x, bool b = 1) {
    queue<int> Q;
    memset(dist, 0x3F, sizeof(dist));
    Q.push(x), dist[x] = 0;
    for (; !Q.empty(); Q.pop()) {
        int x = Q.front();
        for (int v = 1; v <= n; ++v) {
            int w = G[x][v] == 2 || (G[x][v] == 1 && o[v]) ? 0 : G[x][v] == 1 ? 1 : oo;
            if (dist[v] > dist[x] + w) {
                if (b) pre[v] = x;
                dist[v] = dist[x] + w;
                Q.push(v);
            }
        }
    }
}

vector<int> get_candidate(int x) {
    vector<int> ret;
    BFS(x);
    for (int i = 1; i <= n; ++i)
        if (!o[i] && dist[i] == 1)
            ret.push_back(i);
    return ret;
}

bool check(int s, int x) {
    set<int> d;
    for (int t = x; t != s; t = pre[t])
        if (G[t][pre[t]] == 1) {
            G[t][pre[t]] = 2, G[pre[t]][t] = 0;
            d.insert(t);
        }
    BFS(x, 0);
    for (int t = x; t != s; t = pre[t])
        if (d.count(t))
            G[t][pre[t]] = 1, G[pre[t]][t] = 1;
    for (int i = 1; i <= n; ++i)
        if (!o[i] && dist[i] == oo)
            return false;
    return true;
}

void travel(int x, int y) {
    set<int> d;
    for (int t = y; t != x; t = pre[t])
        if (G[t][pre[t]] == 1) {
            G[t][pre[t]] = 2, G[pre[t]][t] = 0;
            d.insert(t);
        }
}

int main(int argc, char **argv) {
#ifdef LOCAL
    freopen("C-small-attempt1.in" , "r", stdin);
    freopen("C.out", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);

    int T;
    scanf("%d", &T);
    for (int tc = 1; tc <= T; ++tc) {
        scanf("%d%d", &n, &m);
        memset(G, 0, sizeof(G));
        for (int i = 1; i <= n; ++i)
            scanf("%d", &code[i]);
        for (int i = 1; i <= m; ++i) {
            int u, v;
            scanf("%d%d", &u, &v);
            G[u][v] = G[v][u] = 1;
        }
        
        memset(o, 0, sizeof(o));
        int S = min_element(code + 1, code + n + 1) - code;
        for (int cnt = 1, x = S; cnt <= n; ++cnt) {
            // fprintf(stderr, "cur: %d\n", x);
            assert(o[x] == false);
            ans[cnt] = x, o[x] = true;
            if (cnt == n) break;

            vector<int> candidate = get_candidate(x);
            sort(ALL(candidate), cmp);
            assert(SZ(candidate) > 0);
            for (int i = 0; i < SZ(candidate); ++i) {
                int v = candidate[i];
                if (check(x, v)) {
                    travel(x, v);
                    x = v;
                    break;
                }
                BFS(x);
            }
        }
        
        printf("Case #%d: ", tc);
        for (int i = 1; i <= n; ++i)
            printf("%05d", code[ans[i]]);
        puts("");
    }

    return 0; 
}
