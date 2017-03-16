#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cassert>
#include <ctime>


using namespace std;

#ifdef WIN32
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

typedef long double ld;
typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<ll> vll;
typedef vector<vll> vvll;

ll rdtsc() {
    ll tmp;
    asm("rdtsc" : "=A"(tmp));
    return tmp;
}

inline int myrand() {
    return abs((rand() << 15) ^ rand());
}

inline int rnd(int x) {
    return myrand() % x;
}

#define TASKNAME "text"
#define pb push_back
#define mp make_pair
#define EPS (1e-9)
#define INF ((int)1e9)
#define sqr(x) ((x) * (x))         
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define sz(x) ((int)(x).size())


const int maxn = 50 + 10;

int n;

int maxu;
int used[maxn];
int go[maxn][maxn];

int col[maxn];

int vals[maxn];


void countGot(int v) {
    if (col[v] == 2)
        return;
    used[v] = maxu;
    for (int u = 0; u < n; ++u) {
        if (used[u] == maxu)
            continue;
        if (!go[v][u])
            continue;
        countGot(u);
    }
}

int start;

bool ok() {
    assert(start != -1);
    ++maxu;
    countGot(start);
    for (int i = 0; i < n; ++i)
        if (used[i] != maxu && col[i] != 2)
            return false;
    return true;
}

int cnt;
int path[maxn];

int times;
void solve() {
    int ansLayer = -1, ansv = -1;
    for (int layer = cnt - 1; layer >= -1; --layer) {
        if (layer == -1 && count(col, col + n, 0) != n)
            continue;
        for (int v = 0; v < n; ++v) {
            if (col[v])
                continue;
            if (layer >= 0 && !go[path[layer]][v])
                continue;
            if (ansv == -1 || vals[v] < vals[ansv]) {
                ansv = v;
                ansLayer = layer;
            }
        }
        if (layer >= 0) {
            col[path[layer]] = 2;
            if (!ok())
                break;
        }
    }

    for (int i = 0; i < cnt; ++i)
        col[path[i]] = 1;

    while (cnt >= 0 && cnt > ansLayer + 1) {
        --cnt;
        col[path[cnt]] = 2;
    }

    if (ansv == -1)
        return;

    /*eprintf("cnt = %d\n", cnt);
    for (int i = 0; i < n; ++i)
        eprintf("%d%c", col[i], " \n"[i == n - 1]);
    eprintf("%d %d\n", ansLayer, ansv);
    */
    if (ansLayer == -1)
        start = ansv;
    printf("%d", vals[ansv]);
    ++times;
    col[ansv] = 1;
    path[cnt++] = ansv;
    solve();
}

bool solve(int testCase) {
    printf("Case #%d: ", testCase);
    int m;
    if (scanf("%d%d", &n, &m) < 2)
        return 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            go[i][j] = 0;
    for (int i = 0; i < n; ++i)
        scanf("%d", &vals[i]);
    for (int i = 0; i < m; ++i) {
        int s, t;
        scanf("%d%d", &s, &t);
        --s, --t;
        go[s][t] = go[t][s] = 1;
    }

    for (int i = 0; i < n; ++i)
        used[i] = 0, col[i] = 0;
    maxu = 0;


    cnt = 0;

    start = -1;
    times = 0;
    solve();
    assert(times == n);
    printf("\n");
    return 1;
}

int main() {
    srand(rdtsc());
#ifdef DEBUG
    freopen(TASKNAME".in", "r", stdin);
    freopen(TASKNAME".out", "w", stdout);
#endif
    
    int maxt;
    while (scanf("%d", &maxt) == 1) {
        for (int t = 0; t < maxt; ++t)
            assert(solve(t + 1));
        
        #ifdef DEBUG
            eprintf("%.18lf\n", (double)clock() / CLOCKS_PER_SEC);
        #endif
    }
    return 0;
}
