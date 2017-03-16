

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;

struct g_type {
       int y,next;
};

const int maxn = 10111;
int a[maxn],sum[maxn],tot[maxn],first[maxn],fa[maxn];
int n,g_tot,root;
g_type g[maxn];

void add( int x, int y ) {
     g_tot++;
     g[g_tot].y = y;
     g[g_tot].next = first[x];
     first[x] = g_tot;
}

void readdata() {
     memset( a, 0, sizeof( a ) );
     memset( fa, 0, sizeof( fa ) );
     memset( first, 0, sizeof( first ) );
     memset( sum, 0, sizeof( sum ) );
     memset( tot, 0, sizeof( tot ) );
     g_tot = 0;
     for ( int i=1; i<=n; i++ ) {
         int x;
         scanf( "%d", &x );
         scanf( "%d", &a[x] );
         int tot;
         scanf( "%d", &tot );
         for ( int j=1; j<=tot; j++ ) {
             int y;
             scanf( "%d", &y );
             add( x, y );
             fa[y] = x;
         }
     }
     for ( int i=1; i<=n; i++ )
     if ( fa[i]==0 ) root = i;
}

int dp( int x ) {
     int ans = 0;
     sum[x] = a[x];
     tot[x] = 1;
     for ( int t=first[x]; t!=0; t=g[t].next ) {
         int tmp = dp( g[t].y );
         sum[x] += sum[g[t].y];
         tot[x] += tot[g[t].y];
         ans += abs( tmp );
     }
     ans += abs( sum[x]-tot[x] );
     return ans;
}

int main() {
    freopen( "b.in", "r", stdin );
    freopen( "b.out", "w", stdout );
    while ( true ) {
          scanf( "%d", &n );
          if ( n==0 ) break;
          readdata();
          cout << dp( root ) << endl;
    }
    return 0;
}
