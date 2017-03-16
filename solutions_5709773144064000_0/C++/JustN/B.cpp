#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
const int Right = 10000000;

double C , F , X;

double f( int k )
{
    double res = (X - C) / (2 + ( double(k) * F) );
    for ( int i =0 ; i <= k ; i++ )
        res += C / ( 2 + ( double(i) * F) );

    return res;
}

int main()
{
    freopen("input.in" , "r" , stdin );
    freopen("output.out" , "w" , stdout );

    cout << setprecision(10) << fixed ;

    int T;
    cin >> T;

    for ( int t = 1 ; t <= T ; t++ )
    {

        cin >> C >> F >> X;

        double V = ( F * ( X - C ) ) - ( 2 * C );

        int l = 0 , r = Right;

        while ( r - l > 1 )
        {
            int mid = ( r + l ) / 2 ;
            if ( double(mid) * F * C > V ) r = mid ;
            else l = mid;
        }

        int k ;
        if ( double(l) * F * C > V ) k = l;
        else k = r;

        cout << "Case #" << t << ": " << f( k ) << endl;

    }

    return 0;
}

