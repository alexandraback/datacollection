#include <cstdio>

int main() {

    int T;
    scanf("%d", &T);

    for (int t = 1; t <= T; t++) {

        int d;
        scanf("%d", &d);

        int p[d];
        for (int i = 0; i < d; i++)
            scanf("%d", &p[i]);

        int ans = 1000;
        for (int lim = 1; lim <= 1000; lim++) {
            int mov = 0;
            for (int i = 0; i < d; i++)
                mov += (p[i] - 1) / lim;
            if (mov + lim < ans)
                ans = mov + lim;
        }

        printf("Case #%d: %d\n", t, ans);

    }

}
