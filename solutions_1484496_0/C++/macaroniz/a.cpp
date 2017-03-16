#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1200*1200];
int T,N;
int arr[25];
int hash[2000000];
int maxState;
int calc(int state)
{
    int ret = 0;
    for(int i = 0;(1 << i) < maxState;i++)
    {
        if((state & (1 << i)) != 0)
        {
            ret += arr[i];
        }
    }
    return ret;
}
int OUT(int state)
{
    for(int i = 0;(1 << i) < maxState;i++)
    {
        if((state & (1 << i)) != 0)
            printf("%d ",arr[i]);
    }
    printf("\n");
}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%d",&T);
    for(int cas = 1;cas <= T;cas++)
    {
        memset(dp,0,sizeof dp);
        memset(hash,0xff,sizeof hash);
        scanf("%d",&N);
        for(int i = 0;i < N;i++)
            scanf("%d",&arr[i]);
        maxState = 1 << N;
        bool flag = false;
        printf("Case #%d:\n",cas);
        for(int state = 1;state < maxState;state++)
        {
            int sum = calc(state);
            if(hash[sum] != -1)
            {
                OUT(hash[sum]);
                OUT(state);
                flag = true;
                break;
            }
            hash[sum] = state;
        }
        if(!flag)
        {
            printf("Impossible\n");
        }
    }
    fclose(stdin);
    fclose(stdout);
}
