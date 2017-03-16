// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long double LD;
typedef long long ll;
typedef long long LL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<LD,LD> Pt;
#define mod9 1000000009ll
#define mod7 1000000007ll
#define INF  1023456789ll
#define INF16 10000000000000000ll
#define FI first
#define SE second
#define X FI
#define Y SE
#define PB push_back
#define MP make_pair
#define MT make_tuple
#define eps 1e-9
#define SZ(x) (int)(x).size()
#define ALL(x) (x).begin(), (x).end()
#ifndef ONLINE_JUDGE
#define debug(...) printf(__VA_ARGS__)
#else 
#define debug(...)
#endif
inline ll getint(){
  ll _x=0,_tmp=1; char _tc=getchar();    
  while( (_tc<'0'||_tc>'9')&&_tc!='-' ) _tc=getchar();
  if( _tc == '-' ) _tc=getchar() , _tmp = -1;
  while(_tc>='0'&&_tc<='9') _x*=10,_x+=(_tc-'0'),_tc=getchar();
  return _x*_tmp;
}
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = ( _tmp * _tmp ) % _mod;
  if( _x & 1 ) _tmp = ( _tmp * _a ) % _mod;
  return _tmp;
}
inline ll add( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x + _y;
  if( _ >= _mod ) _ -= _mod;
  return _;
}
inline ll sub( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x - _y;
  if( _ < 0 ) _ += _mod;
  return _;
}
inline ll mul( ll _x , ll _y , ll _mod = mod7 ){
  ll _ = _x * _y;
  if( _ >= _mod ) _ %= _mod;
  return _;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 111
void build(){

}
int n , v[ N ];
char c[ N ];
ll dp[ N ][ N ][ 2 ][ 2 ][ 2 ];
bool got[ N ][ N ][ 2 ][ 2 ][ 2 ];
bool cal[ N ][ N ][ 2 ][ 2 ][ 2 ];
void init(){
  scanf( "%s" , c + 1 );
  n = strlen( c + 1 );
  for( int i = 1 ; i <= n ; i ++ )
    if( c[ i ] == '+' ) v[ i ] = 1;
    else v[ i ] = 0;
  for( int i = 1 ; i <= n ; i ++ )
    for( int j = 1 ; j <= n ; j ++ )
      for( int k = 0 ; k < 2 ; k ++ )
        for( int u = 0 ; u < 2 ; u ++ )
          for( int o = 0 ; o < 2 ; o ++ )
            cal[ i ][ j ][ k ][ u ][ o ] =
            got[ i ][ j ][ k ][ u ][ o ] = false;
}
// l , r , inv , +- , ><
ll DP( int l , int r , int inv , int pos , int dir ){
  if( l > r ) return 0;
  if( got[ l ][ r ][ inv ][ pos ][ dir ] )
    return dp[ l ][ r ][ inv ][ pos ][ dir ];
  if( cal[ l ][ r ][ inv ][ pos ][ dir ] )
    return INF16;
  cal[ l ][ r ][ inv ][ pos ][ dir ] = true;
  ll tans = INF16;
  if( !dir ){
    if( ( v[ r ] ^ inv ) == pos )
      tans = min( tans , DP( l , r - 1 , inv , pos , dir ) );
    else{
      tans = min( tans , DP( l , r - 1 , inv , 1 - pos , dir ) + 1 );
      tans = min( tans , DP( l , r , 1 - inv , pos , 1 - dir ) + 1 );
    }
  }else{
    if( ( v[ l ] ^ inv ) == pos )
      tans = min( tans , DP( l + 1 , r , inv , pos , dir ) );
    else{
      tans = min( tans , DP( l + 1 , r , inv , 1 - pos , dir ) + 1 );
      tans = min( tans , DP( l , r , 1 - inv , pos , 1 - dir ) + 1 );
    }
  }
  got[ l ][ r ][ inv ][ pos ][ dir ] = true;
  return dp[ l ][ r ][ inv ][ pos ][ dir ] = tans;
}
void solve(){
  printf( "Case #%d: %lld\n" , ++ _cs , DP( 1 , n , 0 , 1 , 0 ) );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
