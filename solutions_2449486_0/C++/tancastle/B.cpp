#include<cstdio>
#include<iostream>
#include<cstring>
#include<cmath>
#include<algorithm>

using namespace std;

int m, n;
int d[105][105];
int a[105], b[105], ma[105], mb[105];

bool setit(int *t, int *mt, int i, int v) {
    if(t[i] == -1) {
        //printf("%d %d %d\n", t[i], mt[i], v);
        if(v < mt[i]) return 0;
        t[i] = v;
        return 1;
    }
    if(t[i] != v) return 0;
    return 1;
}

int main()
{
    freopen("B.in", "r", stdin);
    freopen("B.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int kase=1; kase<=T; kase++) {
        scanf("%d%d", &n, &m);
        memset(a, 0xff, sizeof(a));
        memset(b, 0xff, sizeof(b));
        memset(ma, 0, sizeof(ma));
        memset(mb, 0, sizeof(mb));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                scanf("%d", &d[i][j]);
            }
        }

        printf("Case #%d: ", kase);

        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                ma[i] = max(ma[i], d[i][j]);
            }
        }
        for(int j=1; j<=m; j++) {
            for(int i=1; i<=n; i++) {
                mb[j] = max(mb[j], d[i][j]);
            }
        }

        //for(int i=1; i<=n; i++) printf("#%d\n", ma[i]);
        //for(int i=1; i<=m; i++) printf("#%d\n", mb[i]);

        bool flag;
        for(int i=1; i<=n; i++) {
            flag = 1;
            for(int j=1; j<=m; j++) {
                if(d[i][j] < ma[i]) {
                    flag = setit(b, mb, j, d[i][j]);
                    //printf("flag=%d\n", flag);
                    if(flag == 0) break;
                }
            }
            if(flag == 0) break;
        }
        if(flag == 0) {
            printf("NO\n");
            continue;
        }

        /*
        printf("a[]: ");
        for(int i=1; i<=n; i++) printf("%d ", a[i]);
        printf("\nb[]: ");
        for(int j=1; j<=m; j++) printf("%d ", b[j]);
        printf("\n");
        */

        for(int j=1; j<=m; j++) {
            flag = 1;
            for(int i=1; i<=n; i++) {
                if(d[i][j] < mb[j]) {
                    //printf("i=%d, j=%d\n", i, j);
                    flag = setit(a, ma, i, d[i][j]);
                    //printf("flag=%d\n", flag);
                    if(flag == 0) break;
                }
            }
            if(flag == 0) break;
        }
        if(flag == 0) {
            printf("NO\n");
            continue;
        }

        printf("YES\n");
    }
    return 0;
}
