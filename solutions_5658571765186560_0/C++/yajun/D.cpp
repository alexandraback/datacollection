# include <stdio.h>

bool get(int R, int C, int X) {
    if (R*C % X != 0) return false;
    switch(X) {
        case 1: return true;
        case 2: return true;
        case 3: return R==2 || C==2 || (R==3 && C==3) || R==4 || C==4;
        case 4: return R==3 || C==3 || (R==4 && C==4);
    }
    return false;
}

# define testin freopen("D-small-attempt2.in", "r", stdin)
# define testout freopen("outc.txt", "w", stdout)

int X, R, C;

int main()
{
    testin;
    testout;
/*
    for (int i = 1; i <= 4; ++i) {
        for (int j = 1; j <= 4; ++j) {
            for (int k = 1; k <= 4; ++k) {
                if (get(j, k, i)) printf("G");
                else printf("R");
            }
            printf("\n");
        }
        printf("\n");
        printf("\n");
    }
*/

    int T;
    scanf("%d", &T);
    for (int ica = 1; ica <= T; ++ica) {
        scanf("%d%d%d", &X, &R, &C);
        printf("Case #%d: ", ica);
        if (get(R,C,X)) puts("GABRIEL");
        else puts("RICHARD");
    }
    return 0;
}
