#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num[2510];

int main()
{
    int i,n,t,T,tmp;
    scanf("%d",&T);
    for (t=1;t<=T;t++)
    {
        printf("Case #%d: ",t);
        scanf("%d",&n);
        memset(num,0,sizeof(num));
        for (i=0;i<(2*n-1)*n;i++)
        {
            scanf("%d",&tmp);
            num[tmp]++;
        }
        for (i=1;i<=2500;i++)
            if (num[i]&1)
                printf("%d ",i);
        printf("\n");
    }
}
