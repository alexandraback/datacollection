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
int ans[1001][1001];

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

        	for(int lefts=1; lefts<=j; lefts++)
        		for(int rights=1; rights<=n-j; rights++)
        		 if(ans[j][lefts]!=MOD && ans[n-j][rights]!=MOD)
        		 	ans[n][1+max(lefts+ans[n-j][rights],rights+ans[j][lefts])]=min(ans[n][1+max(lefts+ans[n-j][rights],rights+ans[j][lefts])],1+ans[j][lefts]+ans[n-j][rights]);

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

int main()
{
    freopen("inp.txt","r",stdin);
    freopen("op.txt","w",stdout);

    for(int i=1; i<=1000; i++)
    {
        for(int j=1; j<=i; j++)
            ans[i][j]=-1;
    }

    for(int i=1; i<=1000; i++)
        ans[i][i]=0;

    FILE *check=fopen("check.txt","r");

    for(int i=0; i<=1000; i++)
    {
        for(int j=0; j<=1000; j++)
            fscanf(check,"%d",&ans[i][j]);
    }

    for(int i=0; i<=1000; i++)
        for(int j=0; j<=1000; j++)
          if(ans[i][j]==-1)
            ans[i][j]=MOD;
    int t;
    scanf("%d",&t);

    for(int cases=1; cases<=t; cases++)
    {
        printf("Case #%d: ",cases);

        int n;
        scanf("%d",&n);

        int P[n+1];
        for(int i=1; i<=n; i++)
            scanf("%d",&P[i]);
        int maxn=*max_element(P+1,P+n+1);

        for(int i=1; i<=n; i++)
            for(int j=1; j<=maxn; j++)
             sumans[i][j]=MOD;


		for(int i=1; i<=maxn; i++)
			sumans[1][i]=ans[P[1]][i];

        for(int i=2; i<=n; i++)
        {
            for(int j=1; j<=P[i]; j++)
            {
                if(ans[P[i]][j]!=MOD)
                {
                    for(int k=1; k<=maxn; k++)
                        if(sumans[i-1][k]!=MOD && max(j+sumans[i-1][k],k+ans[P[i]][j])<=maxn)
                        {
                            sumans[i][max(j+sumans[i-1][k],k+ans[P[i]][j])]=min(sumans[i][max(j+sumans[i-1][k],k+ans[P[i]][j])],sumans[i-1][k]+ans[P[i]][j]);
                            //printf("%d %d %d %d %d--\n",i,j,k,max(j+sumans[i-1][k],k+ans[P[i]][j]),sumans[i-1][k]+ans[P[i]][j]);
                        }
                }
            }
        }

        int realans=maxn;

        for(int i=1; i<=maxn; i++)
        {
            if(sumans[n][i]!=MOD)
            {
                //printf("%d--%d\n",i,sumans[n][i]);
                realans=i;
                break;
            }
        }
        printf("%d\n",realans);
    }
    return 0;
}
