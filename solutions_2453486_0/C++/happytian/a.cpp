#include<iostream>
using namespace std;

char data[4][4];

int judge(bool full_fill) {
    int x, o, t;
    for (int i = 0; i < 4; i++) {
        x = 0, o = 0, t = 0;
        for (int j = 0; j < 4; j++) {
            if (data[i][j] == 'X')
                x++;
            else if (data[i][j] == 'O')
                o++;
            else if (data[i][j] == 'T')
                t++;
        }
        if ((x + t) == 4)
            return 1; // x win
        if ((o + t) == 4)
            return 2; // y win;
    }

    for (int j = 0; j < 4; j++) {
        x = 0, o = 0, t = 0;
        for (int i = 0; i < 4; i++) {
            if (data[i][j] == 'X')
                x++;
            else if (data[i][j] == 'O')
                o++;
            else if (data[i][j] == 'T')
                t++;
        }
        if ((x + t) == 4)
            return 1; // x win
        if ((o + t) == 4)
            return 2; // y win;
    }

    x = 0, o = 0, t = 0;
    for (int i = 0; i < 4; i++) {
        if (data[i][i] == 'X')
            x++;
        else if (data[i][i] == 'O')
            o++;
        else if (data[i][i] == 'T')
            t++;
    }
    if ((x + t) == 4)
        return 1; // x win
    if ((o + t) == 4)
        return 2; // y win;

    x = 0, o = 0, t = 0;
    for (int i = 0; i < 4; i++) {
        if (data[i][3-i] == 'X')
            x++;
        else if (data[i][3-i] == 'O')
            o++;
        else if (data[i][3-i] == 'T')
            t++;
    }
    if ((x + t) == 4)
        return 1; // x win
    if ((o + t) == 4)
        return 2; // y win;

    if (full_fill)
        return 3;
    return 4;
}

int main() {
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++) {
        bool full_fill = true;
        for (int p = 0; p < 4; p++)
            for (int q = 0; q < 4; q++) {
                cin >> data[p][q];
                if (data[p][q] == '.')
                    full_fill = false;
            }
        int result = judge(full_fill);
        if (result == 1) 
            cout << "Case #" << i << ": " << "X won" << endl;
        else if (result == 2)
            cout << "Case #" << i << ": " << "O won" << endl;
        else if (result == 3)
            cout << "Case #" << i << ": " << "Draw" << endl;
        else if (result == 4)
            cout << "Case #" << i << ": " << "Game has not completed" << endl;
    }
}
