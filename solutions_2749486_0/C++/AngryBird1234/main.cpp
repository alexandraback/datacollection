#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <set>
using namespace std;
typedef long long LL;

int cas, x, y;
int casid;
int main()
{
    freopen( "B-small-attempt2.in", "r", stdin );
    freopen( "B-small-attempt2.out", "w", stdout );
    scanf( "%d", &cas );
    while ( cas-- )
    {
        string gox, goy;
        scanf( "%d %d",&x, &y );
        if ( x < 0 )
        gox = "EW", x *= -1;
        else
        gox = "WE";
        if ( y < 0 )
        goy = "NS", y *= -1;
        else
        goy = "SN";

        printf( "Case #%d: ", ++casid );
        for ( int i = 0; i < x; i++ )
        cout << gox;
        for ( int j = 0; j < abs( y ); j++ )
        cout << goy;
        cout << endl;
    }

    return 0;
}
