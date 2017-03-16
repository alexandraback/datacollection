// eddy1021
#include <bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
typedef int TYPE;
typedef pair<int,int> PII;
#define mod9 1000000009ll
#define mod7 1000000000007ll 
#define INF 1023456789ll
#define FI first
#define SE second
#define PB push_back
#define MP make_pair
#define eps 1e-7
ll getint(){
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
bool equal( D _x ,  D _y ){
    return _x > _y - eps && _x < _y + eps;
}
int __ = 1 , cs;
/*********default*********/
int x , r , c;
void build(){

}
void init(){
    x = getint();
    r = getint();
    c = getint();
}
bool can(){
    if( r > c ) swap( r , c );
    if( x == 1 ) return true;
    if( ( r * c ) % x ) return false;
    if( x == 2 ) return true;
    if( c < x ) return false;
    if( x == 3 ){
        if( r == 1 ) return false;
        return true;
    }
    if( r <= 2 ) return false;
    return true;
}
void solve(){
    printf( "Case #%d: " , ++ cs );
    if( can() ) puts( "GABRIEL" );
    else puts( "RICHARD" );    
}
int main(){
    build();
    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
