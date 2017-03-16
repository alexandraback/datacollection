#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    int boardstate[4][4], cnt, draw, fill, i, j, t, temp1, temp2, win1, win2;
    string board[4], status, temp;
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    cin >> t;
    getline(cin, temp);
    for (cnt = 1; cnt <= t; cnt++)
    {
        draw = 0; fill = 0; win1 = 0; win2 = 0; //initialization
        
        //parse board
        for (i = 0; i < 4; i++)
        {
            getline(cin, board[i]);
            for (j = 0; j < 4; j++)
            {
                boardstate[i][j] = 0;
                if (board[i][j] == 'X') boardstate[i][j] = 1;
                if (board[i][j] == 'O') boardstate[i][j] = 2;
                if (board[i][j] == 'T') boardstate[i][j] = 3;
                if (boardstate[i][j]) fill++;
            }
        }
        
        //check rows
        for (i = 0; i < 4; i++)
        {
            if ((!win1) && (!win2))
            {
                temp1 = 0; temp2 = 0;
                for (j = 0; j < 4; j++)
                {
                    if (temp1 == j)
                    {
                        if ((boardstate[i][j] == 1) || (boardstate[i][j] == 3)) temp1++;
                    }
                    if (temp2 == j)
                    {
                        if ((boardstate[i][j] == 2) || (boardstate[i][j] == 3)) temp2++;
                    }
                }
                if (temp1 == 4) win1 = 1;
                if (temp2 == 4) win2 = 1;
            }
        }
        
        //check columns
        for (i = 0; i < 4; i++)
        {
            if ((!win1) && (!win2))
            {
                temp1 = 0; temp2 = 0;
                for (j = 0; j < 4; j++)
                {
                    if (temp1 == j)
                    {
                        if ((boardstate[j][i] == 1) || (boardstate[j][i] == 3)) temp1++;
                    }
                    if (temp2 == j)
                    {
                        if ((boardstate[j][i] == 2) || (boardstate[j][i] == 3)) temp2++;
                    }
                }
                if (temp1 == 4) win1 = 1;
                if (temp2 == 4) win2 = 1;
            }
        }
        
        //check both diagonals
        if ((!win1) && (!win2))
        {
            temp1 = 0; temp2 = 0;
            for (i = 0; i < 4; i++)
            {
                if (temp1 == i)
                {
                    if ((boardstate[i][i] == 1) || (boardstate[i][i] == 3)) temp1++;
                }
                if (temp2 == i)
                {
                    if ((boardstate[i][i] == 2) || (boardstate[i][i] == 3)) temp2++;
                }
            }
            if (temp1 == 4) win1 = 1;
            if (temp2 == 4) win2 = 1;
        }
        if ((!win1) && (!win2))
        {
            temp1 = 0; temp2 = 0;
            for (i = 0; i < 4; i++)
            {
                if (temp1 == i)
                {
                    if ((boardstate[i][3-i] == 1) || (boardstate[i][3-i] == 3)) temp1++;
                }
                if (temp2 == i)
                {
                    if ((boardstate[i][3-i] == 2) || (boardstate[i][3-i] == 3)) temp2++;
                }
            }
            if (temp1 == 4) win1 = 1;
            if (temp2 == 4) win2 = 1;
        }
        
        //check if draw, and recap status
        if ((!win1) && (!win2) && (fill == 16)) draw = 1;
        status = "Game has not completed";
        if (draw) status = "Draw";
        if (win1) status = "X won";
        if (win2) status = "O won";
        if ((win1) && (win2)) status = "error"; //should never occur
        
        //display results
        cout << "Case #" << cnt << ": " << status << endl;
        getline(cin, temp);
    }
    return 0;
}
