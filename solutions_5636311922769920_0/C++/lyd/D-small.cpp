#include <stdio.h>

int main()
{
    int T,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d:",(ca++));
        for(int i=1;i<=k;i++)
            printf(" %d",i);
        printf("\n");
    }
    return 0;
}

