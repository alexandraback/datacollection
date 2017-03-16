#include <cstdio>

int f[1000001];

long long Reverse(long long x) {
        long long j = x;
        long long k = 0;
        while (j > 0) {
            k = (k * 10) + (j % 10);
            j /= 10;
        }
        return k;
}

int main() {
    f[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        f[i] = f[i - 1] + 1;
        int k = Reverse(i);
        if (k < i && Reverse(k) == i && f[k] + 1 < f[i]) f[i] = f[k] + 1;
        //ssif (i < 30) printf("f[%d] = %d]\n", i, f[i]);
    }
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        long long n;
        scanf("%I64d", &n);
        printf("Case #%d: ", cas);
        printf("%d\n", f[n]);
    }
    return 0;
}
