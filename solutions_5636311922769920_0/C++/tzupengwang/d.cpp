//by tzupengwang™
#include<bits/stdc++.h>
using namespace std;

#define FO(it,c) for (__typeof((c).begin()) it=(c).begin();it!=(c).end();it++)
typedef unsigned long long ll;
typedef pair<int,int> ii;

int k , c , s ;

void init() {
  scanf( "%d%d%d" , &k , &c , &s ) ;
}

void process() {
  if ( ( k + c - 1 ) / c > s ) {
    puts( " IMPOSSIBLE" ) ;
    return ;
  }
  vector< int > v ;
  int pt = 1 ;
  while ( pt <= k ) {
    v.clear() ;
    while ( pt <= k && v.size() < c ) {
      v.push_back( pt ++ ) ;
    }
    ll as = v.back() - 1 ; v.pop_back() ;
    for ( int i : v ) {
      as = as * (ll)k + (ll)i - 1 ;
    }
    printf( " %llu" , as + 1 ) ;
  }
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

