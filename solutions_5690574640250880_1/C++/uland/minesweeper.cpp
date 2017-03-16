#include <cstdio>

const int maxR = 50;
const int maxC = 50;

void testCase()
{
    int r, c, m;
    scanf("%d%d%d", &r, &c, &m);
    int q = r * c - m;
    bool map[maxR][maxC];
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j)
            map[i][j] = true;
    }
    if (r == 1 || c == 1 || q <= 1 || m == 0) {
        int goodLeft = q;
        for (int i = 0; i < r; ++i) {
            for (int j = 0; j < c; ++j) {
                if (goodLeft > 0) {
                    map[i][j] = false;
                    --goodLeft;
                }
            }
        }
    } else {
        for (int i = 2; i <= r; ++i) {
            for (int j = 2; j <= c && i * j <= q; ++j) {
                int d = q - i * j;
                //printf("%d %d\n", i, j);
                for (int x = 0; x <= j; ++x) {
                    int y = d - x;
                    //printf("%d %d %d %d\n", i, j, x, y);
                    if (x != 1 && y != 1 && y >= 0 && y <= i && (x == 0 || i < r) && (y == 0 || j < c)) {
                        for (int pi = 0; pi < i; ++pi) {
                            for (int pj = 0; pj < j; ++pj) {
                                map[pi][pj] = false;
                            }
                        }
                        for (int px = 0; px < x; ++px) {
                            map[i][px] = false;
                        }
                        for (int py = 0; py < y; ++py) {
                            map[py][j] = false;
                        }
                        goto found;
                    }
                }
            }
        }
        printf("Impossible\n");
        return;
        found: ;
    }
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (i == 0 && j == 0)
                printf("c");
            else if (map[i][j])
                printf("*");
            else
                printf(".");
        }
        printf("\n");
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; ++i) {
        printf("Case #%d:\n", i);
        testCase();
    }
}