#include <cstdio>
#include <cstring>
#include <iostream>

#define MAX 30

using namespace std;

int C, D, V, ans, d[105], v[105];


void renew() {
    int j;
    for ( j = V ; j >= 0 ; j -- ) {
        if ( v[j] == 1 ) v[j+d[D+ans]] = 1;
    }
}


int main () {

    int t, T, i, j;
    scanf("%d",&T);

    for ( t = 1 ; t <= T ; t ++ ) {

        ans = 0;

        scanf("%d %d %d",&C,&D,&V);

        for ( i = 0 ; i < D ; i ++ ) {
            scanf("%d",&d[i]);
        }

        memset(v,0,sizeof(v)); v[0] = 1;


        for ( i = 0 ; i < D ; i ++ ) {
            for ( j = V ; j >= 0 ; j -- ) {
                if ( v[j] == 1 ) v[j+d[i]] = 1;
            }
        }

        /*for ( i = 0 ; i <= V ; i ++ ) {
            printf("%d ",v[i]);
        }*/

        while ( true ) {

            for ( i = 0 ; i <= V ; i ++ ) {
                if ( v[i] == 0 ) {
                    d[D+ans] = i;
                    break;
                }
            }
            if ( i == V+1 ) break;
            renew();
            ans ++;

        }



        printf("Case #%d: %d\n",t,ans);
    }

    return 0;

}
