#include <stdio.h>
#include <string.h>

int main()
{
    int T,ca=1;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        int cnt[2510];
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<2*n-1;i++)
        {
            for(int j=0;j<n;j++)
            {
                int p;
                scanf("%d",&p);
                cnt[p]++;
            }
        }
        printf("Case #%d:",(ca++));
        for(int i=0;i<=2500;i++)
        {
            if(cnt[i] % 2 != 0)
                printf(" %d",i);
        }
        printf("\n");
    }
    
    return 0;
}

