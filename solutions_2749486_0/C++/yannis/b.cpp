#include <cstdio>
#include <cstdlib>

int main(void) {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t, T, i, x, y;

    scanf("%d", &T);

    for (t=1; t<=T; ++t) {
        scanf("%d %d", &x, &y);

        printf("Case #%d: ", t);

        for (i=0; i<x; ++i) { printf("WE"); }
        for (i=x; i<0; ++i) { printf("EW"); }
        for (i=0; i<y; ++i) { printf("SN"); }
        for (i=y; i<0; ++i) { printf("NS"); }
        printf("\n");
    }

    return 0;
}
