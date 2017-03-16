#include <algorithm>
#include <cstdio>
using namespace std;

const int N = 1000;
int a[N], b[N];
int res, n;

void go(int c, int s, int r)
{
    if (c+s >= res) return;
    if (!s) res = c;
    for (int i = 0; i < n; ++i) {
        if (0 <= b[i] && b[i] <= r) {
            b[i] = ~b[i];
            go(c+1, s-1, r+(0<=a[i]?2:1));
            b[i] = ~b[i];
            continue;
        }
        if (0 <= a[i] && a[i] <= r && 0 <= b[i]) {
            a[i] = ~a[i];
            go(c+1, s, r+1);
            a[i] = ~a[i];
        }
    }
}

int main()
{
    int T;
    scanf("%d\n", &T);
    for (int tt = 1; tt <= T; ++tt) {
        bool bad = true;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &a[i], &b[i]);
        }
        res = 3*n;
        go(0, n, 0);
        printf("Case #%d: ", tt);
        if (res == 3*n) puts("Too Bad");
        else printf("%d\n", res);
    }
}
