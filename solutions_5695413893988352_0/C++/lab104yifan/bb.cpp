#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int T;
char a[105], b[105];
int len;
int Min, ax, ay;

void dfs(int u, int x, int y, int d) {
    if (u == len) {
        d = abs(d);
        if (Min > d) {
            Min = d;
            ax = x; ay = y;
        } else if (Min == d) {
            if (x < ax) {
                ax = x;
                ay = y;
            } else if (x == ax) {
                if (y < ay) ay = y;
            }
        }
        return;
    }
    int d1 = 0, u1 = 9;
    if (a[u] != '?') d1 = u1 = a[u] - '0';
    int d2 = 0, u2 = 9;
    if (b[u] != '?') d2 = u2 = b[u] - '0';
    for (int i = d1; i <= u1; i++){
        for (int j = d2; j <= u2; j++) {
            dfs(u + 1, x * 10 + i, y * 10 + j, d * 10 + (i - j));
        }
    }
}

int ans[2][10];

int main() {
freopen("B-small-attempt0.in", "r", stdin);
freopen("B-small-attempt0.out", "w", stdout);
    int cas = 0;
    scanf("%d", &T);
    while (T--) {
        Min = INF;
        scanf("%s%s", a, b);
        len = strlen(a);
        dfs(0, 0, 0, 0);
        int an = 0;
        memset(ans, 0, sizeof(ans));
        while (ax) {
            ans[0][an++] = ax % 10;
            ax /= 10;
        }
        an = 0;
        while (ay) {
            ans[1][an++] = ay % 10;
            ay /= 10;
        }
        printf("Case #%d: ", ++cas);
        for (int i = len - 1; i >= 0; i--) printf("%d", ans[0][i]); printf(" ");
        for (int i = len - 1; i >= 0; i--) printf("%d", ans[1][i]); printf("\n");
    }
    return 0;
}
