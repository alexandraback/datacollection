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
        if( k > c * s )
        {
            printf(" IMPOSSIBLE\n");
            continue;
        }
        int iIdx = 0;
        for(int i=0;i*c<k;i++)
        {
            long long p = 0;
            for(int j=0;j<c;j++)
            {
                p*=k;
                if( iIdx < k )
                    p+=(iIdx++);
            }
            printf(" %lld",p+1);
        }
        printf("\n");
    }
    return 0;
}

