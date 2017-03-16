#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

using namespace std;

struct node {
    int s, l, p;
} a[2010];

int t, n;
int vis[1010];

bool cmp(const node &x, const node &y) {
    return x.s == y.s ? x.l > y.l : x.s < y.s;
}

bool check(int t) {
    int gs2 = 0, star = 0;
    memset(vis, 0, sizeof(vis));
    while (gs2 < n) {
        int p = star ;
        for (int i = 0; i < n * 2; i ++ )
            if (a[i].l == 2 && star >= a[i].s) {
                if (vis[a[i].p] < 2) {
                    star += (2 - vis[a[i].p]);
                    vis[a[i].p] = 2;
                    gs2 ++ ;
                    break;
                }
            }
        if (p != star) continue;
        for (int i = 0; i < n * 2; i ++ )
            if (a[i].l == 1 && star >= a[i].s) {
                if (vis[a[i].p] < 1) {
                    if (t == 0) return false;
                    star ++ ;
                    vis[a[i].p] = 1;
                    t -- ;
                    break;
                }
            }
        if (star == p) return false;
    }
    return true;
}

int main() {
    freopen("B-small-attempt5.in", "r", stdin);
    freopen("b1.out", "w", stdout);
    scanf("%d", &t);
    for (int i = 1; i <= t; i ++ ) {
        scanf("%d", &n);
        for (int j = 0; j < n; j ++ ) {
            scanf("%d%d", &a[j].s, &a[j + n].s);
            a[j].l = 1;
            a[j + n].l = 2;
            a[j].p = a[j + n].p = j;
        }
        //sort(a, a + (2 * n), cmp);
        if (! check(n)) {
            printf("Case #%d: Too Bad\n", i);
            continue;
        }
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r) / 2;
            if (check(mid)) r = mid;
            else l = mid + 1;
        }
        printf("Case #%d: %d\n", i, l + n);
    }
    return 0;
}
