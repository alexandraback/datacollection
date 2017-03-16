#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <vector>

using namespace std;
long long factors[11];

long long to_base(int a, int base)
{
    long long ret = 0, t = 1;
    for(; a; a >>= 1, t *= base)
        if (a & 1)
            ret += t;
    return ret;
}

long long find_factor(long long a)
{
    for (long long i = 2; i < a / i; i++)
        if (a % i == 0)
            return i;
    return -1;
}

void output_binary(long long a)
{
    if (!a) return;
    output_binary(a >> 1);
    printf("%lld", a & 1);
}

void solve()
{
    int n, j;
    scanf("%d%d", &n, &j);
    for (int i = 0; i < (1 << (n - 2)); i++)
    {
        int t = 1 + (i << 1) + (1 << (n - 1));
        bool flag = 1;
        for (int base = 2; base <= 10; base++)
        {
            long long t1 = to_base(t, base);
            long long factor = find_factor(t1);
            if (factor == -1)
            {
                flag = 0;
                break;
            } 
            factors[base] = factor;
        }
        if (flag)
        {
            output_binary(t);
            for (int k = 2; k <= 10; k++)
                printf(" %lld", factors[k]);
            printf("\n");
            j--;
            if(!j) return;
        }
    }
}

int main()
{
    freopen("c.in", "r", stdin);
    freopen("c.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Case #%d: \n", i);
        solve();
    }
    return 0;
}
