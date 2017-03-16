/*
 * Author: tender
 * Created Time:  2012/5/6 17:28:42
 * File Name: a.cpp
 */
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <set>

using namespace std;
const double pi = acos(-1.0);
const int maxn = 1000;
int g[maxn + 2][maxn + 2], g1[maxn + 2][maxn + 2], num[maxn + 5], dp[maxn + 5];
int tt[maxn + 5];
bool vis[maxn + 5];
void dfs(const int &u) {
    vis[u] = true;
    for (int i = 0; i < num[u]; i++) {
        int v = g[u][i];
        dp[v] += dp[u];
        if (vis[v] == false) dfs(v);
    }
}
void dfs1(const int &u) {
    vis[u] = true;
    for (int i = 0; i < tt[u]; i++) {
        int v = g1[u][i];
        dp[v] += dp[u];
        if (vis[v] == false) dfs1(v);
    }
}
bool in[maxn + 5];
bool solve(const int &n) {
    for (int i = 1; i <= n; i++) {
        //if (in[i] == false) {
            //printf("i = %d\n", i);
        memset(dp, 0, sizeof(int) * (n + 1));
        memset(vis, false, sizeof(vis[0]) * (n + 2));
        dp[i] = 1;
        dfs(i);
        //for (int j = 1; j <= n; j++)
            //printf("dp[%d] = %d\n", j, dp[j]);
        for (int j = 1; j <= n; j++)
            if (dp[j] >= 2) {
                memset(dp, 0, sizeof(int) * (n + 1));
                memset(vis, false, sizeof(vis[0]) * (n + 2));
                dp[j] = 1;
                //printf("j = %d\n", j);
                dfs1(j);
                //for (int t = 1; t <= n; t++)
                    //printf("dp[%d] = %d\n", t, dp[t]);
                if (dp[i] >= 2) return true;
                break;
            }
    }
    return false;
}
int main() {
    freopen("as1.in", "r", stdin);
    freopen("2.txt", "w", stdout);
    int cas;
    scanf("%d", &cas);
    for (int ii = 1; ii <= cas; ii++) {
        printf("Case #%d: ", ii);
        int n;
        scanf("%d", &n);
        memset(in, false, sizeof(in));
        memset(tt, 0, sizeof(tt));
        for (int i = 1; i <= n; i++) {
            scanf("%d", &num[i]);
            for (int j = 0; j < num[i]; j++) {
                int t;
                scanf("%d", &t);
                g[i][j] = t;
                in[t] = true;
                g1[t][tt[t]++] = i;
            }
        }
        if (solve(n)) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
