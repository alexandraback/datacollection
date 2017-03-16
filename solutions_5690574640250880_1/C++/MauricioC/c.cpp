#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>

using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for(int z = 1; z <= t; z++) {
        int R, C, M;
        scanf("%d %d %d", &R, &C, &M);
        int left = R*C - M;

        bool flip = false;
        if (R > C) {
            swap(R, C);
            flip = true;
        }

        char board[51][51];
        memset(board, '*', sizeof board);

        int maximum = min(left/2, C);
        if (2*maximum + 1 == left)
            maximum--;

        printf("Case #%d:\n", z);
        if(left == 1 || R == 1)
            for(int j = 0; j < left; j++)
                board[0][j] = '.';
        else if (maximum <= 1 || maximum == 2 && left % 2 == 1 || maximum * R < left) {
            printf("Impossible\n");
            continue;
        } else {
            for(int i = 0; i < R; i++) {
                int cur = min(left, maximum);
                if (cur + 1 == left)
                    cur--;

                for(int j = 0; j < cur; j++)
                    board[i][j] = '.';
                left -= cur;
            }

            assert(left == 0);
        }

        if(flip)
            swap(R, C);

        board[0][0] = 'c';
        for (int i = 0; i < R; i++, printf("\n"))
            for(int j = 0; j < C; j++)
                printf("%c", board[flip ? j : i][flip ? i : j]);
    }
}
