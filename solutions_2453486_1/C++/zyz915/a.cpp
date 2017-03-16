#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int C, T;
char a[6][6];

void check(char& winner, char a, char b, char c, char d) {
    if ((a == 'O' || a == 'T') && (b == 'O' || b == 'T') &&
        (c == 'O' || c == 'T') && (d == 'O' || d == 'T'))
        winner = 'O';
    if ((a == 'X' || a == 'T') && (b == 'X' || b == 'T') &&
        (c == 'X' || c == 'T') && (d == 'X' || d == 'T'))
        winner = 'X';
}

void run() {
    for (int i = 0; i < 4; i++)
        scanf("%s", a[i]);
    char winner = ' ';
    for (int i = 0; i < 4; i++) {
        check(winner, a[i][0], a[i][1], a[i][2], a[i][3]);
        check(winner, a[0][i], a[1][i], a[2][i], a[3][i]);
    }
    check(winner, a[0][0], a[1][1], a[2][2], a[3][3]);
    check(winner, a[0][3], a[1][2], a[2][1], a[3][0]);
    if (winner == 'O' || winner == 'X')
        printf("Case #%d: %c won\n", C, winner);
    else {
        int draw = true;
        for (int i = 0; i < 4; i++)
            for (int j = 0; j < 4; j++)
                if (a[i][j] == '.')
                    draw = false;
        if (draw)
            printf("Case #%d: Draw\n", C);
        else
            printf("Case #%d: Game has not completed\n", C);
    }
}

int main() {
    scanf("%d", &T);
    for (C = 1; C <= T; C++)
        run();
    return 0;
}
