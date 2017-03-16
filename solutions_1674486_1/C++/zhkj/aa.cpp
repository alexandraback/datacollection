#include <cstdio>
#include <algorithm>
#include <string.h>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

const int MAXN = 1010;

int c[MAXN][MAXN];

struct Node{
    int v;
    int next;
}g[MAXN * MAXN];

int cnt = 0, L[MAXN + MAXN];

void addedge(int u, int v){
    g[cnt].v = v;
    g[cnt].next = L[u];
    L[u] = cnt++;
}

int d[MAXN + MAXN];
int q[MAXN + MAXN];
bool vis[MAXN + MAXN];

void bfs(int st, int n){
    int head = 0, tail = -1;
    memset(d, 0, sizeof(d));
    memset(vis, false, sizeof(vis));
    q[++tail] = st;
    d[st] = 1;
    vis[st] = true;
    while (head <= tail){
        int temp = q[head++];
        for (int i = L[temp]; i != -1; i = g[i].next){
            d[g[i].v] += d[temp];
            if (!vis[g[i].v]){
                q[++tail] = g[i].v;
                vis[g[i].v] = true;
            }
        }
    }
    for (int i = 1; i <= n; i++){
        c[st][i] = d[i];
    }
}

int main(){
    int t, n, m, x;
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i++){
        scanf("%d", &n);
        memset(c, 0, sizeof(c));
        memset(L, -1, sizeof(L));

        cnt = 0;
        for (int j = 1; j <= n; j++){
            scanf("%d", &m);
            for (int k = 1; k <= m; k++){
                scanf("%d", &x);
                addedge(j, x);
            }
        }
        for (int j = 1; j <= n; j++){
            bfs(j, n);
        }
        printf("Case #%d: ", i);
        bool find = false;
        for (int j = 1; j <= n; j++){
            for (int k = 1; k <= n; k++){
                if (c[j][k] > 1){
                    printf("Yes\n");
                    find = true;
                    break;
                }
            }
            if (find) break;
        }
        if (!find) printf("No\n");
    }
    return 0;
}
