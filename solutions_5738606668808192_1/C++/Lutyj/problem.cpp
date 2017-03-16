#include <cstdio>

void print_bin(unsigned n, int len)
{
    for (int i = len-1; i >= 0; --i)
        printf((n & (1<<i)) ? "1" : "0");
}

bool check3_4_5_7_9_10(unsigned n)
{
    int sum = 0;
    for (int i = 0; i < 32; ++i) {
        if (n & (1<<i))
            sum += 1;
    }
    return sum%2 == 0 && sum%3 == 0;
}

bool check2_8(unsigned n)
{
    int sum = 0;
    for (int i = 0; i < 32; ++i) {
        if (n & (1<<i))
            sum += (i%2 == 0) ? 1 : -1;
    }
    return sum%3 == 0;
}

bool check6(unsigned n)
{
    int sum = 0;
    for (int i = 0; i < 32; ++i) {
        if (n & (1<<i))
            sum += (i%2 == 0) ? 1 : -1;
    }
    return sum%7 == 0;
}

void solve(int N, int J)
{
    unsigned MAX = (1<<(N-2)) - 1;
    int j = 0;

    for (unsigned mask = 0; mask < MAX; ++mask) {
        unsigned a = 2 * (MAX + mask) + 3;
        if (!check3_4_5_7_9_10(a))
            continue;

        if (!check2_8(a))
            continue;

        if (!check6(a))
            continue;

        print_bin(a, N);
        printf(" 3 2 3 2 7 3 3 2 3\n");
        if (++j >= J) break;
    }
}

int main()
{
    int T; scanf("%d", &T);
    for (int t = 0; t < T; ++t) {
        int N, J;
        scanf("%d%d", &N, &J);
        printf("Case #%d:\n", t+1);
        solve(N, J);
    }

    return 0;
}
