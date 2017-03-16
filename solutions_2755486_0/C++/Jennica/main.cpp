#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef struct S {
    int d, w, e, s;
} NODE;
NODE node[210];

bool cmp(NODE a, NODE b) {
    return a.d < b.d;
}

int tot;
int h[2][810];

int main() {
    freopen("CCC.in","r",stdin);
    freopen("CCC.out","w",stdout);
    int T, N, i, t, j, cnt;
    int d, n, w, e, s, dd, dp, ds;
    scanf("%d", &T);
    for (t = 1; t <= T; ++t) {
        scanf("%d", &N);
        tot = 0;
        cnt = 0;
        for (i = 0; i < N; ++i) {
            scanf("%d%d%d%d%d%d%d%d", &d, &n, &w, &e, &s, &dd, &dp, &ds);
            w += 200, e += 200;
            w <<= 1;
            e <<= 1;
            dp <<= 1;
            for (j = 0; j < n; ++j) {
                node[tot].d = d;
                d += dd;
                node[tot].s = s;
                s += ds;
                node[tot].w = w;
                w += dp;
                node[tot].e = e;
                e += dp;
                ++tot;
            }
        }
        sort(node, node + tot, cmp);
        memset(h, 0, sizeof (h));
        int ok;
        for (i = 0; i < tot; ++i) {
          //  printf("%d: %d %d %d %d\n", i, node[i].d, node[i].w, node[i].e, node[i].s);
            ok = 0;
            for (j = node[i].w; j <= node[i].e; ++j) {

                if (h[0][j] < node[i].s) {
                    ok = 1;
                    h[1][j] = max(h[1][j], node[i].s);
                }
            }

            cnt += ok;
            if (i + 1 < tot && node[i + 1].d == node[i].d)
                continue;
            for (j = 0; j <= 800; ++j)
                h[0][j] = h[1][j];
        }
        printf("Case #%d: %d\n", t, cnt);
    }
    return 0;
}
