#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string mat[5];

int main()
{
    freopen ( "a.in", "r", stdin );
    freopen ( "ASmall.out", "w", stdout );
    // freopen ( "ALarge.out", "w", stdout );

    string line;

    int ntc, tc = 0;

    cin >> ntc;

    while( ntc -- )
    {
        tc ++;

        bool full = true;

        for( int i = 0; i < 4; i ++ )
            cin >> mat[i];

        bool A = false;
        bool B = false;

        for( int i = 0; i < 4; i ++ )
        {
            bool verA = true, horA = true, verB = true, horB = true;
            bool d1A = true, d2A = true;
            bool d1B = true, d2B = true;
            for ( int j = 0; j < 4; j ++ )
            {
                if ( mat[j][j] == '.' )
                    full = false;

                if ( mat[j][j] == 'O' )
                    d1A = false;
                if ( mat[j][j] == 'X' )
                    d1B = false;
                if ( mat[j][j] == '.' )
                    d1A = d1B = false;

                if ( mat[j][3 - j] == 'O' )
                    d2A = false;
                if ( mat[j][3 - j] == 'X' )
                    d2B = false;
                if ( mat[j][3 - j] == '.' )
                    d2A = d2B = false;

                if ( mat[i][j] == 'O' )
                    horA = false;
                if ( mat[i][j] == 'X' )
                    horB = false;
                if ( mat[i][j] == '.' )
                    horA = horB = false;

                if ( mat[j][i] == 'O' )
                    verA = false;
                if ( mat[j][i] == 'X' )
                    verB = false;
                if ( mat[j][i] == '.' )
                    verA = verB = false;
            }

            if ( horA || verA || d1A || d2A )
                A = true;
            if ( horB || verB || d1B || d2B )
                B = true;
        }
        cout << "Case #" << tc << ": ";
        if ( A )
            cout << "X won" << endl;
        else if ( B )
            cout << "O won" << endl;
        else if ( full )
            cout << "Draw" << endl;
        else
            cout << "Game has not completed" << endl;
    }

}
