//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef long long ll;
typedef pair<int,int> ii;

char s[ 10000 ] ;
int l ;

void init() {
  scanf( "%s" , s ) ;
  l = strlen( s ) ;
}

deque< char > dq ;
void process() {
  while ( !dq.empty() ) dq.pop_back() ;
  dq.push_back( s[ 0 ] ) ;
  char lst = 'Z' + 1 ;
  for ( int i = 1 ; i < l ; i ++ ) {
    if ( s[ i ] == dq.front() ) {
      if ( s[ i ] >= lst ) {
        dq.push_front( s[ i ] ) ;
      } else {
        dq.push_back( s[ i ] ) ;
        if ( lst == 'Z' + 1 ) lst = s[ i ] ;
      }
    } else if ( s[ i ] < dq.front() ) {
      dq.push_back( s[ i ] ) ;
      if ( lst == 'Z' + 1 ) lst = s[ i ] ;
    } else if ( s[ i ] > dq.front() ) {
      lst = dq.front() ;
      dq.push_front( s[ i ] ) ;
    }
  }
  for ( char x : dq ) {
    printf( "%c" , x ) ;
  } puts( "" ) ;
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
    printf( "Case #%d: " , cases ) ;
    process() ;
  }
  return 0 ;
}

