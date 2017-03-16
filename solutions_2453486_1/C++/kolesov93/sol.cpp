#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <deque>
#include <string>
#include <string.h>
#include <queue>
#include <stdlib.h>
#include <set>

using namespace std;

char w[11][11];
set<char> X, O;

bool cool(int x, int y) {
    return x >= 0 && x < 4 && y >= 0 && y < 4;
}

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);

    int _T;
    scanf("%d\n", &_T);

    X.insert('X');
    X.insert('T');
    O.insert('O');
    O.insert('T');

    for (int __test = 1; __test <= _T; ++__test) {
        for (int i = 0; i < 5; ++i) gets(w[i]);
        int cnte = 0;

        bool xwon = false, owon = false;
        for (int x = 0; x < 4; ++x)
            for (int y = 0; y < 4; ++y) {
                if (w[x][y] == '.') ++cnte;

                for (int dx = -1; dx <= 1; ++dx)
                    for (int dy = -1; dy <= 1; ++dy)
                        if (dx != 0 || dy != 0) {
                            int cntx = 0, cnto = 0;
                            
                            for (int i = 0; i < 4; ++i) {
                                if (!cool(x + dx * i, y + dy * i)) break;

                                char c = w[x + dx * i][y + dy * i];
                                if (X.find(c) != X.end()) ++cntx;
                                if (O.find(c) != O.end()) ++cnto;
                            }

                            if (cntx == 4) xwon = true;
                            if (cnto == 4) owon = true;
                        }
            }

        printf("Case #%d: ", __test);

        if (xwon) {
            puts("X won");
        } else if (owon) {
            puts("O won");
        } else if (cnte == 0) {
            puts("Draw");
        } else {
            puts("Game has not completed");
        }
    }


    return 0;
}

