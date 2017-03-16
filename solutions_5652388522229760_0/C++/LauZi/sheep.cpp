#include <cstdio>

void jizz() {
    int n; scanf("%d", &n);

    if (n == 0) {
        puts("INSOMNIA");
        return ;
    }

    bool gg[10] = {};
    int cnt = 0;

    for (int nn = n; ; nn += n) {
        for (int m = nn; m; m /= 10) {
            int d = m%10;
            if (not gg[d]) gg[d] = true, cnt += 1;
        }

        if (cnt == 10) {
            printf("%d\n", nn);
            return ;
        }
    }
}

int main() {
    int T; scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        printf("Case #%d: ", t);
        jizz();
    }

    return 0;
}
