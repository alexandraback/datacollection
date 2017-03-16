#include <iostream>
#include <cstdio>

using namespace std;

int t;
char map[5][5];

//x:1,0:2
bool isWon(char player) {

    bool won = false;

    //∫·œÚ≈–∂œ
    for (int i = 0; i < 4 && !won; ++i) {
        won = true;
        for (int j = 0; j < 4 && won; ++j) {
            if (map[i][j] != player && map[i][j] != 'T')
                won = false;
        }
    }

    //◊›œÚ≈–∂œ
    for (int j = 0; j < 4 && !won; ++j) {
        won = true;
        for (int i = 0; i < 4 && won; ++i) {
            if (map[i][j] != player && map[i][j] != 'T')
                won = false;
        }
    }

    if (won)
        return true;
    //–±Ω«≈–∂œ
    won = true;
    for (int i = 0; i < 4 && won; ++i) {
        if (map[i][i] != player && map[i][i] != 'T')
            won = false;
    }
    if (won)
        return true;

    won = true;
    for (int i = 0; i < 4 && won; ++i) {
        if (map[i][3 - i] != player && map[i][3 - i] != 'T')
            won = false;
    }
    return won;
}

bool isComplete() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (map[i][j] == '.')
                return false;
        }
    }
    return true;
}

int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    scanf("%d", &t);
    for (int ti = 1; ti <= t; ++ti) {
        for (int i = 0; i < 4; ++i) {
            scanf("%s", map[i]);
        }
        printf("Case #%d: ", ti);
        if (isWon('X')) {
            printf("X won\n");
        } else if (isWon('O')) {
            printf("O won\n");
        } else if (isComplete()) {
            printf("Draw\n");
        } else {
            printf("Game has not completed\n");
        }
    }
    return 0;
}

