#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>
using namespace std;

bool vis[ 2000000 ], rec[ 2000000 ][ 21 ];
int main()
{
    ifstream fi;
    ofstream fo;
    fi.open( "C.in" );
    fo.open( "C.out" );
    int testCase;
    fi>>testCase;
    for ( int z = 1; z <= testCase; z++ ){
        int n;
        memset( rec, 0, sizeof( rec ) );
        memset( vis, 0, sizeof( vis ) );
        int a[ 21 ];
        fi>>n;
        for ( int i = 1; i <= n; i++ )
            fi>>a[ i ];
        for ( int i = 1; i <= n; i++ ){
            rec[ a[ i ] ][ i ] = true;
            vis[ a[ i ] ] = true;
        }
        bool getans = false;
        fo<<"Case #"<<z<<": "<<endl;
        for ( int i = a[ 1 ]; i < 2000000; i++ ){
            if ( i == 1243 )
                n = n;
            if ( !vis[ i ] ) continue;
            if ( getans ) break;
            for ( int j = 1; j <= n; j++ ){
                if ( rec[ i ][ j ] ) continue;
                if ( vis[ i + a[ j ] ] ){
                    bool flag = false;
                    rec[ i ][ j ] = true;
                    for ( int k = 1; k <= n; k++ )
                        if ( rec[ i ][ k ] != rec[ i + a[ j ] ][ k ] ) flag = true;
                    rec[ i ][ j ] = false;
                    if ( !flag ) continue;
                    rec[ i ][ j ] = true;
                    for ( int k = 1; k <= n; k++ )
                        if ( rec[ i ][ k ] ) fo<<a[ k ]<<' ';
                    fo<<endl;
                    for ( int k = 1; k <= n; k++ )
                        if ( rec[ i + a[ j ] ][ k ] )
                            fo<<a[ k ]<<' ';
                    rec[ i ][ j ] = false;
                    fo<<endl;
                    getans = true;
                    if ( getans ) break;
                }
                else{
                    for ( int k = 1; k <= n; k++ )
                        rec[ i + a[ j ] ][ k ] = rec[ i ][ k ];
                    rec[ i + a[ j ] ][ j ] = true;
                    vis[ i + a[ j ] ] = true;
                }
            }
        }
    }
    return 0;
}
