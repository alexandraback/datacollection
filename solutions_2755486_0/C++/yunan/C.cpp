#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

struct nod{
    int d, s, t, str;
} q[1000005];
int tot = 0;
int p[2000006];

struct tre{
    int dat, small;
}f[4000006];

int cmp(nod a, nod b){
    return a.d < b.d;
}

int push_down(int k) {
    if (f[k * 2].dat < f[k].dat) f[k * 2].dat = f[k].dat;
    if (f[k * 2 + 1].dat < f[k].dat) f[k * 2 + 1].dat = f[k].dat;
    f[k * 2].small = max(f[k * 2].small, f[k * 2].dat);
    f[k * 2 + 1].small = max(f[k * 2 + 1].small, f[k * 2 + 1].dat);
}

int ins(int k, int l, int r, int lc, int rc, int t){
    if (lc <= l && r <= rc) {
        f[k].dat = max(f[k].dat, t);
        f[k].small = max(f[k].small, f[k].dat);
        return 0;
    }
    push_down(k);
    if ((l + r) / 2 >= lc) ins(k * 2, l, (l + r) / 2, lc, rc,t);
    if ((l + r) / 2 < rc) ins(k * 2 + 1, (l + r) / 2 + 1, r, lc, rc, t);
    f[k].small = min(f[k * 2].small, f[k * 2 + 1].small);
    return 0;
}
int s;
int get(int k, int l, int r, int lc, int rc) {
    if (lc <= l && r <= rc) {
        s = min(s, f[k].small);
        return 0;
    }
    push_down(k);
    if ((l + r) / 2 >= lc) get(k * 2, l, (l + r) / 2, lc, rc);
    if ((l + r) / 2 < rc) get(k * 2 + 1, (l + r) / 2 + 1, r, lc, rc);
    return 0;
}

int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    int d, nn, w, e,  dd, dp, ds, n;
    int ans; 
    for (int tt = 1; tt <= t; ++tt) {
        memset(f,0, sizeof(f));
        scanf("%d", &n);
        tot = 0; ans = 0; 
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d%d%d%d%d%d%d", &d, &nn, &w, &e, &s, &dd, &dp, &ds);
            e = e - 1;
            for (int j = 1; j <= nn; ++j) {
                ++tot;
                q[tot].d = d; q[tot].s = w, q[tot].t = e; q[tot].str = s;
                p[tot * 3 - 3] = w, p[tot * 3 - 2] = e; p[tot * 3 - 1] = (w + e) / 2;
                d = d + dd; w = w + dp; e = e + dp; s = s + ds;
            }
        }
        sort(p, p + tot * 3);
        nn = unique(p, p + tot * 3) - p;
        for (int i = 1; i <= tot; ++i) {
            q[i].s = lower_bound(p, p + nn, q[i].s) - p;
            q[i].t = lower_bound(p, p + nn, q[i].t) - p;
        }
        sort(q + 1, q + tot + 1, cmp);
        for (int i = 1; i <= tot;) {
            int j = i;
            while (j <= tot && (q[j].d == q[i].d)) {
                s = 1000000000;
                get(1, 0, nn, q[j].s, q[j].t);
                if (s < q[j].str) ++ans;
                ++j;
            }
            j = i;
            while (j <= tot && (q[j].d == q[i].d)) {
                s = ins(1, 0, nn, q[j].s, q[j].t, q[j].str);
                ++j;
            }
            i = j;
        }
        //for small
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
