#include <cstdio>

int main(void) {
    int T;
    int A, B;
    int prs, i, ti, l0;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        prs = 0;
        scanf("%d %d\n", &A, &B);
        l0 = 1;
        for (int i = A; i <= B; ++i) {
            while (l0 * 10 <= i) {
                l0 *= 10;
            }
            ti = i;
            for (;;) {
                if (ti % 10) {
                    ti = ti % 10 * l0 + ti / 10;
                    if (ti == i) {
                        break;
                    }
                    if (ti > i && A <= ti && ti <= B) {
                        ++prs;
                    }
                } else {
                    ti /= 10;
                }
            }
        }
        printf("Case #%d: %d\n", t, prs);
    }
    return 0;
}
