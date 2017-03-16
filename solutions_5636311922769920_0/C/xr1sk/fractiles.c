#include <stdio.h>
#include <math.h>

int main() {
    int T, t;
    scanf("%d", &T);
    t = T;
    while (t--) {
        int k, c, s;
        scanf("%d %d %d", &k, &c, &s);
        printf("Case #%d: ", T - t);
        long long temp = pow(k, c - 1);
        for (int i = 0; i < k; i++) {
            printf("%lld ", i * temp + 1);
        }
        printf("\n");
    }
}

