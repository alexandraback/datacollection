#include <iostream>
#include <cmath>

#define LIMIT 1100000

using namespace std;

typedef long long integer;

int main()
{
    integer X, Y, T;
    char ret[ LIMIT ];

    cin >> T;

    for ( integer t = 1; t <= T; t++ )
    {
        cin >> X >> Y;

        integer curr = 1;

        while ( X != 0 )
        {
            if ( X > 0 )
            {
                X--;
                ret[ curr-1 ] = 'W';
                ret[ curr ] = 'E';
            }
            else
            {
                X++;
                ret[ curr-1 ] = 'E';
                ret[ curr ] = 'W';
            }
            curr+=2;
        }

        while ( Y != 0 )
        {
            if ( Y > 0 )
            {
                Y--;
                ret[ curr-1 ] = 'S';
                ret[ curr ] = 'N';
            }
            else
            {
                Y++;
                ret[ curr-1 ] = 'N';
                ret[ curr ] = 'S';
            }
            curr+=2;
        }

        ret[ curr-1 ] = '\0';

        cout << "Case #" << t << ": " << ret << endl;
    }
    return 0;
}
