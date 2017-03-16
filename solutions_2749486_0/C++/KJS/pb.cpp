#include <stdio.h>
int main()
{   freopen("B-small-attempt3.in", "r", stdin);
    freopen("bout.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    int x, y;
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d", &x, &y);

        printf("Case #%d: ", t);

        int flag = 0;
        if (x > 0) {
            printf("E");
            flag = 1;
            for (int i = 1; i < x; ++i)
                printf("WE");
        } else if (x < 0) {
            printf("W");
            flag = 1;
            for (int i = 1; i < -x; ++i)
                printf("EW");
        }

        if (y > 0) {
            if (flag == 0)
                printf("N");

            for (int i = !flag; i < y; ++i)
                printf("SN");
        } else if (y < 0) {
            if (flag == 0)
                printf("S");

            for (int i = !flag; i < -y; ++i)
                printf("NS");
        }
        printf("\n");
    }
    return 0;
}
