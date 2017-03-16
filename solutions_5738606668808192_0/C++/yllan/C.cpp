#include <cstdio>

#define MAX 600000
int primes[MAX];

void build_primes()
{
    int num_of_primes = 1;
    primes[0] = 2;
    for (int n = 3; num_of_primes < MAX; n += 2) {
        bool has_divisor = false;
        
        for (int i = 0; i < num_of_primes && primes[i] * primes[i] <= n; i++) {
            if (n % primes[i] == 0) {
                has_divisor = true;
                break;
            }
        }
        if (!has_divisor) {
            primes[num_of_primes] = n;
            num_of_primes++;
        } 
    }
}

int witness(long long binary, int n, int base)
{
    for (int p = 0; p < MAX; p++) {
        int mod = 0;
        int power = 1;
        for (int d = 0; d < n; d++) {
            mod += (((binary >> d) & 0x01LL) * power) % primes[p];
            power *= base;
            power %= primes[p];
        }
        if (mod % primes[p] == 0) {
            long long v = 0;
            long long power = 1;
            for (int d = 0; d < n; d++) {
                v += (((binary >> d) & 0x01LL) * power);
                power *= base;
            }
            if (v == primes[p]) {
                return 0;
            }
            return primes[p];
        }
    }
    return 0;
}

void solve(int n, int j)
{
    long long begin = 1LL + (1LL << (n - 1));
    int count = 0;
    for (long long i = begin; i < (1LL << n); i += 2) {
        bool all_composite = true;
        int w[11];
        
        for (int base = 2; base <= 10; base++) {
            w[base] = witness(i, n, base);
            if (w[base] == 0) {
                all_composite = false;
                break;
            }
        }
        if (all_composite) {
            for (int d = n - 1; d >= 0; d--)
                printf("%lld", (i >> d) & 0x01);
            for (int b = 2; b <= 10; b++)
                printf(" %d", w[b]);
            puts("");
            count++;
        }
        if (count == j) break;
    }
}

int main()
{
    build_primes();
    puts("Case #1:");
    solve(16, 50);
}