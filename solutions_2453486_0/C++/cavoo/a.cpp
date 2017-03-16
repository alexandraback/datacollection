/*************************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdlib>

using namespace std;

/*************************************************************************************/

char players[] = "XO";

char check(char grid[4][5])
{
    bool won = false, complete = true;

    for(int player = 0; player < 2; player++)
    {
        for(int row = 0; row < 4; row++)
        {
            won = true;
            for(int col = 0; col < 4; col++)
            {
                if(grid[row][col] != players[player] && grid[row][col] != 'T')
                {
                    won = false;
                    break;
                }
            }

            if(won)
                return players[player];
        }

        for(int col = 0; col < 4; col++)
        {
            won = true;
            for(int row = 0; row < 4; row++)
            {
                if(grid[row][col] != players[player] && grid[row][col] != 'T')
                {
                    won = false;
                    break;
                }
            }

            if(won)
                return players[player];
        }

        won = true;
        for(int i = 0; i < 4; i++)
        {
            if(grid[i][i] != players[player] && grid[i][i] != 'T')
            {
                won = false;
                break;
            }
        }

        if(won)
            return players[player];


        won = true;
        for(int i = 0; i < 4; i++)
        {
            if(grid[i][3-i] != players[player] && grid[i][3-i] != 'T')
            {
                won = false;
                break;
            }
        }

        if(won)
            return players[player];
    }

    for(int row = 0; row < 4; row++)
        for(int col = 0; col < 4; col++)
            if(grid[row][col] == '.')
                return '.';

    return ' ';
}

/*************************************************************************************/

int main(int argc, char **argv)
{
    ifstream inputfile(argv[1]);
    string line;

    getline(inputfile, line);
    int N = atoi(line.c_str());

    for(int T = 1; T <= N; T++)
    {
        char grid[4][5] = {0};

        cout << "Case #" << T << ": ";

        for(int i = 0; i < 4; i++)
        {
            getline(inputfile, line);
            for(int j = 0; j < 4; j++)
                grid[i][j] = line[j];

        }

        getline(inputfile, line);

        char result = check(grid);

        if(result == 'X' || result == 'O') cout << result << " won";
        else if(result == ' ') cout << "Draw";
        else cout << "Game has not completed";

        cout << endl;
    }


    return 0;
}

/*************************************************************************************/
