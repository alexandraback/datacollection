//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
struct lst {
  int s[ 100 ] ;
} lt[ 200 ] ;
int gmin = 3000 ;
int cnt[ 10000 ] ;

void init() {
  memset( cnt , 0 , sizeof cnt ) ;
  scanf( "%d" , &n ) ;
  for ( int i = 0 ; i < n * 2 - 1 ; i ++ ) {
    for ( int j = 0 ; j < n ; j ++ ) {
      scanf( "%d" , &lt[ i ].s[ j ] ) ;
      cnt[ lt[ i ].s[ j ] ] ++ ;
    }
  }
}

void process() {
  vector< int > ans ;
  for ( int i = 0 ; i <= 2500 ; i ++ ) {
    if ( cnt[ i ] % 2 ) ans.push_back( i ) ;
  }
  for ( int x : ans ) printf( " %d" , x ) ;
  puts( "" ) ;
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
    init() ;
    printf( "Case #%d:" , cases ) ;
    process() ;
  }
  return 0 ;
}

