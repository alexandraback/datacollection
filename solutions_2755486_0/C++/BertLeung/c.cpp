#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tribe
{
    int d, n, w, e, s, dd, dp, ds;
};

int wall[2][1500];
tribe list[15];

/*
0 -> 2
0.5 -> 1.5
1 -> 3

2 -> 5
2.5 -> 4.5
5 -> 9

0 1 2 3 4 5
 0 1 2 3 4 5
*/

int main()
{
    int e, w;
    int cur, pre;
    int nd = 0;
    int aa, nn, n, i, ed, ans, td, j, k;
    scanf("%d", &nn);
    for ( aa = 1; aa <= nn; aa++ ) {
        scanf("%d", &n);
        nd = 0x7fffffff;
        memset(wall, 0, sizeof(wall));
        for (i = 0; i < n; i++ ) {
            scanf("%d %d %d %d %d %d %d %d", &list[i].d,
                                            &list[i].n,
                                            &list[i].e,
                                            &list[i].w,
                                            &list[i].s,
                                            &list[i].dd,
                                            &list[i].dp,
                                            &list[i].ds);
            nd = (nd < list[i].d)? nd : list[i].d;
            list[i].e += 500;
            list[i].w += 500;
        }
        ans = 0;
        cur = 1; pre = 0;
        while (1) {
            for (ed = 1, i = 0; ed && i < n; i++ ) {
                if (list[i].n) ed = 0;
            }
            if (ed) break;
            pre = cur;
            cur = (1-cur);
            memcpy(&wall[cur][0], &wall[pre][0], sizeof(int)*1500);
            for ( i = 0; i < n; i++ ) {
                if (list[i].d != nd || list[i].n == 0) continue;
                e = list[i].e * 2 + 1;
                w = list[i].w * 2 - 1 ;
                for (j = e; j <= w; j++ ) {
                    if (wall[pre][j] < list[i].s) {
                        ans++;
                        break;
                    }
                }
                for (j = e; j <= w; j++ ) {
                    wall[cur][j] = (wall[cur][j] < list[i].s)? list[i].s : wall[cur][j];
                }
                list[i].s += list[i].ds;
                list[i].e += list[i].dp; list[i].w += list[i].dp;
                list[i].d += list[i].dd;
                list[i].n--;
            }
            td = 0x7fffffff;
            for ( i = 0; i < n; i++ ) {
                if (list[i].n) {
                    td = (td < list[i].d)? td : list[i].d;
                }
            }
            nd = td;
        }
        printf("Case #%d: %d\n", aa, ans);
    }
    return 0;
}

