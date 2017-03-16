//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n = 16 , J = 50 ;

void init() {
  scanf( "%*d%*d" ) ;
}

int  isp( ll x ) {
  ll bd = ( sqrt( x ) + 1 ) ;
  for ( int i = 2 ; i <= bd ; i ++ ) if ( x % i == 0 ) return i ;
  return -1 ;
}

void process() {
  int bt[ 40 ] ;
  int tot = 0 ;
  int lft = J ;
  for ( int i = ( 1 << ( n - 1 ) ) + 1 ; i < ( 1 << n ) ; i += 2 ) if ( __builtin_popcount( i ) == 6 ) {
    int ct = 0 ;
    for ( int j = 0 ; j < n ; j ++ ) {
      bt[ j ] = ( i & ( 1 << j ) ) ? 1 : 0 ;
      if ( bt[ j ] ) {
        if ( j % 2 ) ct ++ ;
        else ct -- ;
      }
    }
    if ( ct == 0 && lft ) {
      lft -- ;
      for ( int i = n - 1 ; i >= 0 ; i -- ) printf( "%d" , bt[ i ] ) ;
      printf( " 3 2 3 3 7 3 3 2 3\n" ) ;
    }
  }
}

int main() {
  /*
#ifdef ONLINE_JUDGE
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
#endif
*/
  int Cases;
  scanf( "%d" , &Cases ) ;
  for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
    printf( "Case #%d:\n" , cases ) ;
    init() ;
    process() ;
  }
  return 0 ;
}

