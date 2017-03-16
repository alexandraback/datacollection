#include<bits/stdc++.h>
#define ll long long

using namespace std;

inline ll getnum()
{
    char c = getchar();
    ll num,sign=1;
    for(;c<'0'||c>'9';c=getchar())if(c=='-')sign=-1;
    for(num=0;c>='0'&&c<='9';)
    {
        c-='0';
        num = num*10+c;
        c=getchar();
    }
    return num*sign;
}

int dp[1005][1005];
int A[1005][1005];

int main()
{
    freopen ("B-large.in","r",stdin);
    freopen ("B-large.out","w",stdout);

    for(int i=0;i<=1000;i++)for(int j=0;j<=1000;j++)dp[i][j]=10000;
    for(int i=0;i<=1000;i++)dp[i][i]=0000;
    dp[1][0]=1;

    for(int i=1;i<=1000;i++)
    {
        for(int j=i-1;j>=i/2+(i%2);j--)
        {
            dp[i][j]=1;
        }
        for(int j=i/2;j>=0;j--)
        {
            for(int k1=j,k2=i-j;k1<=k2;k1++,k2--)
            {
                dp[i][j]=min(dp[i][j],dp[k1][j]+dp[k2][j]+1);
            }
        }
    }
/*
    for(int i=0;i<=10;i++)
    {
        for(int j=0;j<=i;j++)cout<<dp[i][j]<<' ';
        cout<<endl;
    }
*/
    int T=getnum();

    for(int cases=1;cases<=T;cases++)
    {
        memset(A,0,sizeof(A));
        int n=getnum(),ans=0,mx=0;

        for(int i=1;i<=n;i++)
        {
            int x=getnum();
            mx=max(mx,x);
            for(int i=0;i<=x;i++)A[x][i]+=dp[x][i];
        }
        ans=mx;
        for(int i=0;i<=mx;i++)
        {
            int y=0;
            for(int j=i;j<=mx;j++)y+=A[j][i];
            ans=min(ans,i+y);
        }
        printf("Case #%d: %d\n",cases,ans);
    }
}
