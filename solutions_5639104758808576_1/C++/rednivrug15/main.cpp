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

int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

pair < int , int > dp[1001];
int ans[1001][1001],M[1001],m[1001];

pair < int , int > solve(int n)
{
    if(n==1) return mp(1,0);

    if(dp[n].first!=0)
        return dp[n];

    dp[n].first=n;
    dp[n].second=0;

    for(int i=1; i<=n; i++)
    {
        pair < int, int > x=solve(n-i);
        if(x.first+i<=1000)
         ans[n][x.first+i]=min(ans[n][x.first+i],x.second);

        if(x.first + i<dp[n].first)
        {
            dp[n].first=x.first+i;
            dp[n].second=x.second;
        }
        else if( x.first+ i==dp[n].second)
            dp[n].second=min(dp[n].second,x.second);
    }

    for(int j=1; j<n; j++)
    {
            pair < int, int > x=solve(j);
            pair < int, int > y=solve(n-j);

        	for(int lefts=m[j]; lefts<=M[j]; lefts++)
        		for(int rights=m[n-j]; rights<=M[n-j]; rights++)
        		 if(ans[j][lefts]!=MOD && ans[n-j][rights]!=MOD)
                 {
        		 	ans[n][1+max(lefts+ans[n-j][rights],rights+ans[j][lefts])]=min(ans[n][1+max(lefts+ans[n-j][rights],rights+ans[j][lefts])],1+ans[j][lefts]+ans[n-j][rights]);
        		 	m[n]=min(m[n],1+max(lefts+ans[n-j][rights],rights+ans[j][lefts]));
        		 	M[n]=max(M[n],1+max(lefts+ans[n-j][rights],rights+ans[j][lefts]));
                 }

            if(1+ max(x.first+y.second,y.first+x.second)<dp[n].first)
            {
                dp[n].first=1+ max(x.first+y.second,y.first+x.second);
                dp[n].second=1+x.second+y.second;
            }

            else if(1+ max(x.first+y.second,y.first+x.second)==dp[n].first)
                dp[n].second=min(dp[n].second,1+x.second+y.second);
    }
    return dp[n];
}

int sumans[1001][1001];
int hashe[10011];

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        printf("Case #%d: ",cases);
        int n;
        scanf("%d",&n);
        char str[10011];

        scanf("%s",str);
        memset(hashe,0,sizeof hashe);

        int alreadystanding=0,friends=0;

        for(int i=0; str[i]!='\0'; i++)
        {
            if(alreadystanding<i)
            {
                friends+=i-alreadystanding;
                alreadystanding=i;
            }
            alreadystanding+=str[i]-'0';
        }
        printf("%d\n",friends);
    }


    return 0;
}
