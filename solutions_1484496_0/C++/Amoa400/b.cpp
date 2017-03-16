#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

int n;
int a[511];
int ex[2000111];

void output( int s ) {
    // cout<<s <<endl;
     
     int i = 0;
     while ( s>0 ) {
           if ( s%2==1 ) {
                 printf( "%d", a[i] );
                 if ( s!=1 ) printf( " " );
                 }
           s /= 2;
           i++;
     }
     printf("\n");
}

bool dfs( int p, int s, int v ) {
    //cout << p << " " << s << " " << v << endl;
     if ( v!=0 ) {
          if ( ex[v]>0 && ex[v]!=s ) {
               output( s );
               //system( "pause" );
               output( ex[v] );
               return true;
          }
          ex[v] = s;
     }
     
     if ( p==n ) return false;
     
     if ( dfs( p+1, s, v ) ) return true;
     if ( dfs( p+1, s+(1<<p), v+a[p] ) ) return true;
     return false;
}

int main() {
    freopen( "b.in", "r", stdin );
    freopen( "b.out", "w", stdout );
    
    int T;
    scanf( "%d", &T );
    for ( int test=1; test<=T; test++ ) {
        printf( "Case #%d:\n", test );
        
        memset( ex, 0, sizeof(ex) );
        int sum = 0;
        scanf( "%d", &n );
        for ( int i=0; i<n; i++ ) scanf( "%d", &a[i] );
        
        if ( !dfs( 0, 0, 0 ) ) cout <<"Impossible"<<endl;
    }

    return 0;
}
