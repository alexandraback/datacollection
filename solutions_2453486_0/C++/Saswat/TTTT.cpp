#include <stdio.h>

#define DIAG1    (eq(b[0][0], b[1][1]) && eq(b[1][1], b[2][2]) && eq(b[2][2], b[3][3]) && eq(b[3][3], b[0][0]) ? (b[0][0] == 'T' ? b[1][1] : b[0][0]) : 0)
#define DIAG2    (eq(b[0][3], b[1][2]) && eq(b[1][2], b[2][1]) && eq(b[2][1], b[3][0]) && eq(b[3][0], b[0][3]) ? (b[0][3] == 'T' ? b[1][2] : b[0][3]) : 0)

#define COL(K)   (eq(b[0][K], b[1][K]) && eq(b[1][K], b[2][K]) && eq(b[2][K], b[3][K]) && eq(b[3][K], b[0][K]) ? (b[0][K] == 'T' ? b[1][K] : b[0][K]) : 0)
#define ROW(K)   (eq(b[K][0], b[K][1]) && eq(b[K][1], b[K][2]) && eq(b[K][2], b[K][3]) && eq(b[K][3], b[K][0]) ? (b[K][0] == 'T' ? b[K][1] : b[K][0]) : 0)

char b[4][5];

bool eq(char a, char b) {
    return a != '.' && b != '.' && (a == b || a == 'T' || b == 'T');
}

int main() {
    unsigned tests;

    scanf("%u\n", &tests);
    for(int t = 0; t < tests; ++t) {
        int c = 0;
        if(t)
            putchar(10);

        for(int i = 0; i < 4; ++i) {
            for(int j = 0; j < 4; ++j) {
                scanf("%c", *(b+i)+j);
                c += (b[i][j] == '.');
            }
            getchar();
        }
        getchar();

        char res = 0;
        if      (DIAG1)     res = DIAG1;
        else if (DIAG2)     res = DIAG2;

        for(int i = 0; i < 4 && !res; ++i) {
            res = COL(i);
            if(!res) res = ROW(i);
        }

        if(res)
            printf("Case #%d: %c won", t+1, res);
        else if(c)
            printf("Case #%d: Game has not completed", t+1);
        else
            printf("Case #%d: Draw", t+1);
    }

    return 0;
}
