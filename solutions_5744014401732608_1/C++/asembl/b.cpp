#include <cstdio>
#include <iostream>
using namespace std ;

int ans[100][100];

void work() {
    long long n,m;
    scanf("%lld%lld",&n,&m);

    for ( int i = 1 ; i <= n ; ++i )
        for ( int j = 1 ; j <= n ; ++j )
            ans[i][j] = 0 ;

    for ( int i = n-1 ; i ; --i )
        for ( int j = i-1 ; j ; --j )
            ans[i][j] = 1 ;

    for ( int i = n-1 ; i ; --i ) {
        long long c ;

        if ( i-2 >= 0 )
            c = 1LL<<(i-2);
        else
            c = 1;

        if ( m >= c ) {
            ans[n][i] = 1 ;
            m -= c;
        }
    }

    if ( m == 0 ) {
        printf("POSSIBLE\n");
        for ( int i = n ; i ; --i ) {
            for ( int j = n ; j ; --j )
                printf("%d",ans[i][j]);
            printf("\n");
        }
    }
    else {
        printf("IMPOSSIBLE\n");
    }
}
int main() {

    int T ;
    scanf("%d",&T);
    for ( int i = 0 ; i < T ; ++i ) {
        printf("Case #%d: ",i+1);
        work();
    }
    return 0;
}
