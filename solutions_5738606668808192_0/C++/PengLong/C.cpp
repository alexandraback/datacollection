#include <cstdio>
#define MAXN 100005

long long chang(long long a, long long root)
{
    long long ans = 0, r = 1;
    while (a)
    {
        if (a & 1)
            ans += r;
        r *= root;
        a >>= 1;
    }
    return ans;
}

bool mark[MAXN] = {false};
long long prime[10000];
int prisz = 0, ans[10], ansz;

int isntprime(long long a)
{
    for (int i = 0; i < prisz && prime[i] * prime[i] <= a; ++i) if (a % prime[i] == 0LL)
        return prime[i];
    return 0;
}

bool sta[100];
int stasz = 0;

void prn(long long a)
{
    stasz = 0;
    while (a)
    {
        sta[stasz++] = a & 1;
        a >>= 1;
    }
    while (stasz--)
        putchar(sta[stasz] ? '1' : '0');
}

int main(int argc, char* argv[])
{
    mark[1] = true;
    for (int i = 2; i < MAXN; ++i) if (!mark[i])
    {
        prime[prisz++] = i;
        for (int j = i << 1; j < MAXN; j += i)
            mark[j] = true;
    }
    int T, n, m, t;
    long long a, b;
    scanf("%d", &T);
    for (int test = 1; test <= T; ++test)
    {
        scanf("%d%d", &n, &m);
        printf("Case #%d:\n", test);
        for (long long a = 1 << (n - 1) | 1; m > 0; a += 2)
        {
            ansz = 0;
            for (int root = 2; root <= 10; ++root)
            {
                b = chang(a, root);
                if (t = isntprime(b))
                    ans[ansz++] = t;
                else
                    break;
            }
            if (ansz == 9)
            {
                --m;
                prn(a);
                for (int i = 0; i < ansz; ++i)
                    printf(" %d", ans[i]);
                putchar('\n');
            }
        }
    }
    return 0;
}
