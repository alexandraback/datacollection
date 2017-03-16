#include <iostream>
#include <sstream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <cstdio>
#include <climits>
#include <cstring>
#include <cmath>
#include <cassert>

#define X 4
#define Y 4

using namespace std;

int main() {
    int T;
    assert(scanf("%d\n", &T) != EOF);

    for (int t = 1; t <= T; ++t) {
        char board[X][Y];
        
        bool hasEmpty = false;
        for (int y = 0; y < Y; ++y) {
            for (int x = 0; x < X; ++x) {
                assert(scanf("%c", &board[y][x]) != EOF);
                if (board[y][x] == '.')
                    hasEmpty = true;
            }
            assert(scanf("\n") != EOF);
        }
        assert(scanf("\n") != EOF);

        bool winX = false, winO = false;
        // horinzotal
        for (int y = 0; y < Y; ++y) {
            bool okX = true, okO = true;
            for (int x = 0; x < X; ++x)
                if (board[y][x] != 'T') {
                    if (board[y][x] != 'X') okX = false;
                    if (board[y][x] != 'O') okO = false;
                }
            if (okX) winX = true;
            if (okO) winO = true;
        }

        // vertical
        for (int x = 0; x < X; ++x) {
            bool okX = true, okO = true;
            for (int y = 0; y < Y; ++y)
                if (board[y][x] != 'T') {
                    if (board[y][x] != 'X') okX = false;
                    if (board[y][x] != 'O') okO = false;
                }
            if (okX) winX = true;
            if (okO) winO = true;
        }

        // diagonal 1
        bool okX = true, okO = true;
        for (int y = 0; y < Y; ++y) {
            if (board[y][y] != 'T') {
                if (board[y][y] != 'X') okX = false;
                if (board[y][y] != 'O') okO = false;
            }
        }
        if (okX) winX = true;
        if (okO) winO = true;

        // diagonal 2
        okX = okO = true;
        for (int y = 0; y < Y; ++y) {
            int x = X - y - 1;
            if (board[y][x] != 'T') {
                if (board[y][x] != 'X') okX = false;
                if (board[y][x] != 'O') okO = false;
            }
        }
        if (okX) winX = true;
        if (okO) winO = true;
        
        if (winX)
            printf("Case #%d: X won\n", t);
        else if (winO)
            printf("Case #%d: O won\n", t);
        else if (!hasEmpty)
            printf("Case #%d: Draw\n", t);
        else
            printf("Case #%d: Game has not completed\n", t);
    }

    return 0;
}
