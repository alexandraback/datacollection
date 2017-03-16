#include <bits/stdc++.h>
using namespace std;
typedef pair< int, int > pii;

struct P{
    int a, b, c;
    P( int _a = -1, int _b = -1, int _c = -1 ) :
        a( _a ), b( _b ), c( _c ){}
    bool operator < ( const P &oth ) const{
        if( a != oth.a ) return a < oth.a;
        if( b != oth.b ) return b < oth.b;
        return c < oth.c;
    }
};

vector< P > ans;
map< pii, int > vis[ 3 ];
map< P, int > worn;

int main(){
    int T; scanf( "%d", &T );
    for( int kase = 1; kase <= T; ++kase ){
        ans.clear();
        for( int i = 0; i < 3; ++i ) vis[ i ].clear();
        worn.clear();
        int j, p, s, k; scanf( "%d%d%d%d", &j, &p, &s, &k );
        while( true ){
            bool chose = false;
            for( int x = 0; x < j && !chose; ++x )
                for( int y = 0; y < p && !chose; ++y )
                    for( int z = 0; z < s && !chose; ++z )
                        if( !worn[ P( x, y, z ) ] && vis[ 0 ][ pii( x, y ) ] < k && vis[ 1 ][ pii( y, z ) ] < k && vis[ 2 ][ pii( x, z ) ] < k ){
                            worn[ P( x, y, z ) ] = 1;
                            ++vis[ 0 ][ pii( x, y ) ];
                            ++vis[ 1 ][ pii( y, z ) ];
                            ++vis[ 2 ][ pii( x, z ) ];
                            ans.push_back( P( x, y, z ) );
                            chose = true;
                        }
            if( !chose ) break;
        }
        printf( "Case #%d: %d\n", kase, ( int ) ans.size() );
        for( int i = 0; i < ans.size(); ++i )
            printf( "%d %d %d\n", ans[ i ].a + 1, ans[ i ].b + 1, ans[ i ].c + 1 );
    }
    return 0;
}
