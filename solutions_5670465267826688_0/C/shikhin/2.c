#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cross[4][4] = {
    {1, 2, 3, 4},
    {2, -1, 4, -3},
    {3, -4, -1, 2},
    {4, 3, -2, -1}
};

int signum(int i) {
    return (i >= 0) ? 1 : -1;
}

int main()
{
    int T; scanf("%d", &T);
    for (int test = 0; test < T; test++) {
        int L, X; scanf("%d %d\n", &L, &X);

        char array[L * X];
        for (int i = 0; i < L; i++) {
            scanf("%c", &array[i]);
            array[i] = array[i] - 'i' + 2;
        }

        for (int j = 1; j < X; j++)
            memcpy(&array[L * j], &array, L);

        int seen_i = 0, seen_j = 0, cur = 1;
        for (int i = 0; i < L * X; i++) {
            cur = cross[abs(cur) - 1][array[i] - 1] * signum(cur);

            if (cur == 2) seen_i = 1;
            if (seen_i && cur == 4) seen_j = 1;
        }

        if (seen_i && seen_j && cur == -1)
            printf("Case #%d: YES\n", test + 1);
        else printf("Case #%d: NO\n", test + 1);
    }

    return 0;
}