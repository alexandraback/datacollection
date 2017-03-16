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
void build(){

}
ll k , c , s;
void init(){
  k = getint();
  c = getint();
  s = getint();
}
// 1 -> 1
// 2 -> k + 1
// 3 -> 2k + 1
vector<PLL> v;
ll cal( ll l , ll r ){
  v.clear();
  for( ll i = l ; i < r ; i ++ )
    v.PB( MP( i , i ) );
  for( ll _ = 1 ; _ < c ; _ ++ ){
    // r - 1
    if( (int)v.size() == 1 ){
      v[ 0 ].FI = ( v[ 0 ].FI - 1 ) * k + 1;
      v[ 0 ].SE = ( v[ 0 ].SE - 1 ) * k + 1;
    }else{
      for( size_t i = 0 ; i + 2 < v.size() ; i ++ ){
        v[ i ].FI = ( v[ i ].FI - 1 ) * k + 1;
        v[ i ].SE = ( v[ i ].SE - 1 ) * k + 1;
      }
      int sz = (int)v.size();
      if( max( v[ sz - 2 ].FI , v[ sz - 1 ].FI ) <=
          min( v[ sz - 2 ].SE , v[ sz - 1 ].SE ) ){
        v[ sz - 2 ].FI = ( max( v[ sz - 2 ].FI , v[ sz - 1 ].FI ) - 1 ) * k + 1;
        v[ sz - 2 ].SE = ( min( v[ sz - 2 ].SE , v[ sz - 1 ].SE ) - 1 ) * k + 1;
      }else{
        v[ sz - 2 ].FI = v[ sz - 2 ].SE =
          ( v[ sz - 2 ].FI - 1 ) * k + r - _;
      }
      v.pop_back();
    }
  }
  return v[ 0 ].FI;
}
void solve(){
  printf( "Case #%d: " , ++ _cs );
  if( ( k / c ) + ( k % c != 0 ) > s )
    puts( "IMPOSSIBLE" );
  else{
    vector<ll> ans;
    for( int l = 1 ; l <= k ; l += c )
      ans.PB( cal( l , min( l + c , k + 1 ) ) );
    for( size_t i = 0 ; i < ans.size() ; i ++ )
      printf( "%lld%c" , ans[ i ] , " \n"[ i + 1 == ans.size() ] );
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
