/*Author:rednivrug15*/
#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define ll long long
#define MOD 1000000007

long long power(long long a,long long b,long long mod)
{
    long long ret=1;

    while(b)
    {
        if(b%2==1)
            ret=(ret*a)%mod;
        b/=2;
        a=(a*a)%mod;
    }
    return ret;
}

long long int gcd(long long int a,long long int b)
{
    return b==0?a:gcd(b,a%b);
}

int reverses(int n)
{
    int ans=0;
    while(n)
    {
        ans=ans*10+n%10;
        n/=10;
    }
    return ans;
}
int dp[1000001],rev[1000001];

int solve(int n,int finals)
{
    if(n>finals)
        return MOD;
    if(finals==n)
        return 1;
    if(dp[n]!=0)
        return dp[n];
    if(rev[n]>n && rev[n]<=finals)
     return dp[n]=1+min(solve(rev[n],finals),solve(n+1,finals));

    return dp[n]=1+solve(n+1,finals);
}

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    for(int i=1; i<=1000000; i++) rev[i]=reverses(i);
    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        int n;
        memset(dp,0,sizeof dp);
        scanf("%d",&n);
        printf("Case #%d: %d\n",cases,solve(1,n));
        //for(int i=1; i<=23; i++) printf("%d %d\n",n,dp[i]);
    }

    return 0;
}
