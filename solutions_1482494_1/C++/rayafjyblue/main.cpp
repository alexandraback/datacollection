#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define INF 9999

using namespace std;

int n, a[1005], b[1005];
bool vis[1005][2];
int res;

int main() {
    freopen("B-large.in", "r", stdin);
    freopen("B-large.out", "w", stdout);
    int icase, tt = 0, i;
    scanf("%d", &icase);
    while (icase--) {
        res = -1;
        scanf("%d", &n);
        for (i = 0; i < n; i++) scanf("%d%d", &a[i], &b[i]);
        printf("Case #%d: ", ++tt);
        int score = 0, step = 0;
        memset(vis, 0, sizeof(vis));
        while (1) {
            bool flag = 0;
            for (i = 0; i < n; i++) {
                if (!vis[i][1] && score >= b[i]) {
                    flag = 1;
                    vis[i][1] = 1;
                    if (vis[i][0]) score++;
                    else score += 2;
                    step++;
                }
            }
            for (i = 0; i < n; i++) if (!vis[i][1]) break;
            if (i == n) {
                res = step;
                break;
            }
            if (!flag) {
                int id = -1, maxx = -1;
                for (i = 0; i < n; i++)
                    if (!vis[i][0] && !vis[i][1] && score >= a[i] && maxx < b[i]) maxx = b[i], id = i;
                if (id != -1) {
                    flag = 1;
                    vis[id][0] = 1;
                    score++;
                    step++;
                }
            }
            if (!flag) break;
        }
        if (res == -1) puts("Too Bad");
        else printf("%d\n", res);
    }
    return 0;
}
