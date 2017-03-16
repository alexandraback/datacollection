#include<cstdio>
#include<cmath>
#include<stdlib.h>
#include<map>
#include<set>
#include<time.h>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;
#define eps 1e-8
long long qpow(long long x,int k)
{
    long long ans=1;
    while(k)
    {
        if(k&1)
            ans*=x;
        k>>=1;
        x*=x;
    }
    return ans;
}
int main()
{
//    freopen("D-small-attempt0.in","r",stdin);
//    freopen("D-small-attempt0.out","w",stdout);
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int T;
    scanf("%d",&T);
    for(int cas=1; cas<=T; cas++)
    {
        int k,c,s;
        scanf("%d%d%d",&k,&c,&s);
        printf("Case #%d: ",cas);
        if(s*c<k)
            printf("IMPOSSIBLE\n");
        else
        {
            if(c>=k)
            {
                long long now=1;
                long long step=1LL;
                for(int i=1; i<=k; i++)
                {
                    now=(now-1)*k+i;
                }
                for(int i=k+1; i<=c; i++)
                {
                    now=(now-1)*k+1;
                }
                printf("%I64d\n",now);
            }
            else
            {
                long long now=1LL;
                int tim=(k/c)+(k%c==0?0:1);
                long long ans[105];
                int d=0;
                long long step=0;
                for(int t=1; t<tim; t++)
                {

                    long long now=1;
                    for(int i=2; i<=c; i++)
                    {
                        now=(now-1)*k+d+i;
                    }
                    ans[t]=now+step;
                    step+=qpow(k,c-1)*c;
                    d+=c;
                }
                ans[tim]=qpow(k,c)-ans[1]+1;
                for(int i=1;i<=tim;i++)
                    printf("%I64d ",ans[i]);
                printf("\n");
            }
        }
    }
    return 0;
}
