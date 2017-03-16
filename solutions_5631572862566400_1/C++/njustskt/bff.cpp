/*************************************************************************
	> File Name: bff.cpp
	> Author: skt
	> Mail: sktsxy@gmail.com
	> Created Time: 2016年04月16日 星期六 10时04分13秒
 ************************************************************************/

#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <complex>
#include <cassert>
// #pragma comment(linker,"/STACK:102400000,102400000")
using namespace std;
#define LL long long
#define pb push_back
#define mp make_pair
#define x first
#define y second
template <typename T> inline void checkMax(T &a, T b) {a = a>b?a:b;}
template <typename T> inline void checkMin(T &a, T b) {a = a<b?a:b;}
typedef pair<int, int> PII;
typedef vector<int> vi;
const double PI = acos(-1.0);
const double eps = 1e-8;
const int N = 1000 + 5;
int T, Cas = 1, n, bff[N];

bool check[N], add[N], vis[N];

struct Edge {
    int v, next;
} p[N << 1];

int head[N], cnt;

void init() {
    memset(head, -1, sizeof(head));
    cnt = 0;
}

void addEdge(int u, int v) {
    p[cnt].v = v;
    p[cnt].next = head[u];
    head[u] = cnt ++;
}

bool dfs(int u, int &cnt, int pre) {
    vis[u] = true;
    cnt ++;
    if (vis[bff[u]]) {
        if (bff[u] == pre) {
            return true;
        } else {
            return false;
        }
    }
    return dfs(bff[u], cnt, pre);
}

int dfs(int u, int c) {
    vis[u] = true;
    int cnt = 1;
    int deep = 0;
    for (int i = head[u]; i != -1; i = p[i].next) {
        int v = p[i].v;
        if (!vis[v] && v != c) {
            int temp = dfs(v, c);
            deep = max(deep, temp);
        }
    }
    return deep + cnt;
}


void work() {
    printf("Case #%d: ", Cas ++);
    scanf("%d", &n);
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &bff[i]);
    }
    memset(check, 0, sizeof(check));
    for (int i = 1; i <= n; i ++) {
        if (bff[bff[i]] == i) {
            check[bff[i]] = check[i] = true;
        }
    }
    memset(add, 0, sizeof(add));
    init();
    for (int i = 1; i <= n; i ++) {
        if (add[i]) continue;
        if (check[i]) {
            int fa = bff[i];
            if (fa < i) {
                addEdge(fa, i);
            } else {
                addEdge(i, fa);
            }
        } else {
            addEdge(bff[i], i);
            addEdge(i, bff[i]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i ++) {
        memset(vis, 0, sizeof(vis));
        int now = 0;
        if (dfs(i, now, i)) {
            ans = max(ans, now);
        }
    }
    int now = 0;
    memset(vis, 0, sizeof(vis));
    for (int i = 1; i <= n; i ++) {
        if (vis[i]) continue;
        if (check[i]) {
            int pnt = dfs(i, bff[i]);
            now += pnt;
        }
    }
    ans = max(ans, now);
    cout << ans << endl;
}
int main() {
    scanf("%d", &T);
    while (T --) {
        work();
    }
    return 0;
}
