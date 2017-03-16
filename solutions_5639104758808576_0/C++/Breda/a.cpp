#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, sm, i, j, r, p;
    char v[1010];
    scanf("%d", &t);
    for(j=1;j<=t;j++)
    {
        scanf("%d %s", &sm, v);
        r = p = 0;
        for(i=0;i<=sm;i++)
        {
            if(p<i)
            {
                r+=(i-p);
                p+=(i-p);
            }
            p+=v[i]-'0';
        }
        printf("Case #%d: %d\n", j, r);
    }
    return 0;
}
