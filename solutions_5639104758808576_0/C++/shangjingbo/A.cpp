#include <cstdio>
#include <cstring>

const int maxn = 1000;

char s[maxn + 10];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);

    int test = 1, tests;
    for (scanf("%d", &tests); test <= tests; ++ test) {
        int n, answer = 0, sum = 0;
        scanf("%d%s", &n, s);
        for (int i = 0; i <= n; ++ i) {
            if (sum < i) {
                answer += i - sum;
                sum = i;
            }
            sum += s[i] - '0';
        }
        printf("Case #%d: %d\n", test, answer);
    }

    return 0;
}
