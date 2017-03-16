#include <stdio.h>

int p[1005];

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    
    int cases;
    scanf("%d", &cases);
    for (int c = 1; c <= cases; c++)
    {
        int maxp = 0;
        int num;
        scanf("%d", &num);
        for (int i = 1; i <= num; i++)
        {
            scanf("%d", &p[i]);
            if (maxp < p[i])
            {
                maxp = p[i];
            }
        }
        
        int ans = maxp;
        for (int maxe = 1; maxe <= maxp; maxe++)
        {
            int timeout = 0;
            for (int i = 1; i <= num; i++)
            {
                timeout += (p[i] - 1) / maxe;
            }
            if (ans > timeout + maxe)
            {
                ans = timeout + maxe;
            }
        }
        
        printf("Case #%d: %d\n", c, ans);
    }
    
    return 0;
}
