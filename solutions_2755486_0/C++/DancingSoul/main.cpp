#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
struct Pnode{
    int d, s, l, r;
} p[10000];
int cas, CAS, n, d, cnt, w, e, s, dd, dp, ds, i, j, ans, num;
int h[100000], th[100000];
int cmp(Pnode a, Pnode b){return a.d < b.d;}
int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &CAS);
    for (cas = 1; cas <= CAS; cas++){
        scanf("%d", &n);
        num = ans = 0;
        for (i = 1; i <= n; i++){
            scanf("%d%d%d%d%d%d%d%d", &d, &cnt, &w, &e, &s, &dd, &dp, &ds);
            for (j = 0; j < cnt; j++){
                p[++num].d = d + dd * j;
                p[num].s = s + ds * j;
                p[num].l = (w + dp * j) * 2 + 1 + 50000;
                p[num].r = (e + dp * j) * 2 - 1 + 50000;
            }
        }
        memset(h, 0, sizeof(h));
        memset(th, 0, sizeof(th));
        sort(p + 1, p + num + 1, cmp);
        p[0] = p[1];
        for (i = 1; i <= num; i++){
            if (p[i].d != p[i - 1].d) memcpy(h, th, sizeof(th));
            int ok = 0;
            for (j = p[i].l; j <= p[i].r; j++){
                if (p[i].s > h[j]) ok = 1;
                th[j] = max(th[j], p[i].s);
            }
            ans += ok;
        }
        printf("Case #%d: %d\n", cas, ans);

    }

}
