#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for( int iii=0; iii<n; ++iii ) {

        bool t[4][4][2] = {{}};
        int filled = 0;
        for( int j=0; j<4; ++j )
            for( int k=0; k<4; ++k ) {
                char c;
                cin >> c;
                t[k][j][0] = ( c == 'X' || c == 'T' );
                t[k][j][1] = ( c == 'O' || c == 'T' );
                if ( c != '.' )
                    ++filled;
            }

        int wis = -1;
        for( int i=0; i<2; ++i ) {
            bool found = false;
            for( int j=0; j<4; ++j ) {
                {
                    bool r = true;
                    for( int k=0; k<4; ++k )
                        r &= t[k][j][i];
                    if ( r ) {
                        wis = i;
                        found = true;
                        break;
                    }
                }

                {
                    bool r = true;
                    for( int k=0; k<4; ++k )
                        r &= t[j][k][i];
                    if ( r ) {
                        wis = i;
                        found = true;
                        break;
                    }
                }
            }
            if ( found )
                goto result;
        }

        for( int i=0; i<2; ++i ) {
            bool found = false;
            {
                bool r = true;
                for( int j=0; j<4; ++j )
                    r &= t[j][j][i];
                if ( r ) {
                    wis = i;
                    found = true;
                    break;
                }
            }

            {
                bool r = true;
                for( int j=0; j<4; ++j )
                    r &= t[j][4-j-1][i];
                if ( r ) {
                    wis = i;
                    found = true;
                    break;
                }
            }
            if ( found )
                goto result;
        }

    result:
        cout << "Case #" << iii + 1 << ": ";
        if ( wis != -1 ) {
            cout << ( wis == 0 ? "X" : "O" ) << " won";
        } else {
            cout << ( filled == 16 ? "Draw" : "Game has not completed" );
        }
        cout << endl;

    }
}
