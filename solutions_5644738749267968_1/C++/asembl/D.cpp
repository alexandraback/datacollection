#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std ;
int n ;

double a[10000] , b[10000] ;

int main()
{
    int T , test = 0 ;
    cin >> T ;
    while ( T-- )
    {
        test++;
        cin >> n ;

        for ( int i = 0 ; i < n ; ++i )
            cin >> a[i] ;
        for ( int j = 0 ; j < n ; ++j )
            cin >> b[j] ;
        sort( a , a+n );
        sort( b , b+n );

        int ans1 = 0 ;
        for( int i = 0, j = 0 ; i < n ; ++i )
        {
            if ( a[i] > b[j] ) {
                ans1 ++ ;
                ++j ;
            }
        }
        int ans2 = 0 ;
        for( int i = 0, j = 0 ; i < n ; ++i )
        {
            if ( b[i] > a[j] ) {
                ans2 ++ ;
                ++j ;
            }
        }

        cout << "Case #" << test << ": ";
        cout << ans1 << ' ' << n-ans2 << endl ;
    }
    return 0;
}
