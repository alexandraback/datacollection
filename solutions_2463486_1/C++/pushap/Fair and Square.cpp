#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define MIn(a,b) a>b?b:a
#define MAx(a,b) a>b?a:b
//#define FOR(i,n) for(i=1;i<=n;i++)
#define S(n) scanf("%lld",&n)
#define P(n) printf("%lld",n)
#define sl(n) scanf("%lld",&n)
#define mod 1000000007
#define ull unsigned long long
using namespace std;
long long dp[10000000];
bool pal(long long i)
{
    char str[100];
    sprintf(str,"%lld",i);
    int l;
    l=strlen(str);
    int low=0;
    int high=l-1;
    while(low<=high)
    {
        if(str[low]==str[high])
        {
            low++;
            high--;
        }
        else
        return 0;
    }
    return 1;
}
int main()
{
    long long i,j,count=0,a,b,t,ans,ind=0;
    freopen("C-large-1.in","r",stdin);
    freopen("output.txt","w",stdout);
    for(i=1;i<=10000000;i++)
    {
        if(pal(i)&&pal(i*i))
        {
            dp[++count]=i*i;
        }
    }
   /* for(i=1;i<=count;i++)
    {
        printf("%lld\n",dp[i]);
    }
    printf("%lld\n",count);*/
    S(t);
    while(t--)
    {
        S(a);S(b);
        ans=0;
       //cout<<dp[1];
        for(i=1;i<=count;i++)
        {
            if(dp[i]>=a&&dp[i]<=b)
            ans++;
        }
        printf("Case #%lld: %lld\n",++ind,ans);
    }
   return 0;
}
