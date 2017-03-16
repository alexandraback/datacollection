#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
double ans;
int n, x, y;
bool f[100][100];
const int dx = 50;
int h = 100;

void dfs(int l, double p, int cx, int cy) {
    if (l == 0) {
        if (x + dx >= 0 && x + dx < h && y >= 0 && y < h)
            if (f[x + dx][y]) ans += p;
        return;
    }
    if (cy == 0 || f[cx + dx - 1][cy - 1] && f[cx + dx + 1][cy - 1]) {
        f[cx + dx][cy] = 1;
        dfs(l - 1, p, 0, h);
        f[cx + dx][cy] = 0;
    } else {
        if (cy == 1) {
            if (f[cx + dx - 1][cy - 1] == 1 && f[cx + dx + 1][cy - 1] == 0) dfs(l, p, cx + 1, cy - 1);
            if (f[cx + dx - 1][cy - 1] == 0 && f[cx + dx + 1][cy - 1] == 1) dfs(l, p, cx - 1, cy - 1);
            if (f[cx + dx - 1][cy - 1] == 0 && f[cx + dx + 1][cy - 1] == 0) {
                dfs(l, p / 2, cx - 1, cy - 1);
                dfs(l, p / 2, cx + 1, cy - 1);
            }
        } else if (f[cx + dx][cy - 2] == 0) dfs(l, p, cx, cy - 2);
        else {
            if (f[cx + dx - 1][cy - 1] == 1 && f[cx + dx + 1][cy - 1] == 0) dfs(l, p, cx + 1, cy - 1);
            if (f[cx + dx - 1][cy - 1] == 0 && f[cx + dx + 1][cy - 1] == 1) dfs(l, p, cx - 1, cy - 1);
            if (f[cx + dx - 1][cy - 1] == 0 && f[cx + dx + 1][cy - 1] == 0) {
                dfs(l, p / 2, cx - 1, cy - 1);
                dfs(l, p / 2, cx + 1, cy - 1);
            }
        }
    }
}

int main() {
    freopen("B-small-attempt1.in", "r", stdin);
    freopen("B-small-attempt1.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        scanf("%d%d%d", &n, &x, &y);
        ans = 0;
        memset(f, 0, sizeof (f));
        dfs(n, 1.0, 0, h);
        printf("Case #%d: %lf\n", cas, ans);
    }
    return 0;
}