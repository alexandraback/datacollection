#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for( int tcase = 1; tcase <= t; ++tcase )
    {
        cout << "Case #" << tcase << ": ";

        int n;
        long long a1, a[ 100 ];
        cin >> a1 >> n;
        for( int i = 0; i < n; ++i ) cin >> a[ i ];

        if( a1 == 1 )
        {
            cout << n << endl;
            continue;
        }
        
        sort( a, a + n );
        int pos = 0;
        vector< int > cost, rest;
        for( ; pos < n; ++pos )
            if( a1 > a[ pos ] ) a1 += a[ pos ]; else break;

        while( pos != n )
        {
            int cnt = 0;
            rest.push_back( n - pos );
            while( a1 <= a[ pos ] )
            {
                ++cnt;
                a1 = a1 * 2 - 1;
            }
            cost.push_back( cnt );
            for( ; pos < n; ++pos )
                if( a1 > a[ pos ] ) a1 += a[ pos ]; else break;
        }
        cost.push_back( 0 );
        rest.push_back( 0 );
        int res = 0x7FFFFFFF, totalcost = 0;
        for( int i = 0; i < cost.size(); ++i )
        {
            if( res > totalcost + rest[ i ] )
                res = totalcost + rest[ i ];
            totalcost += cost[ i ];
        }

        cout << res << endl;
    }
}
