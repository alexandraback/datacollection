#include <cstdio>
#include <memory.h>

#define DEBUG 0
#if DEBUG == 1
#define dprintf(str, ...) printf(str, __VA_ARGS__)
#else
#define dprintf(str, ...)
#endif

#define MAX_N 300

int main() 
{
    int t, n;
    int s[MAX_N];
    int sum;
    int set[MAX_N];
    double result[MAX_N];
    scanf("%d", &t);
    for (int count = 1; count <= t; ++count)
    {
        scanf("%d", &n);
        sum = 0;
        memset(set, 0, sizeof(set));
        for (int idx = 0; idx < n; ++idx)
        {
            scanf("%d", s + idx);
            sum += s[idx];
        }
        dprintf("sum : %d\n", sum);
        printf("Case #%d: ", count);
        double result;
        int total = sum, lastTotal;
        int ignoreCount = 0;
        lastTotal = -1;
        while (lastTotal != total)
        {
            lastTotal = total;
            result = (double)(sum + total) / n;
            for (int idx = 0; idx < n; ++idx)
                if (s[idx] > result && set[idx] == 0)
                {
                    total -= s[idx];
                    set[idx] = 1;
                    ++ignoreCount;
                }
        }
        for (int idx = 0; idx < n; ++idx)
        {
            if (count == 6)
                dprintf("%d | ", s[idx]);
            result = ((double)(sum + total) / (double)(n - ignoreCount) - (double)s[idx]) / sum * 100;
            if (result < 0)
                result = 0;
            if (idx != n - 1)
                printf("%lf ", result);
            else 
                printf("%lf\n", result);
        }

    }
}
