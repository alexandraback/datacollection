#include <iostream>
#include <cstring>
#include <stdio.h>
#include <algorithm>
using namespace std;

#define MaxN 110

struct polje {
    int r,c,h;

    polje() {}
    polje( int _r, int _c, int _h ) {
        r = _r;
        c = _c;
        h = _h;
    }

    bool operator < ( const polje &other ) const {
        return h > other.h;
    }
};

int T;
int n,m;
int a[MaxN][MaxN];

polje h[MaxN*MaxN];
int ph;

bool sol;

int main()
{
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);

    scanf("%d",&T);
    for (int t = 0; t < T; ++t) {
        scanf("%d%d",&n,&m);

        sol = true;
        ph = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                scanf("%d",&a[i][j]);
                h[ ph++ ] = polje( i, j, a[i][j] );
            }

        for (int q = 0; q < ph; ++q) {
            polje p = h[q];

            bool ok = true;
            for (int j = 0; j < m; ++j) {
                if ( a[ p.r ][j] > p.h ) ok = false;
            }

            bool ok2 = true;
            for (int i = 0; i < n; ++i) {
                if ( a[i][ p.c ] > p.h ) ok2 = false;
            }

            if ( !ok && !ok2 ) {
                sol = false;
                break;
            }
        }

        printf("Case #%d: ",t+1);
        if ( !sol ) printf("NO\n");
        else       printf("YES\n");
    }

    return 0;
}
