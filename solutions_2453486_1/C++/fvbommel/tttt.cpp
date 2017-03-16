#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const char players[] = "OX";

char check_win( const string& s )
{
    cout << "# Checking " << s << endl;
    for( char p = 0 ; p < 2 ; p++ )
    {
        char c = players[ p ];
        bool win = true;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( s[ i ] != c && s[ i ] != 'T' )
            {
                win = false;
                break;
            }
        }
        if (win)
        {
            return c;
        }
    }
    return '\0';
}

bool complete( string (&game)[4] )
{
    for( int line = 0 ; line < 4 ; line++ )
    {
        if( game[line].find( '.' ) != string::npos )
            return false;
    }
    return true;
}

int main( int argc, const char** argv ) {
    const char* filename = "sample.in";
    if (argc >= 2)
        filename = argv[ 1 ];
    
    ifstream input( filename );
    ofstream output( (string(filename) + ".out").c_str() );
    
    int N;
    input >> N;
    cout << N << endl;
    
    string game[4];
    
    for (int i = 0 ; i < N ; i++)
    {
        cout << "Game #" << i << endl;
        for (int j = 0 ; j < 4 ; j++)
        {
            input >> game[ j ];
            cout << "Line #" << j << ": " << game[ j ] << endl;
        }
        
        output << "Case #" << (i+1) << ": ";
        
        // Check whether each player won.
        char winner = '\0';
        for (int line = 0 ; line < 4 && !winner; line++)
        {
            winner = check_win(game[line]);
        }
        if (winner)
        {
            output << winner << " won\n";
            continue;
        }

        for (int col = 0 ; col < 4 && !winner; col++)
        {
            char column[] = {
                game[0][col],
                game[1][col],
                game[2][col],
                game[3][col],
                0
            };
            winner = check_win(column);
        }
        if (winner)
        {
            output << winner << " won\n";
            continue;
        }
        
        char diag1[] = {
            game[0][0],
            game[1][1],
            game[2][2],
            game[3][3],
            0
        };
        if (( winner = check_win( diag1 ) ))
        {
            output << winner << " won\n";
            continue;
        }

        char diag2[] = {
            game[3][0],
            game[2][1],
            game[1][2],
            game[0][3],
            0
        };
        if (( winner = check_win( diag2 ) ))
        {
            output << winner << " won\n";
            continue;
        }
        
        if (complete(game))
        {
            output << "Draw\n";
            continue;
        }
        
        output << "Game has not completed\n";
    }
    
    cout << endl;
}