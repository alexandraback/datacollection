#include <cstdio>
#include <cstring>

#define mem(s, v) memset(s, v, sizeof(s))

int R, C;
char field[55][55];


bool valid(int r, int c, int m) {
    if (m < 0 || r < 0 || c < 0) return false;
    if (r * c - m == 1) {

        field[0][0] = 'c';
        return true;
    }
    if (r == 1 || c == 1) {
        return false;
    }

    if (m == 0) {
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                field[i][j] = '.';
        field[0][0] = 'c';
        return true;
    }
    if (r < 3 || c < 3) {
        if (m % 2 != 0)
            return false;
        if (r * c - m < 4)
            return false;

        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                field[i][j] = '.';
            
        if (r < 3)
            for (int j = c - 1; j > 1; --j)
                field[0][j] = field[1][j] = '*', --m, --m;
        if (c < 3)
            for (int i = r - 1; i > 1; --i)
                field[i][0] = field[i][1] = '*', --m, --m;
        field[0][0] = 'c';
        return true;
    } else {
        if ((r - 2) * (c - 2) < m) return false;
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                field[i][j] = '.';
        for (int i = 0; i < r - 2; ++i)
            for (int j = 0; j < c - 2; ++j) {
                field[r - 1 - i][c - 1 - j] = '*';
                --m;
                if (m == 0) {
                    field[0][0] = 'c';
                    return true;
                }
            }
        field[0][0] = 'c';
        return true;
    }
}

int main() {
    int T, M;
    scanf("%d", &T);
    for (int kase = 1; kase <= T; ++kase) {
        scanf("%d %d %d", &R, &C, &M);
        mem(field, '.');
        bool worked = M == 0;
        if (worked) {
            field[0][0] = 'c';
            goto end;
        }
        if (R == 1 || C == 1) {
            int m = M;

            field[0][0] = 'c';
            for (int i = 0; i < R; ++i)
                for (int j = 0; j < C; ++j) {
                    field[R - 1 - i][C - 1 - j] = '*', --m;
                    if (m == 0) {
                        worked = true;
                        goto end;
                    }
                }
                    
        } else {
            mem(field, '*');
            for (int r = 1; r <= R; ++r) {
                for (int c = 1; c <= C; ++c) {
                    int mines = R * C - r * c;
                    if (valid(r, c, M - mines)) {
                        worked = true;
                        goto end;
                    }
                }
            }
        }
        end:;
        printf("Case #%d:\n", kase);
        if (worked) {
            for (int i = 0; i < R; ++i, printf("\n"))
                for (int j = 0; j < C; ++j)
                    printf("%c", field[i][j]);
        } else {
            printf("Impossible\n");
        }
    }
}
