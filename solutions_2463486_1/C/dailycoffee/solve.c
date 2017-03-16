#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

static bool is_fair(uint64_t n)
{
    uint64_t m = 0;
    uint64_t i = n;
    while (i > 0) {
        int digit = i % 10;
        m = m * 10 + digit;
        i /= 10;
    }
    return n == m;
}

static uint64_t solve(uint64_t a, uint64_t b)
{
    uint64_t total = 0;
    uint64_t sa = (uint64_t)ceill(sqrt(a));
    uint64_t sb = (uint64_t)sqrt(b);
    for (uint64_t i = sa; i <= sb; ++i) {
        if (is_fair(i) && is_fair(i * i)) {
            ++total;
        }
    }
    return total;
}

int main(void)
{
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; ++i) {
        uint64_t a, b;
        scanf("%llu %llu\n", &a, &b);
        printf("Case #%d: %llu\n", i + 1, solve(a, b));
    }
}
