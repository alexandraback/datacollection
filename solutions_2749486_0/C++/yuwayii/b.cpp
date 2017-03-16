#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for( int tcase = 1; tcase <= t; ++tcase )
    {
        cout << "Case #" << tcase << ": ";

        int x, y;
        cin >> x >> y;
        if( x > 0 ) 
            for( int i = 0; i < x; ++i ) cout << "WE";
        else if( x < 0 )
            for( int i = 0; i < -x; ++i ) cout << "EW";

        if( y > 0 )
            for( int i = 0; i < y; ++i ) cout << "SN";
        else if( y < 0 )
            for( int i = 0; i < -y; ++i ) cout << "NS";

        cout << endl;
    }
}
