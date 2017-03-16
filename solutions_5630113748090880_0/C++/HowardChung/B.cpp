#include <stdio.h>
#include <string.h>

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("aout.txt","w",stdout);

    int T;
    scanf("%d",&T);

    for(int cases = 1; cases <= T; cases++)
    {
        int cnt[2510];
        memset(cnt,0,sizeof(cnt));

        int n;
        scanf("%d",&n);

        for(int i = 0; i < (2*n-1)*n; i++)
        {
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }

        printf("Case #%d:",cases);
        for(int i = 1; i <= 2500; i++)
            if( cnt[i]%2 != 0 )
                printf(" %d",i);
        puts("");
    }

    return 0;
}
