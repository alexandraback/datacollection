#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int a[511];

int main() {
    freopen( "a.in", "r", stdin );
    freopen( "a.out", "w", stdout );
    
    int T;
    scanf( "%d", &T );
    for ( int test=1; test<=T; test++ ) {
        printf( "Case #%d:", test );
        
        int n;
        int sum = 0;
        scanf( "%d", &n );
        for ( int i=0; i<n; i++ ) {
            scanf( "%d", &a[i] );
            sum += a[i];
        }
        
        for ( int i=0; i<n; i++ ) {
            double l = 0,
                   r = 1;
            while ( l<r ) {
                  double m = (l+r)/2;
                  double p = 1-m;
                  double minv = a[i]+sum*m;
                  for ( int j=0; j<n; j++ ) 
                  if ( i!=j && a[j]<minv ) p -= (minv-a[j])/sum*1.0+10e-10;
                  if ( p>0 ) l = m+10e-10;
                  else r = m-10e-10;
            }
            printf( " %.6lf", l*100 );
        }
        printf( "\n" );
    }

    return 0;
}
