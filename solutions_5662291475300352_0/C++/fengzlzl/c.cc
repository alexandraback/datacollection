#include <cstdio>

const double eps = 1e-9;

struct Hicker {
    int d, h, m;
} a[10];

bool Catch(int x, int y) {//speed : x < y
    if (a[x].m >= a[y].m) return false;
    double delta = a[x].d - a[y].d;
    if (delta < 0) delta += 360.0;
    double t1 = delta / (a[y].m - a[x].m);
    if (a[x].d > a[y].d) {
        if (a[x].d + t1 * a[x].m >= 360) return 0;
        double t2 = 360.0 / (a[y].m - a[x].m);
        if (a[x].d + (t1 + t2) * a[x].m >= 360) return 0;
        return 1;
    } else {
        if (a[x].d + t1 * a[x].m >= 360) return 0;
        return 1;
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d%d", &a[i].d, &a[i].h, &a[i].m);
        }
        printf("Case #%d: ", cas);
        if (n == 2 && (Catch(0, 1) || Catch(1, 0))) puts("1");
        else puts("0");
    }
    return 0;
}
