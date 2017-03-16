#include <set>
#include <map>
#include <ctime>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define sz size
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define inf 1000000007

using namespace std;

bool vis[10010];
int A, B, C, w, d[50], a[50], flg[10010], tot;
struct epoch { int a, b, c; } b[50];

void dfs(int st, int las) {
    for (int l = las; l <= tot; ++ l) {
        int i = b[l].a, j = b[l].b, k = b[l].c;
        if (vis[i * 100 + j * 10 + k] && flg[i * 100 + j * 10] < w && flg[i * 100 + k] < w && flg[j * 10 + k] < w)
            {
                vis[i * 100 + j * 10 + k] = false;
                ++ flg[i * 100 + j * 10], ++ flg[i * 100 + k], ++ flg[j * 10 + k];
                a[st] = l;
                dfs(st + 1, l + 1);
                vis[i * 100 + j * 10 + k] = true;
                -- flg[i * 100 + j * 10], -- flg[i * 100 + k], -- flg[j * 10 + k];
            }
    }
    if (st - 1 > d[0]) {
        d[0] = st - 1;
        for (int i = 1; i <= d[0]; ++ i) d[i] = a[i];
    }
}

void solve() {
    d[0] = 0;
    memset(vis, true, sizeof(vis));
    memset(flg, 0, sizeof(flg));
    tot = 0;
    for (int i = 1; i <= A; ++ i)
        for (int j = 1; j <= B; ++ j)
            for (int k = 1; k <= C; ++ k) {
                ++ tot;
                b[tot].a = i, b[tot].b = j, b[tot].c = k;
            }
    dfs(1, 1);
    printf("%d\n", d[0]);
    for (int i = 1; i <= d[0]; ++ i) 
        printf("%d %d %d\n", b[d[i]].a, b[d[i]].b, b[d[i]].c);
}

int main() {
    freopen("test.in", "r", stdin);
    freopen("test.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++ t) {
        scanf("%d%d%d%d", &A, &B, &C, &w);
        printf("Case #%d: ", t);
        solve();
    }
    return 0;
}