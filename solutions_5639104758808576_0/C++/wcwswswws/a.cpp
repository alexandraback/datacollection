#include <stdio.h>
char s[1001];
int a[1001];

int main()
{
    freopen("A-small-attempt3.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int test;
    scanf("%d", &test);
    for (int t = 1; t <= test; t++)
    {
        int n;
        scanf("%d%s", &n, s);
        for (int i = 0; i <= n; i++) { a[i] = s[i] - '0'; }
        int ans = 0, person = 0, smax = n;
        for (int i = 0; i <= smax; i++)
        if (a[i] > 0)
        {
            if (person >= i) { person += a[i]; }
            else
            {
                ans += i - person;
                person = i + a[i];
            }
        }
        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}
