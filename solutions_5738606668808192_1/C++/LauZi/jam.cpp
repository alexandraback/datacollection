#include <cstdio>

int n, j;

int main() {
    scanf("%*d%d%d", &n, &j);
    puts("Case #1:");

    int num = 1<<(n-1) | 1;
    while (j--) {
        for (; ; num += 2) {
            int cnt[2] = {};
            for (int i = 1; i < n-1; ++i)
                cnt[i&1] += num>>i&1;
            if (cnt[0] == cnt[1])
                break;
        }

        for (int i = n-1; i >= 0; --i)
            printf("%d", num>>i&1);
        for (int i = 2; i <= 10; ++i)
            printf(" %d", i+1);
        putchar('\n');
        num += 2;
    }

    return 0;
}
