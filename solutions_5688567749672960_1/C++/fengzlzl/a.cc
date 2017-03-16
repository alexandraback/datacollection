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

long long Solve(long long n) {
        long long m = n;
        long long tot = 1;
        while (n > 1) {
            if (n % 10 == 0) {
                n--;
                tot++;
            }
            long long d = 1;
            for (; n / d >= 10; d *= 10);
            //printf("d = %I64d\n", d);
            long long best = n - d;
            for (long long i = 1; i <= d; i *= 10) {
                long long right = n % i;
                long long left = Reverse(n / i * i);
                if (right + left < best) best = right +left;
                //if (m == 11) printf("left = %I64d, right = %I64d\n" ,left, right);
            }
            n = d;
            tot += best;
        }
    return tot;
}

int main() {
    /*
    f[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        f[i] = f[i - 1] + 1;
        int k = Reverse(i);
        if (k < i && Reverse(k) == i && f[k] + 1 < f[i]) f[i] = f[k] + 1;
        if (i <=1000000 && f[i] != Solve(i)) printf("f[%d] = %d, solve = %I64d\n", i, f[i], Solve(i));
        //if (i < 122) printf("f[%d] = %d]\n", i, f[i]);
    }
    puts("OK");
    */
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++) {
        long long n;
        scanf("%I64d", &n);
        printf("Case #%d: ", cas);
      //  printf("%d\n", f[n]);
        /*
        long long m = n;
        while (m > 0) {
            int k = Reverse(m);
            if (f[m] == f[m - 1] + 1) n--;
            else if (k < m && Reverse(k) == m && f[k] + 1 == f[m]) {
                printf("%d from %d\n", k, m);
                m = k;
            }
        }
        */
        printf("%I64d\n", Solve(n));
    }
    return 0;
}
