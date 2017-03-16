#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cassert>
#include <cstring>
#include <cstdarg>
#include <cstdio>
#include <random>
#include <cmath>
#include <ctime>
#include <functional>
#include <algorithm>
#include <complex>
#include <numeric>
#include <limits>
#include <bitset>
#include <vector>
#include <string>
#include <queue>
#include <deque>
#include <array>
#include <list>
#include <map>
#include <set>
using namespace std;
#define ALL(a) (a).begin(), (a).end()
#define SZ(a) int((a).size())
#define MP(x, y) make_pair((x),(y))
#define FI first
#define SE second
#define LOWB(x) (x & (-x))
#define UNIQUE(a) sort(ALL(a)), (a).erase(unique(ALL(a)), (a).end())
#define HEIGHT(n) (sizeof(int) * 8 - __builtin_clz(n)) //height of range n segment tree
typedef long long llong;
typedef pair<int, int> pii;
typedef vector<int> vi;
template<class T> inline T min(T a, T b, T c) {return min(min(a,b),c);}
template<class T> inline T min(T a, T b, T c, T d) {return min(min(a,b),min(c,d));}
template<class T> inline T max(T a, T b, T c) {return max(max(a,b),c);}
template<class T> inline T max(T a, T b, T c, T d) {return max(max(a,b),max(c,d));}
const int INF = 1e9;
const llong INF_LL = 4e18;
const double pi = acos(-1.0);
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
/*-----------------------------------*/
#define N 2010
int nxt[N], n, idx[N];
bool inc[N];

bool mul(int a, int b) {
    if (nxt[a] == b && nxt[b] == a) return true;
    return false;
}

int find_cycle(int cur, int id) {
    idx[cur] = id;
    if (mul(cur, nxt[cur])) return 0;
    if (idx[nxt[cur]]) {
        return idx[cur] - idx[nxt[cur]] + 1;
    }
    int res = find_cycle(nxt[cur], id+1);
    if (res) inc[cur] = true;
    return res;
}

vector<int> g[N];
bool rid[N];

void add_edge(int u, int v) {
    g[u].push_back(v);
}

int dfs(int rt) {
    int res = 0;
    for (auto i: g[rt]) {
        int tmp = dfs(i);
        res = max(res, tmp+1);
    }
    return res;
}

int find_tree() {
    for (int i=1; i<=n; i++) g[i].clear();
    for (int i=1; i<=n; i++) if (!inc[i]) {
        if (!mul(nxt[i], i)) add_edge(nxt[i], i);
    }
    int res = 0;
    for (int i=1; i<=n; i++) if (!inc[i] && mul(i, nxt[i])) {
        inc[i] = true;
        inc[nxt[i]] = true;
        int tmp = dfs(i);
        int tmp2 = dfs(nxt[i]);
        res += tmp + tmp2 + 2;
    }
    return res;
}

int solve() {
    memset(idx, 0, sizeof(idx));
    memset(inc, false, sizeof(inc));
    int res = 0, cycle = 0;
    for (int i=1; i<=n; i++) {
        memset(idx, 0, sizeof(idx));
        int tmp = find_cycle(i, 1);
        cycle = max(cycle, tmp);
    }
    int cnt = find_tree();
    res = max(cnt, cycle);
    return res;
}

int main() {
    freopen("test.in", "r", stdin);
    int cas;
    cin >> cas;
    for (int i=1; i<=cas; i++) {
        cin >> n;
        for (int j=1; j<=n; j++) cin >> nxt[j];
        printf("Case #%d: %d\n", i, solve());
    }
    return 0;
}
