#include <stdio.h>

int a[1000001];

int main() {
    for (int i = 1; i <= 1000000; i++) {
        int mark = 0;
        int j = i;
        while (mark < (1 << 10) - 1) {
            int k = j;
            j += i;
            while (k) {
                mark |= (1 << (k % 10));
                k /= 10;
            }
        }
        a[i] = j - i;
    }
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int i = 1; i <= test; i++) {
        int m;
        scanf("%d", &m);
        int ans = a[m];
        printf("Case #%d: ", i);
        if (ans == 0) { printf("INSOMNIA\n"); }
        else { printf("%d\n", ans); }
    }
    return 0;
}
