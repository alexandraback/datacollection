#include <stdio.h>

void findpath(int X, int Y, char *s) {
    int px = 0, py = 0, move = 0;
    if (X < px) {
        s[move] = 'W';
        px--;
        move++;
        while (px != X) {
            s[move] = 'E';
            s[move+1] = 'W';
            move += 2;
            px--;
        }
    } else if (X > px) {
        s[move] = 'E';
        px++;
        move++;
        while (px != X) {
            s[move] = 'W';
            s[move+1] = 'E';
            move += 2;
            px++;
        }
    }
    if (Y < py) {
        s[move] = 'S';
        py--;
        move++;
        while (py != Y) {
            s[move] = 'N';
            s[move+1] = 'S';
            move += 2;
            py--;
        }
    } else if (Y > py) {
        s[move] = 'N';
        py++;
        move++;
        while (py != Y) {
            s[move] = 'S';
            s[move+1] = 'N';
            move += 2;
            py++;
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 0; t < T; ++t)
    {
        int X, Y;
        char s[500];
        for (int i = 0; i < 500; ++i)
        {
            s[i] = '\0';
        }
        scanf("%d %d", &X, &Y);
        findpath(X, Y, s);
        printf("Case #%d: %s\n", t+1, s);
    }
}