#include <iostream>
#include <cmath>

using namespace std;

typedef long long integer;

bool is_palindrome( integer n )
{
    char to_str[ 100 ];

    integer it = 0;
    while ( n != 0 )
    {
        to_str[ it ] = '0' + n % 10;
        n /= 10;
        it++;
    }
    it--;

    for ( int i = 0; i <= it/2; i++ )
    {
        if ( to_str[ i ] != to_str[ it - i ] ) return false;
    }
    return true;
}

int main()
{
    integer T, A, B, a, b;
    integer ret;

    cin >> T;

    for ( int t = 0; t < T; t++ )
    {
        cin >> A >> B;

        a = ceil( sqrt( double( A ) ) );
        b = floor( sqrt( double( B ) ) );

        ret = 0;

        for ( integer i = a; i <= b; i++ )
        {
            if ( is_palindrome( i ) and is_palindrome( i*i ) ) ret++;
        }

        cout << "Case #" << t+1 << ": " << ret << endl;

    }
    
    return 0;
}
