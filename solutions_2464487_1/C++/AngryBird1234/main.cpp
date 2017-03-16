#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <map>
//#include <pair>
#include <algorithm>

using namespace std;
typedef unsigned long long LL;
int fk;
int main()
{
    //cout << ( 1ULL << 63 );
    freopen( "A-large.in", "r", stdin );
    freopen( "A-large.out", "w", stdout );
    LL t, r;
    int cas;
    scanf( "%d", &cas );
    while ( cas-- )
    {
       // int cnt = 0;
        cin >> r >> t;
        //while (  )
        LL high = ( 1ULL << 63 ), low = 1;
        while ( high >= low )
        {
            LL mid = ( high + low ) / 2;
            double val = 2.0 * mid * mid + ( 2.0 * r - 1 ) * mid - t * 1.0;
            if ( val > 0 )
            {
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        //cout << "Case #" << ++fk<< ": " << high << endl;
        printf( "Case #%d: ", ++fk );
        cout << high << endl;
    }
    return 0;
}
