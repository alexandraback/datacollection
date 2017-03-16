#include <cstdio>
#include <queue>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define LL long long
#define pii pair <int, int>
#define piii pair <pii, int>
#define xx first
#define yy second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson ls, l, m
#define rson rs, m + 1, r
#define psi pair <string, int>
using namespace std;

const int N = 1005;
int vis[N], nx[N], mx[N];

int dfs (int u, int start) {
    if (u == start) return 1;
    if (vis[u]) return 0;
    vis[u] = 1;
    int tmp = dfs (nx[u], start);
//    if (tmp = dfs (nx[u], start)) return
    if (tmp) return tmp + 1;
    return 0;
}

pii dfs2 (int u, int fa) {
    if (vis[u]) {
        if (nx[u] == fa) return pii (u, 0);
        return pii (0, 0);
    }
    vis[u] = 1;
    pii tmp = dfs2 (nx[u], u);
    if (tmp.xx) return pii (tmp.xx, tmp.yy + 1);
    return tmp;
}

//void dfs3 (int u, int start) {
//    is[u] = 1;
//    if (u == start) return;
//    dfs3 (nx[u], start);
////    is[u] = 1;
//}
//
//int dfs4 (int u) {
//    if (is[u]) return 1;
//    return dfs (nx[u]) + 1;
//}

int main () {
    freopen ("in.txt", "r", stdin);
    freopen ("out.txt", "w", stdout);
    int T, cas = 1;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
//        cout << n << endl;
//        for (int i = 1; i <= n; i++) g[i].clear();
        for (int i = 1; i <= n; i++) {
            scanf ("%d", &nx[i]);
//            nx[i] = x;
        }
        int res = 0;
//        for (int i = 1; i <= n; i++) {
//
//        }
        for (int i = 1; i <= n; i++) {
            memset (vis, 0, sizeof vis);
            vis[i] = 1;
            int tmp = dfs (nx[i], i);
//            if (tmp) {
//                dfs3 (nx[i], i);
//            }
            res = max (res, tmp);
//            memset (vis, 0, sizeof vis);
//            vis[i] = 1;
//            cout << i << ' ' << dfs (nx[i], i) << endl;
        }
//        memset (mx, 0, sizeof mx);
        for (int i = 1; i <= n; i++) mx[i] = 1;
        for (int i = 1; i <= n; i++) {
            memset (vis, 0, sizeof vis);
            vis[i] = 1;
            pii tmp = dfs2 (nx[i], i);
            if (tmp.xx) mx[tmp.xx] = max (mx[tmp.xx], tmp.yy);
            memset (vis, 0, sizeof vis);
            vis[i] = 1;
            tmp = dfs2 (nx[i], i);
//            cout << i << ' ' << tmp.xx << ' ' << tmp.yy << endl;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (nx[nx[i]] == i && i < nx[i]) {
//                cnt++;
                cnt += mx[i] + mx[nx[i]];
//                res = max (res, mx[i] + mx[nx[i]]);
            }
        }
        res = max (res, cnt);
        printf ("Case #%d: %d\n", cas++, res);
//        cout << res << endl;
    }
}
