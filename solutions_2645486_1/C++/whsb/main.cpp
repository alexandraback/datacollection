#include <iostream>
#include <cstdio>
#include <map>
#include <math.h>
#include <string.h>
using namespace std;

int dp[20][10],N,E,R,v[20000];

int cal(int x)
{
    if(x>E) return E;
    return x;
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d%d",&E,&R,&N);
        for(int i=0;i<N;i++) scanf("%d",&v[i]);

        long long ans=0,tmpE=E,useE;
        for(int i=0;i<N;i++)
        {
            int flag=0;
            for(int j=i+1;j<N;j++)
            {
                if((long long)R*(long long)(j-i)>=(long long)E) break;
                if(v[j]>v[i])
                {
                    flag=1;break;
                }
            }
            if(flag)
            {
                useE=max(0LL,tmpE+R-E);

            }
            else
            {
                useE=tmpE;
            }
            ans+=useE*(long long)v[i];
            tmpE=tmpE-useE+R;
        }
        printf("Case #%d: ",cas);
        cout<<ans<<endl;
        /*
        memset(dp,0,sizeof(dp));
        for(int i=0;i<N;i++)
        {
            for(int j=1;j<=E;j++)
            {
                for(int k=0;k<=j;k++)
                {
                    dp[i+1][cal(j-k+R)]=max(dp[i+1][cal(j-k+R)],dp[i][j]+k*v[i]);
                }
            }
        }
        int ans=0;
        for(int i=0;i<=N;i++)
        for(int j=0;j<=E;j++)
        ans=max(ans,dp[i][j]);
        printf("Case #%d: %d\n",cas,ans);
        */
    }
    return 0;
}
