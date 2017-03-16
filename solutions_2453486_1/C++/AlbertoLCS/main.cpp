#include <iostream>

using namespace std;

int getWinner(char tablero[4][4])
{
    int X, O, punto = 0;
    for(int i = 0; i < 4; i++){
        X = 0;
        O = 0;
        for(int j = 0; j < 4; j++){
            if(tablero[i][j] == 'X')
                X++;
            else if(tablero[i][j] == 'O')
                O++;
            else if(tablero[i][j] == 'T'){
                X++;
                O++;
            }
            else if(tablero[i][j] == '.')
                punto++;
            if(X == 4)
                return 0;
            if(O == 4)
                return 1;
        }
    }
    for(int i = 0; i < 4; i++){
        X = 0;
        O = 0;
        for(int j = 0; j < 4; j++){
            if(tablero[j][i] == 'X')
                X++;
            else if(tablero[j][i] == 'O')
                O++;
            else if(tablero[j][i] == 'T'){
                X++;
                O++;
            }
            else if(tablero[j][i] == '.')
                punto++;
            if(X == 4)
                return 0;
            if(O == 4)
                return 1;
        }
    }
    X = 0;
    O = 0;
    for(int i = 0; i < 4; i++){
        if(tablero[i][i] == 'X')
            X++;
        else if(tablero[i][i] == 'O')
            O++;
        else if(tablero[i][i] == 'T'){
            X++;
            O++;
        }
        else if(tablero[i][i] == '.')
            punto++;
        if(X == 4)
            return 0;
        if(O == 4)
            return 1;
    }
    X = 0;
    O = 0;
    for(int i = 0; i < 4; i++){
        if(tablero[3-i][i] == 'X')
            X++;
        else if(tablero[3-i][i] == 'O')
            O++;
        else if(tablero[3-i][i] == 'T'){
            X++;
            O++;
        }
        else if(tablero[3-i][i] == '.')
            punto++;
        if(X == 4)
            return 0;
        if(O == 4)
            return 1;
    }
    if(punto == 0)
        return 2;
    else
        return 3;
}
int main()
{
    int casos, r;
    char tablero[4][4];
    cin >> casos;
    for(int x = 1; x < casos+1; x++){
        for(int i = 0; i < 4; i++)
            for(int j = 0; j < 4; j++)
                cin >> tablero[i][j];
        r = getWinner(tablero);
        cout << "Case #" << x << ": ";
        if(r == 0)
            cout << "X won" << endl;
        else if (r == 1)
            cout << "O won" << endl;
        else if (r == 2)
            cout << "Draw" << endl;
        else if (r == 3)
            cout << "Game has not completed" << endl;
    }
    return 0;
}
