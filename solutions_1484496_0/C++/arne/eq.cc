#include <cstdio>
#include <cstring>

int N;
int a[500];
int m[2000001];

int main() {
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &N);

        int x = -1, y = -1;
        memset(m, -1, sizeof m);
        m[0] = 0;

        for (int i = 0; i < N; ++i) {
            scanf("%d", a + i);
            for (int j = 2000000; j >= 0; --j) {
                if (m[j] != -1) {
                    int p = m[j] | (1 << i);
                    if (m[j + a[i]] != -1) {
                        x = m[j + a[i]];
                        y = p;
                    }
                    m[j + a[i]] = p;
                }
            }
        }

        printf("Case #%d:\n", t);
        if (x < 0) printf("Impossible\n"); else {
            bool b = false;
            for (int i = 0; i < N; ++i) if (x & (1 << i)) {
                printf(b ? " %d" : "%d", a[i]);
                b = true;
            }
            printf("\n");

            b = false;
            for (int i = 0; i < N; ++i) if (y & (1 << i)) {
                printf(b ? " %d" : "%d", a[i]);
                b = true;
            }
            printf("\n");
        }
    }

    return 0;
}
