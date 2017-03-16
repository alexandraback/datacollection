#include <cstdio>
#include <cstring>

using namespace std;

int N, X, Y;
int grid[40][40];

int wins, totals;

void move_diamond(int x, int y, int i);

void finish_at(int x, int y, int i) {
    grid[y][x] = 1;
    //printf("Diamond %d finished at (%d,%d)\n", i, x, y);
    if (i < N) {
        move_diamond(20, 40, i+1);
    } else {
        totals++;
        if (X < 40 && X >= 0 && Y < 40 && Y >= 0 && grid[Y][X])
            wins++;
    }
    grid[y][x] = 0;
}

void move_diamond(int x, int y, int i) {
    /* move down until it hits something */
    while (grid[y-2][x] == 0 && y >= 2)
        y -= 2;

    /* move left if possible */
    if (grid[y-1][x-1] == 0 && y > 0) {
        //printf("Diamond %d collided at (%d,%d)\n", i, x, y);
        move_diamond(x-1, y-1, i);
    }

    /* move right if possible */
    if (grid[y-1][x+1] == 0 && y > 0) {
        //printf("Diamond %d collided at (%d,%d)\n", i, x, y);
        move_diamond(x+1, y-1, i);
    }

    /* we're finished if we can't move */
    if ((grid[y-1][x-1] != 0 && grid[y-1][x+1] != 0) || y == 0) {
        finish_at(x, y, i);
        return;
    }
}

int main() {
    int T; scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        scanf("%d %d %d", &N, &X, &Y);

        wins = 0;
        totals = 0;
        X += 20;
        move_diamond(20, 40, 1);

        //printf("wins = %d; totals = %d;\n", wins, totals);

        printf("Case #%d: %f\n", i+1, (double)wins / (double)totals);
    }
}
