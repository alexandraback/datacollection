//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
int s[ 2000 ] ;
int cy[ 2000 ] ;
vector< int > v[ 2000 ] ;

void init() {
  scanf( "%d" , &n ) ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    v[ i ].clear() ;
  }
  for ( int i = 1 ; i <= n ; i ++ ) {
    scanf( "%d" , &s[ i ] ) ;
    v[ s[ i ] ].push_back( i ) ;
  }
}

bool vis[ 2000 ] ;
int dfs( int nw , int ct ) {
  int ret = 0 ;
  vis[ nw ] = true ;
  for ( int nxt : v[ nw ] ) if ( nxt != ct && !vis[ nxt ] ) {
    ret = max( ret , dfs( nxt , ct ) ) ;
  }
  return ret + 1 ;
}

void process() {
  memset( vis , false , sizeof vis ) ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    int len = 0 , nw = i ;
    do {
      nw = s[ nw ] ;
      len ++ ;
      if ( len == 2000 ) {
        len = 0 ;
        break ;
      }
    } while ( nw != i ) ;
    cy[ i ] = len ;
  }
  int ans = 0 ;
  for ( int i = 1 ; i <= n ; i ++ )
    ans = max( ans , cy[ i ] ) ;

  int ans2 = 0 ;
  for ( int i = 1 ; i <= n ; i ++ ) {
    if ( cy[ i ] == 2 && s[ i ] > i ) {
      ans2 += dfs( i , s[ i ] ) + dfs( s[ i ] , i ) ;
    }
  }
  ans = max( ans , ans2 ) ;
  printf( "%d\n" , ans ) ;
}

int main() {
  int Cases;
  scanf( "%d" , &Cases ) ;
  for ( int cases = 1 ; cases <= Cases ; cases ++ ) {
    init() ;
    printf( "Case #%d: " , cases ) ;
    process() ;
  }
  return 0 ;
}

