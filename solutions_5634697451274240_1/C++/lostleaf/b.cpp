#include <cstdio>
#include <cstring>
#include <cstdlib>

char s[110];

void solve()
{
    scanf(" %s", s);
    int len = strlen(s);
    // printf("%s %d\n", s, len);
    int p2;
    for (p2 = len - 1; s[p2] == '+' && p2 >= 0; p2--);
    if (p2 < 0)
    {
        printf("0\n");
        return;
    }
    
    char cur = s[0], ret = 1;
    for (int p1 = 0; p1 <= p2; p1++)
        if (cur != s[p1])
        {
            cur = s[p1];
            ret++;
        }
    printf("%d\n", ret);
}

int main()
{
    freopen("b.in", "r", stdin);
    freopen("b.out", "w", stdout);

    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
