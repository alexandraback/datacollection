#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

string s[10];

int check() {
    //row
    for (int i = 1; i <= 4; i++) {
        int ok = 0;

        for (int j = 0; j < 4; j++)
            if (s[i][j] == '.') ok |= 1;
            else if (s[i][j] == 'O') ok |= 2;
            else if (s[i][j] == 'X') ok |= 4;

        if (ok == 2) return 1;
        else if (ok == 4) return 2;
    }

    //column

    for (int i = 0; i < 3; i++) {
        int ok = 0;

        for (int j = 1; j <= 4; j++)
            if (s[j][i] == '.') ok |= 1;
            else if (s[j][i] == 'O') ok |= 2;
            else if (s[j][i] == 'X') ok |= 4;

        if (ok == 2) return 1;
        else if (ok == 4) return 2;
    }

    //left diagonal
    int ok = 0;
    for (int i = 1; i <= 4; i++) {
        int j = i - 1;

        if (s[i][j] == '.') ok |= 1;
        else if (s[i][j] == 'O') ok |= 2;
        else if (s[i][j] == 'X') ok |= 4;
    }
    if (ok == 2) return 1;
    else if (ok == 4) return 2;

    //right diagonal
    ok = 0;
    for (int i = 1; i <= 4; i++) {
        int j = 4-i;

        if (s[i][j] == '.') ok |= 1;
        else if (s[i][j] == 'O') ok |= 2;
        else if (s[i][j] == 'X') ok |= 4;
    }
    if (ok == 2) return 1;
    else if (ok == 4) return 2;


    //complete
    for (int i = 1; i <= 4; i++)
        for (int j = 0; j < 3; j++)
            if (s[i][j] == '.') return 4;

    return 3;
}

int main() {
    freopen("A-large.in", "r", stdin);
    freopen("a.out", "w", stdout);

    int ntest;
    cin >> ntest;
    for (int test = 1; test <= ntest; test++) {
        cout << "Case #" << test << ": ";

        for (int i = 1; i <= 4; i++)
            cin >> s[i];

        int res = check();

        switch (res) {
            case 1: cout <<"O won";
            break;

            case 2: cout << "X won";
            break;

            case 3: cout << "Draw";
            break;

            case 4: cout <<"Game has not completed";
            break;
        }
        cout << endl;
    }

}
