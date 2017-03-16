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
typedef tuple<int,int,int> tiii;
typedef tuple<LL,LL,LL> tlll;
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
ll mypow( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 1ll;
  ll _tmp = mypow( _a , _x / 2 , _mod );
  _tmp = mul( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = mul( _tmp , _a , _mod );
  return _tmp;
}
ll mymul( ll _a , ll _x , ll _mod ){
  if( _x == 0 ) return 0ll;
  ll _tmp = mymul( _a , _x / 2 , _mod );
  _tmp = add( _tmp , _tmp , _mod );
  if( _x & 1 ) _tmp = add( _tmp , _a , _mod );
  return _tmp;
}
inline bool equal( D _x ,  D _y ){
  return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , _cs;
/*********default*********/
#define N 10210
void build(){
}
int n , bf[ N ] , sz[ N ] , p[ N ] , bst[ N ] , gd[ N ];
int find_p( int x ){
  return x == p[ x ] ? x : p[ x ] = find_p( p[ x ] );
}
void Union( int x , int y ){
  x = find_p( x );
  y = find_p( y );
  p[ x ] = y;
}
bool onc[ N ];
void init(){
  n = getint();
  for( int i = 0 ; i < n ; i ++ )
    bf[ i ] = getint() - 1;
  for( int i = 0 ; i < n ; i ++ ){
    onc[ i ] = false;
    p[ i ] = i;
    bst[ i ] = 0;
    gd[ i ] = 0;
  }
}
int ans;
bool tag[ N ];
void cal( int now ){
  for( int j = 0 ; j < n ; j ++ )
    tag[ j ] = false;
  int cnt = 0 , st = now;
  while( !tag[ now ] ){
    cnt ++; tag[ now ] = true;
    now = bf[ now ];
  }
  if( st == now ){
    for( int j = 0 ; j < n ; j ++ )
      tag[ j ] = false;
    while( !tag[ now ] ){
      onc[ now ] = true;
      tag[ now ] = true;
      sz[ now ] = cnt;
      now = bf[ now ];
    }
    ans = max( ans , cnt );
  }
}
void gogo( int now ){
  int len = 0;
  while( !onc[ now ] ){
    len ++;
    now = bf[ now ];
  }
  bst[ now ] = max( bst[ now ] , len );
}
void gogo2( int now ){
  vector<int> vv;
  vv.PB( now ); int tmp = bf[ now ];
  while( now != tmp ){
    vv.PB( tmp );
    tmp = bf[ tmp ];
  }
  int kk = sz[ now ];
  for( size_t i = 0 ; i < vv.size() ; i ++ )
    for( size_t j = i + 1 ; j < vv.size() ; j ++ ){
      ans = max( ans , sz[ now ] + bst[ vv[ i ] ] + bst[ vv[ j ] ] );
      kk = max( kk , sz[ now ] + bst[ vv[ i ] ] + bst[ vv[ j ] ] );
    }
  for( size_t i = 0 ; i < vv.size() ; i ++ ){
    ans = max( ans , sz[ now ] + bst[ vv[ i ] ] );
    kk = max( kk , sz[ now ] + bst[ vv[ i ] ] );
  }
  gd[ now ] = kk;
}
void solve(){
  ans = 1;
  for( int i = 0 ; i < n ; i ++ ){
    if( !onc[ i ] ) cal( i );
    Union( i , bf[ i ] );
  }
  for( int i = 0 ; i < n ; i ++ )
    if( !onc[ i ] )
      gogo( i );
  int kkk = 0;
  for( int i = 0 ; i < n ; i ++ )
    if( bf[ bf[ i ] ] == i ){
      gogo2( i );
      if( i == find_p( i ) )
        kkk += gd[ i ];
    }
  ans = max( ans , kkk );
  printf( "Case #%d: %d\n" , ++ _cs , ans );
}
int main(){
  build();
  __ = getint();
  while( __ -- ){
    init();
    solve();
  }
}
