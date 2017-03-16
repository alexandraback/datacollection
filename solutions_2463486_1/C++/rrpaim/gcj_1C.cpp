#include <iostream>
#include <cmath>
#include <list>

#define LIMIT 100000000000000LL

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
    list< integer > l;

    a = ceil( sqrt( double( 1 ) ) );
    b = floor( sqrt( double( LIMIT ) ) );

    for ( integer i = a; i <= b; i++ )
    {
        if ( is_palindrome( i ) and is_palindrome( i*i ) ) l.push_back( i*i );
    }

    cin >> T;

    for ( int t = 0; t < T; t++ )
    {
        cin >> A >> B;

        /*a = ceil( sqrt( double( A ) ) );
        b = floor( sqrt( double( B ) ) );

        ret = 0;

        for ( integer i = a; i <= b; i++ )
        {
            if ( is_palindrome( i ) and is_palindrome( i*i ) ) cout << i*i << endl;
        }*/

        ret = 0;

        list< integer >::iterator it_begin;
        list< integer >::reverse_iterator it_end;
        integer left_gap = 0, right_gap = 0;

        for ( it_begin = l.begin(); it_begin != l.end(); ++it_begin )
        {
            left_gap++;
            if ( *it_begin >= A ) break;
        }

        for ( it_end = l.rbegin(); it_end != l.rend(); ++it_end )
        {            
            right_gap++;
            if ( *it_end <= B ) break;
        }

        cout << "Case #" << t+1 << ": " << l.size() - ( left_gap + right_gap - 2 ) << endl;

    }
    
    return 0;
}
