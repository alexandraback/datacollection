//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
char s[ 1000 ] ;

void init() {
  scanf( "%s" , s ) ;
  n = strlen( s ) ;
  while ( n && s[ n - 1 ] == '+' ) n -- ;
}

int process() {
  char lst = '*' ;
  int ans = 0 ;
  for ( int i = 0 ; i < n ; i ++ ) if ( s[ i ] != lst ) {
    ans ++ , lst = s[ i ] ;
  }
  return ans ;
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
    printf( "Case #%d: %d\n" , cases , process() ) ;
  }
  return 0 ;
}

