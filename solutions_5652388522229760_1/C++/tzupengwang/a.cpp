//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

int n ;
int used[ 10 ] , cnt ;

void init() {
  memset( used , false , sizeof used ) ;
  cnt = 0 ;
  scanf( "%d" , &n ) ;
}

int process() {
  if ( n == 0 ) {
    return -1 ;
  }
  int x = n ;
  while ( cnt < 10 ) {
    int tp = x ;
    while ( tp ) {
      int w = tp % 10 ;
      if ( !used[ w ] ) used[ w ] = true , cnt ++ ;
      tp /= 10 ;
    }
    if ( cnt == 10 ) {
      return x ;
    }
    x += n ;
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
    init() ;
    int ans = process() ;
    printf( "Case #%d: " , cases ) ;
    if ( ans == -1 ) puts( "INSOMNIA" ) ;
    else printf( "%d\n" , ans ) ;
  }
  return 0 ;
}

