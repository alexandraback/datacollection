#include <iostream>

#define SIZE 4

using namespace std;

int main()
{
    int T;
    char c[ SIZE ][ SIZE+1 ];

    cin >> T;

    for ( int t = 0; t < T; t++ )
    {
        int empty = 0;
        for ( int i = 0; i < SIZE; i++ )
        {
            cin >> c[ i ];
            for ( int j = 0; j < SIZE; j++ )
            {
                if ( c[ i ][ j ] == '.' ) empty++;
            }
        }

        cout << "Case #" << t+1 << ": ";

        bool won = false;
        int count_t, count_o, count_x;
        for ( int i = 0; i < SIZE; i++ )
        {
            count_t = 0; count_o = 0; count_x = 0;
            //Row
            for ( int j = 0; j < SIZE; j++ )
            {
                switch ( c[ i ][ j ] )
                {
                    case 'O' : count_o++; break;
                    case 'X' : count_x++; break;
                    case 'T' : count_t++; break;
                }
            }

            if ( ( count_o == 4 ) or ( count_o == 3 and count_t == 1 ) )
            {
                cout << "O won" << endl;
                won = true;
                break;
            }
            if ( ( count_x == 4 ) or ( count_x == 3 and count_t == 1 ) )
            {
                cout << "X won" << endl;
                won = true;
                break;
            }
            
            count_t = 0; count_o = 0; count_x = 0;
            //Col
            for ( int j = 0; j < SIZE; j++ )
            {
                switch ( c[ j ][ i ] )
                {
                    case 'O' : count_o++; break;
                    case 'X' : count_x++; break;
                    case 'T' : count_t++; break;
                }
            }

            if ( ( count_o == 4 ) or ( count_o == 3 and count_t == 1 ) )
            {
                cout << "O won" << endl;
                won = true;
                break;
            }
            if ( ( count_x == 4 ) or ( count_x == 3 and count_t == 1 ) )
            {
                cout << "X won" << endl;
                won = true;
                break;
            }
        }

        if ( !won )
        {
            count_t = 0; count_o = 0; count_x = 0;
            //Main diag
            for ( int i = 0; i < SIZE; i++ )
            {
                switch ( c[ i ][ i ] )
                {
                    case 'O' : count_o++; break;
                    case 'X' : count_x++; break;
                    case 'T' : count_t++; break;
                }
            }

            if ( ( count_o == 4 ) or ( count_o == 3 and count_t == 1 ) )
            {
                cout << "O won" << endl;
                won = true;
            }
            if ( ( count_x == 4 ) or ( count_x == 3 and count_t == 1 ) )
            {
                cout << "X won" << endl;
                won = true;
            }
        }

        if ( !won )
        {
            count_t = 0; count_o = 0; count_x = 0;
            //Secondary diag
            for ( int i = 0; i < SIZE; i++ )
            {
                switch ( c[ SIZE-i-1 ][ i ] )
                {
                    case 'O' : count_o++; break;
                    case 'X' : count_x++; break;
                    case 'T' : count_t++; break;
                }
            }

            if ( ( count_o == 4 ) or ( count_o == 3 and count_t == 1 ) )
            {
                cout << "O won" << endl;
                won = true;
            }
            if ( ( count_x == 4 ) or ( count_x == 3 and count_t == 1 ) )
            {
                cout << "X won" << endl;
                won = true;
            }
        }

        if ( !won )
        {
            if ( empty == 0 )
                cout << "Draw" << endl;
            else
                cout << "Game has not completed" << endl;
        }
    }

    return 0;
}
