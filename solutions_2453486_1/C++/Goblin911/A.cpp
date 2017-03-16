#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;

char c[4][4];

void init() {
    scanf("%*c");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++)
            scanf("%c", &c[i][j]);
        scanf("%*c");
    }
}

int winner() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) if (c[i][j] == 'X' || c[i][j] == 'O') {
            bool h = true, v = true, l = (i == j), r = (i + j == 3); 
            for (int k = 0; k < 4; k++) {
                if (c[i][k] != c[i][j] && c[i][k] != 'T') h = false;
                if (c[k][j] != c[i][j] && c[k][j] != 'T') v = false;
                if (c[k][k] != c[i][j] && c[k][k] != 'T') l = false;
                if (c[3 - k][k] != c[i][j] && c[3 - k][k] != 'T') r = false;
            
            }
            if (h || v || l || r)
                return c[i][j] == 'X' ? 1 : -1;
        }
    return 0;
}

bool isEnd() {
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) if (c[i][j] == '.')
            return false;
    return true;
}

void solve() {
    int who = winner();
    if (who) {
        if (who == 1) {
            printf("X won\n");
            return;
        } else {
            printf("O won\n");
            return;
        }
    }
    if (isEnd())
        printf("Draw\n");
    else printf("Game has not completed\n");
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        init();
        solve();
    }
}
