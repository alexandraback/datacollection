#include <stdio.h>

int T, X, R, C;

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%d%d%d", &X, &R, &C);
        int area = R * C;
        if (X == 1) {
            printf("Case #%d: GABRIEL\n", t);
        } else if (X == 2) {
            if (area % 2)
                printf("Case #%d: RICHARD\n", t);
            else
                printf("Case #%d: GABRIEL\n", t);
        } else if (X == 3) {
            if (area % 3 || (R == 1 || C == 1))
                printf("Case #%d: RICHARD\n", t);
            else 
                printf("Case #%d: GABRIEL\n", t);
        } else if (X == 4) {
            if (area % 4 || (R == 1 || C == 1) ||
                    (R == 2 && C == 2) || (R == 2 && C == 4) 
                    || (R == 4 && C == 2)) 
                printf("Case #%d: RICHARD\n", t);
            else 
                printf("Case #%d: GABRIEL\n", t);
       }
    }

    return 0;
}
