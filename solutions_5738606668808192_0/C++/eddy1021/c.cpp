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
#define N 1048576
bool p[ N + N ];
ll f[ N + N ];
ll bs[ 11 ][ 100 ];
vector<ll> pr;
void build(){
  for( ll i = 2 ; i < N ; i ++ ) p[ i ] = true;
  for( ll i = 2 ; i < N ; i ++ ) if( p[ i ] ){
    pr.PB( i );
    for( ll j = N / i ; j >= i ; j -- ){
      p[ i * j ] = false;
      f[ i * j ] = i;
    }
  }
  for( ll i = 1 ; i <= 10 ; i ++ ){
    bs[ i ][ 0 ] = 1;
    for( ll j = 1 ; j < 100 ; j ++ )
      bs[ i ][ j ] = bs[ i ][ j - 1 ] * i;
  }
}
inline ll isp( ll x ){
  if( x < N ){
    if( p[ x ] ) return -1;
    return f[ x ];
  }else{
    for( size_t i = 0 ; i < pr.size() && pr[ i ] * pr[ i ] <= x ; i ++ )
      if( x % pr[ i ] == 0 )
        return pr[ i ];
    return -1;
  }
}
ll n , J;
void init(){
  n = getint();
  J = getint();
}
vector<ll> ans;
vector<ll> di[ 11 ];
ll bt[ N ] , tvl , tmp[ 11 ];
bool okay( ll nbs ){
  ll vl = 0;
  for( ll i = 0 ; i < n ; i ++ )
    vl += bt[ i ] * bs[ nbs ][ i ];
  tvl = vl;
  ll tdi = isp( vl );
  if( tdi == -1 ) return false;
  tmp[ nbs ] = tdi;
  return true;
}
void output(){
  puts( "Case #1:" );
  for( size_t i = 0 ; i < ans.size() ; i ++ ){
    printf( "%lld" , ans[ i ] );
    for( int ii = 2 ; ii <= 10 ; ii ++ )
      printf( " %lld" , di[ ii ][ i ] );
    puts( "" );
  }
}
void test(){
  for( int nbs = 2 ; nbs <= 10 ; nbs ++ )
    if( !okay( nbs ) )
      return;
  ans.PB( tvl );
  for( int nbs = 2 ; nbs <= 10 ; nbs ++ )
    di[ nbs ].PB( tmp[ nbs ] );
  if( (int)ans.size() == J ){
    output();
    exit( 0 );
  }
}
void solve(){
  bt[ 0 ] = bt[ n - 1 ] = 1;
  for( ll i = 0 ; i < ( 1ll << ( n - 2 ) ) ; i ++ ){
    for( ll j = 0 ; j < n - 2 ; j ++ )
      if( ( i >> j ) & 1ll )
        bt[ j + 1 ] = 1;
      else bt[ j + 1 ] = 0;
    test();
  }
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
