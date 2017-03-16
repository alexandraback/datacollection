# include<cstdio>
# include<iostream>
# include<vector>

using namespace std;

# define N 1000010
int dp[N];

void init()
{
    dp[1]=1;
    for(int i=2;i<=N-10;i++)
    {
        int tmp=i;
        int val=0;
        while(tmp)
        {
            val=val*10+tmp%10;
            tmp/=10;
        }
        if(i%10 != 0 && val < i)     dp[i]=min(dp[i-1]+1,dp[val]+1);
        else    dp[i]=dp[i-1]+1;
        //if(i<=30)   printf("num:%d %d\n",i,dp[i]);
    }
    for(int i=2;i<=N-10;i++)
    {
        int tmp=i;
        int val=0;
        while(tmp)
        {
            val=val*10+tmp%10;
            tmp/=10;
        }
        if(val > i)     dp[i]=min(dp[i],dp[val]);
    }
}
int main()
{
    //freopen("A-small-attempt0.in","r",stdin);
    //freopen("out.out","w",stdout);
    init();
    int test;scanf("%d",&test);
    for(int T=1;T<=test;T++)
    {
        int n;scanf("%d",&n);
        printf("case #%d: %d\n",T,dp[n]);
    }
    return 0;
}
