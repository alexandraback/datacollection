#include <stdio.h>

char str[10005];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    
    int cases;
    
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++)
    {
        int ans = 0;
        int num;
        scanf("%d %s", &num, &str);
        int tot = 0;
        for (int i = 0; i <= num; i++)
        {
            int p = str[i] - 48;
            if (ans + tot < i)
            {
                ans = i - tot;
            }
            tot += p;
        }
        printf("Case #%d: %d\n", c, ans);
    }
    
    return 0;
}
