#include <stdio.h>
#include <string.h>

bool c[10];
int s;

void add(int n)
{
    while (n) {
        if (!c[n % 10]) c[n % 10] = true, ++s;
        n /= 10;
    }
}

int solve(int n)
{
    memset(c, 0, sizeof(c));
    s = 0;
    int ret = 0;
    while (s < 10) add(ret += n);
    return ret;
}

int main()
{
    int dat;
    scanf("%d", &dat);
    for (int cas = 1; cas <= dat; ++cas) {
        int n;
        scanf("%d", &n);
        if (n == 0) {
            printf("Case #%d: INSOMNIA\n", cas);
        } else {
            printf("Case #%d: %d\n", cas, solve(n));
        }
    }
}
