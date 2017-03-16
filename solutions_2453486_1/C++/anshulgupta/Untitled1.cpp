#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <map>
#include <set>

using namespace std;

int fun(char board[4][4])
{
    int full = 0;
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            if(board[i][j] != '.')
                full++;
    
    for(int i = 0; i < 4; i++)
    {
        if( (board[i][0] == 'X' || board[i][0] == 'T') && (board[i][1] == 'X' || board[i][1] == 'T') &&
            (board[i][2] == 'X' || board[i][2] == 'T') && (board[i][3] == 'X' || board[i][3] == 'T'))
            return 1;
    }    
    for(int i = 0; i < 4; i++)
    {
        if( (board[0][i] == 'X' || board[0][i] == 'T') && (board[1][i] == 'X' || board[1][i] == 'T') &&
            (board[2][i] == 'X' || board[2][i] == 'T') && (board[3][i] == 'X' || board[3][i] == 'T'))
            return 1;
    }    
    
    for(int i = 0; i < 4; i++)
    {
        if( (board[i][0] == 'O' || board[i][0] == 'T') && (board[i][1] == 'O' || board[i][1] == 'T') &&
            (board[i][2] == 'O' || board[i][2] == 'T') && (board[i][3] == 'O' || board[i][3] == 'T'))
            return 2;
    }    
        
    for(int i = 0; i < 4; i++)
    {
        if( (board[0][i] == 'O' || board[0][i] == 'T') && (board[1][i] == 'O' || board[1][i] == 'T') &&
            (board[2][i] == 'O' || board[2][i] == 'T') && (board[3][i] == 'O' || board[3][i] == 'T'))
            return 2;
    }    
    
    if( (board[0][0] == 'X' || board[0][0] == 'T') && (board[1][1] == 'X' || board[1][1] == 'T') &&
        (board[2][2] == 'X' || board[2][2] == 'T') && (board[3][3] == 'X' || board[3][3] == 'T'))
        return 1;
    
    if( (board[0][3] == 'X' || board[0][3] == 'T') && (board[1][2] == 'X' || board[1][2] == 'T') &&
        (board[2][1] == 'X' || board[2][1] == 'T') && (board[3][0] == 'X' || board[3][0] == 'T'))
        return 1;
    
    
    if( (board[0][0] == 'O' || board[0][0] == 'T') && (board[1][1] == 'O' || board[1][1] == 'T') &&
        (board[2][2] == 'O' || board[2][2] == 'T') && (board[3][3] == 'O' || board[3][3] == 'T'))
        return 2;
    
    if( (board[0][3] == 'O' || board[0][3] == 'T') && (board[1][2] == 'O' || board[1][2] == 'T') &&
        (board[2][1] == 'O' || board[2][1] == 'T') && (board[3][0] == 'O' || board[3][0] == 'T'))
        return 2;
    
    if(full == 16)
        return 3;
    else
        return 4;
}
    
int main()
{
    int cases,  k = 1;
    char board[4][4];
    cin >> cases;
    
    while(cases--) {
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> board[i][j];
                 
        cout << "Case #" << k++ << ": ";
        switch(fun(board)) 
        {
            case 1: cout << "X won" << endl; break;
            case 2: cout << "O won" << endl; break;
            case 3: cout << "Draw" << endl; break;
            case 4: cout << "Game has not completed" << endl; break;
        }
    }
    return 0;
}
