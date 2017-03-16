#include <stdio.h>
int main () {
        int t;
        scanf ( "%d", &t );
        int i;
        for ( i = 1; i <= t; i++ ) {
                int n;
                scanf ( "%d", &n );
                int j;
                int a[100][100]={0},m,k,c[100],l,flag = 0;
                for ( j = 1; j <= n; j++ ) {
                        scanf ( "%d",&c[i] );
                        for ( k = 1; k <= c[i]; k++ ) {
                                scanf ("%d", &m );
                                a[j][m] = 1;
                        }
                }
                for ( j = 1; j <= n; j++ ) {
                        for ( k = 1; k <= n; k++){
                                for ( l = 1; l <= n; l++ ) {
                                        if ( a[j][k] != 0 && a[k][l] != 0 ) 
                                                a[j][l]++;
                                }
                        }
                }
                for ( j = 1; j <= n; j++ ){
                        for ( k = 1; k<= n; k++ ) {
                                if ( a[j][k] >= 2 ) {
                                        flag = 1;
                                        break;
                                }
                        }
                        if ( flag == 1)
                        break;
                }
                if ( flag == 1)
                printf ( "Case #%d: Yes\n",i);
                else 
                printf ( "Case #%d: No\n",i);
        }
        return 0;
} 