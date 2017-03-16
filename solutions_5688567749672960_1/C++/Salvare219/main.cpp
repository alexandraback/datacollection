#include<bits/stdc++.h>
using namespace std;


int dp[10000000];
char s[20];
int rev(int x)sc
{
    sprintf(s,"%d",x);
    int n=strlen(s);
    for(int i=0;i<n/2;i++)
        swap(s[i],s[n-i-1]);
    sscanf(s,"%d",&x);
    return x;
}
void dfs()
{
    queue<int>q;
    q.push(1);
    for(int i=1;i<=10000000;i++)
        dp[i]=100000000;dp[1]=1;
    while(!q.empty())
    {
        int x=q.front();q.pop();
        if(dp[x+1]>dp[x]+1)
        {
            dp[x+1]=dp[x]+1;
            if(x<10000000)q.push(x+1);
        }
        int y=rev(x);
        if(dp[y]>dp[x]+1)
        {
            dp[y]=dp[x]+1;
            if(y<10000000)q.push(y);
        }
    }
}
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    dfs();
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n;scanf("%d",&n);
        printf("Case #%d: %d\n",ti++,dp[n]);
    }
    return 0;
}
