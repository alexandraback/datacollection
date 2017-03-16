#include <cstdio>

int main(void) {
    int T, N, S, p, ti;
    int i0, i1;
    scanf("%d\n", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d %d %d", &N, &S, &p);
        i0 = 0;
        i1 = 0;
        for (int n = 0; n < N; ++n) {
            scanf("%d", &ti);
            if (3 * p - 2 <= ti) {
                ++i0;
            } else if (3 * p - 4 <= ti && (p != 1 || ti >= 1)) {
                ++i1;
            }
        }
        if (i1 > S) {
            i1 = S;
        }
        printf("Case #%d: %d\n", t, i0 + i1);
    }
    return 0;
}
