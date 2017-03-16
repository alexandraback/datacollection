#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;

int n;
vector<int> map[1005];
bool in[1005];
bool vis[1005];

bool dfs(int x) {
    if (vis[x]) return 1;
    vis[x] = 1;
    int i;
    for (i = 0; i < (int)map[x].size(); i++) {
        int to = map[x][i];
        if (dfs(to)) return 1;
    }
    return 0;
}

bool f() {
    int i;
    for (i = 1; i <= n; i++) {
        if (in[i]) {
            memset(vis, 0, sizeof(vis));
            if (dfs(i)) return 1;
        }
    }
    return 0;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int x, y, i, j, icase, tt = 0;
    scanf("%d", &icase);
    while (icase--) {
        for (i = 1; i <= n; i++) in[i] = 1;
        scanf("%d", &n);
        for (i = 1; i <= n; i++) map[i].clear();
        for (i = 1; i <= n; i++) {
            scanf("%d", &x);
            for (j = 0; j < x; j++) {
                scanf("%d", &y);
                map[i].push_back(y);
                in[y] = 0;
            }
        }
        printf("Case #%d: %s\n", ++tt, f() ? "Yes" : "No");
    }
    return 0;
}
