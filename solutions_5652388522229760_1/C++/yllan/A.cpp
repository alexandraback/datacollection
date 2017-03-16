#include <cstdio>

long long solve(long long n)
{
    if (n == 0) return 0;
    int digits = 0;
    long long answer = 0;
    for (answer = 1; digits != (1 << 10) - 1; answer++) {
        // printf("Try %lld:\n", n * answer);
        for (long long dn = n * answer; dn > 0; dn /= 10) {
            int d = dn % 10; // last digit
            digits |= (1 << d);
        }
    }
    return n * (answer - 1);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; t++) {
        long long N;
        scanf("%lld", &N);
        long long answer = solve(N);
        if (answer == 0) {
            printf("Case #%d: INSOMNIA\n", t);
        } else {
            printf("Case #%d: %lld\n", t, answer);
        }
    }    
}