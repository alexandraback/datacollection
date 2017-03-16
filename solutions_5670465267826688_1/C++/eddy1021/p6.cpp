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
#define N 10010
ll l , x;
char c[ N * 50 ];
int chg( char ctmp ){
    if( ctmp == 'i' ) return 2;
    if( ctmp == 'j' ) return 3;
    if( ctmp == 'k' ) return 4;
    return 0;
}
int mu[4][4] = { { 1 , 2 , 3 , 4 } ,
                { 2 , -1 , 4 , -3 } ,
                { 3 , -4 , -1 , 2 } ,
                { 4 , 3 , -2 , -1 } };
int mul( int tx , int ty ){
    int sgn = 1;
    if( tx < 0 ) sgn *= -1;
    if( ty < 0 ) sgn *= -1;
    int vl = mu[ abs( tx ) - 1 ][ abs( ty ) - 1 ];
    return sgn * vl;
}
void build(){

}
void init(){
    l = getint(); x = getint();
    if( x > 23 ){
        x %= 4;
        x += 20;
    }
    scanf( "%s" , c );
    for( int i = l ; i < l * x ; i ++ )
        c[ i ] = c[ i % l ];
    l *= x;    
}
int prep[ N * 20 ];
bool check(){
    prep[ 0 ] = chg( c[ 0 ] );
    for( int i = 1 ; i < l ; i ++ )
        prep[ i ] = mul( prep[ i - 1 ] , chg( c[ i ] ) );
    if( prep[ l - 1 ] != -1 ) return false;
    bool goti = false;
    for( int i = 0 ; i < l ; i ++ )
        if( !goti && prep[ i ] == 2 ) goti = true;
        else if( goti && prep[ i ] == 4 ) return true;
    return false;
}
void solve(){
    printf( "Case #%d: " , ++ cs );
    if( check() ) puts( "YES" );
    else puts( "NO" );
}
int main(){
    build();
    __ = getint();
    while( __ -- ){
        init();
        solve();
    }
}
