#include <cstdio>
#include <cstdlib>
#include <cstring>

int h(long long x)
{
        char s[20];
        for (int i = 0, j = sprintf(s, "%lld", x) - 1; i < j; i++, j--)
                if (s[i] != s[j])
                        return 0;
        return 1;
}

long long g(long long x, int y)
{
        char s[20];
        memset(s, 0, sizeof(s));
        for (int i = sprintf(s, "%lld", x) - 1, j = i + y; i >= 0; i--, j++)
                s[j] = s[i];
        return atoll(s);
}

int f(long long x)
{
        int ans = 0;
        for (long long i = 1; ; i *= 10 )
        
                for (int k = 0; k < 2; k++)
                        for (long long j = i; j < 10 * i; j++) {
                                long long r = g(j, k);
                                if (r * r > x)
                                        return ans;
                                ans += h(r * r);
                        }
}

int main()
{
        int T;
        scanf("%d", &T);
        for (int i = 1; i <= T; i++) {
                long long A, B;
                scanf("%lld%lld", &A, &B);
                printf("Case #%d: %d\n", i, f(B) - f(A - 1));
        }
}
