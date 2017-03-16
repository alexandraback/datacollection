#include <stdio.h>

const int n = 32, j = 500;
typedef long long i64;

i64 conv(int x, int b)
{
    i64 ret = 0, y = 1;
    while (x) {
        if (x&1) ret += y;
        x >>= 1;
        y *= b;
    }
    return ret;
}

int main()
{
    puts("Case #1:");
    for (int x = (1<<(n/2-1))+1, k = 0; k < j; x += 2, ++k) {
        for (int i = n / 2 - 1; i >= 0; --i) printf("%d", x>>i&1);
        for (int i = n / 2 - 1; i >= 0; --i) printf("%d", x>>i&1);
        for (int i = 2; i <= 10; ++i) printf(" %lld", conv(x, i));
        puts("");
    }
}
