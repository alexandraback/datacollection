/*
Author: LotK
LANG: C++
*/

#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct BT {
    int type;
    long long v;   // v value , amount
}a[103], b[103];
long long max;

int n, m;
long long table[103][103];

long long findMax(long long a, long long b, long long c, long long d) {
    if(a<b) a=b;
    if(a<c) a=c;
    if(a<d) a=d;
    return a;
}

long long solB(int,int);
long long solA(int x, int y) {
    while(b[y].type != a[x].type && y<m) y++;
    if(y>=m) return 0;

    long long d = 0;
    if(a[x].v > b[y].v) {
        a[x].v -= b[y].v;
        d += b[y].v;
        long long tmp = table[x+1][y+1];
        long long tmp2 = solA(x, y+1);
        if(tmp<tmp2) tmp = tmp2;
        d += tmp;
        a[x].v += b[y].v;
    }
    else if(a[x].v < b[y].v) {
        b[y].v -= a[x].v;
        d += a[x].v;
        long long tmp = table[x+1][y+1];
        long long tmp2 = solB(x+1, y);
        if(tmp<tmp2) tmp = tmp2;
        d += tmp;

        b[y].v += a[x].v;
    }
    else {
        d += a[x].v + table[x+1][y+1];
    }
    return d;
}
long long solB(int x, int y) {
    while(b[y].type != a[x].type && x<n) x++;
    if(x>=n) return 0;

    long long d = 0;
    if(a[x].v > b[y].v) {
        a[x].v -= b[y].v;
        d += b[y].v;
        long long tmp = table[x+1][y+1];
        long long tmp2 = solA(x, y+1);
        if(tmp<tmp2) tmp = tmp2;
        d += tmp;

        a[x].v += b[y].v;
    }
    else if(a[x].v < b[y].v) {
        b[y].v -= a[x].v;
        d += a[x].v;
        long long tmp = table[x+1][y+1];
        long long tmp2 = solB(x+1, y);
        if(tmp<tmp2) tmp = tmp2;
        d += tmp;

        b[y].v += a[x].v;
    }
    else {
        d += a[x].v + table[x+1][y+1];
    }
    return d;
}
long long sol(int x, int y) {
    if(x>=n || y>=m) return 0ll;

    if(table[x+1][y] == 0) {
        table[x+1][y] = sol(x+1, y);
    }
    if(table[x][y+1] == 0) {
        table[x][y+1] = sol(x, y+1);
    }


    long long d = 0;

    if(a[x].type == b[y].type) {
        if(a[x].v > b[y].v) {
            a[x].v -= b[y].v;
            d += b[y].v;
            long long tmp = table[x+1][y+1];
            long long tmp2 = solA(x, y+1);
            if(tmp<tmp2) tmp = tmp2;
            d += tmp;
            a[x].v += b[y].v;
        }
        else if(a[x].v < b[y].v) {
            b[y].v -= a[x].v;
            d += a[x].v;
            long long tmp = table[x+1][y+1];
            long long tmp2 = solB(x, y+1);
            if(tmp<tmp2) tmp = tmp2;
            d += tmp;

            b[y].v += a[x].v;
        }
        else {
            d += a[x].v + table[x+1][y+1];
        }
    }
    table[x][y] = findMax(table[x+1][y], table[x][y+1], table[x+1][y+1], d);
    return table[x][y];
}
int main() {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C-small-attempt0.out", "w", stdout);

    int t, tt, i, j;
    scanf("%d", &tt);
    for(t=0 ; t<tt ; t++) {
        scanf("%d%d", &n, &m);
        for(i=0 ; i<n ; i++) {
            scanf("%lld%d", &a[i].v, &a[i].type);
        }
        for(i=0 ; i<m ; i++) {
            scanf("%lld%d", &b[i].v, &b[i].type);
        }
        for(i=0 ; i<=n+2 ; i++) {
            for(j=0 ; j<=m+2 ; j++) {
                table[i][j] = 0ll;
            }
        }



        sol(0, 0);
        /*
        for(i=0 ; i<n ; i++) {
            for(j=0 ; j<m ; j++) {
                printf("%d ", table[i][j]);
            }
            printf("\n");
        }*/
        printf("Case #%d: %lld\n", t+1, table[0][0]);
    }

}
