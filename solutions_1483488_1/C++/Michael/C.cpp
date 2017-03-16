#include <cstring>
#include <iostream>

#define LIMIT 2000000
#define LENGTH 7

int main()
{
    int* found = new int[ LIMIT*LENGTH ];
    int T;
    std::cin >> T;
    for ( int t = 0; t < T; t++ )
    {
        memset( found, 0, LIMIT*LENGTH*sizeof( int ) );
        int A, B;
        std::cin >> A;
        std::cin >> B;
        int A_digits[ LENGTH ];
        int B_digits[ LENGTH ];
        int A_shift = A;
        int B_shift = B;
        int length;
        for ( length = 0; B_shift; length++ )
        {
            A_digits[ length ] = A_shift % 10;
            A_shift /= 10;
            B_digits[ length ] = B_shift % 10;
            B_shift /= 10;
        }
        int n = -1;
        int count = 0;
        int values[ LENGTH ] = { 1, 10, 100, 1000, 10000, 100000, 1000000 };
        int counter[ LENGTH ];
        for ( counter[ 6 ] = 0; counter[ 6 ] <= 1; counter[ 6 ]++ )
            for ( counter[ 5 ] = 0; counter[ 5 ] <= 9; counter[ 5 ]++ )
                for ( counter[ 4 ] = 0; counter[ 4 ] <= 9; counter[ 4 ]++ )
                    for ( counter[ 3 ] = 0; counter[ 3 ] <= 9; counter[ 3 ]++ )
                        for ( counter[ 2 ] = 0; counter[ 2 ] <= 9; counter[ 2 ]++ )
                            for ( counter[ 1 ] = 0; counter[ 1 ] <= 9; counter[ 1 ]++ )
                                for ( counter[ 0 ] = 0; counter[ 0 ] <= 9; counter[ 0 ]++ )
                                {
                                    if ( ++n < A )
                                        continue;
                                    if ( n >= B )
                                        break;
                                    for ( int offset = 1; offset < length; offset++ )
                                    {
                                        int m = 0;
                                        for ( int digit = 0; digit < length; digit++ )
                                            m += counter[ ( digit + offset ) % length ]*values[ digit ];
                                        if ( m <= n || m > B )
                                            continue;
                                        bool unseen = true;
                                        for ( int i = 1; i <= found[ LENGTH*n ]; i++ )
                                            if ( found[ LENGTH*n + i ] == m ) {
                                                unseen = false;
                                                break;
                                            }
                                        if ( unseen )
                                        {
                                            found[ LENGTH*n ]++;
                                            found[ LENGTH*n + found[ LENGTH*n ] ] = m;
                                            count++;
                                        }
                                    }
                                }
        std::cout << "Case #" << t + 1 << ": " << count << std::endl;
    }
    return 0;
}
