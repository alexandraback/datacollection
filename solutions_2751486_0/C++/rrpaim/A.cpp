#include <iostream>

#define L 101

typedef long long integer;

using namespace std;

int length( char * s )
{
    int ret = 0;
    while ( s[ ret ] != '\0' ) ret++;
    return ret;
}

bool is_vowel( char * s, int pos )
{
    return s[ pos ] == 'a' or s[ pos ] == 'e' or s[ pos ] == 'i' or s[ pos ] == 'o' or s[ pos ] == 'u';
}

int main()
{
    int T, n, len, end;
    char str[ L ];
    bool count[ L ];
    integer ret;

    cin >> T;

    for ( int t = 1; t <= T; t++ )
    {
        ret = 0;

        cin >> str >> n;

        len = length( str );

        count[ 0 ] = !is_vowel( str, 0 );
    
        for ( int i = 1; i < len; i++ )
        {
            count[ i ] = !is_vowel( str, i );
        }

        end = 0;

        for ( int i = 0; i < len; i++ )
        {
            if ( !count[ i ] ) continue;
            bool possible = true;
            int j;
            for ( j = i+1; j < len and j-i < n; j++ )
            {
                if ( !count[ j ] )
                {
                    possible = false;
                    break;
                }
            }

            if ( possible and j-i == n )
            {
                //cout << i << " " << j << endl;
                //cout << i-end << " " << len-j << endl;
                ret += ( i-end+1 ) * ( len-j+1 );

                end = i+1;
            }
        }

        cout << "Case #" << t << ": " << ret << endl;
    }

    return 0;
}
