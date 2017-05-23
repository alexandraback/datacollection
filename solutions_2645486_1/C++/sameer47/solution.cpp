#include <iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <list>
#include <stack>
#include <bitset>
#include <string>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <ctime>

#define ALL(i,n)    for(i = 0; i < (n); i++)
#define FOR(i,a,b)  for(i = (a); i < (b); i++)
#define SET(p)      memset(p,-1,sizeof(p))
#define CLR(p)      memset(p,0,sizeof(p))
#define S(n)	    scanf("%d",&n)
#define P(n)	    printf("%d\n",n)
#define Sl(n)	    scanf("%lld",&n)
#define Pl(n)	    printf("%lld\n",n)
#define Sf(n)       scanf("%lf",&n)
#define Ss(n)       scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
using namespace std;

LL val[10005],e,r;

LL func(LL i,LL n,LL e,LL r,LL me)
{
    if(i>n)
        return 0;

    LL j,ans=0;
    for(j=0;j<=e;j++)
    {
        ans=max(ans,j*val[i] + func(i+1,n,min(e+r-j,me),r,me) );
    }

    return ans;
}

LL solve(LL s,LL f,LL le,LL re)
{
    //printf("%lld %lld %lld %lld\n",s,f,le,re);
    if(s>f)
        return 0;

    LL ans=0;
    if(s==f)
    {
        if(le+r>re)
            ans= val[s]*(le+r-re);
        else
            ans= 0;
    }

    LL j,p,mx=0;
    for(j=s;j<=f;j++)
    {
        if(val[j]>mx)
        {
            mx=val[j];
            p=j;
        }
    }

    if(r*(f-p+1)>=re)
    {
        if(le+ r*(p-s)>=e)
            ans= e*val[p] + solve(s,p-1,le,e) + solve(p+1,f,r,re);
        else
            ans= (le+ r*(p-s))*val[p] + solve(p+1,f,r,re);
    }
    else
    {
        LL rem=re- r*(f-p+1);
        if(le+ r*(p-s)>=e)
            ans= (e-rem)*val[p] + solve(s,p-1,le,e) + solve(p+1,f,r+rem,re);
        else
            ans= (le+ r*(p-s) -rem)*val[p] + solve(p+1,f,r+rem,re);
    }

    //printf("       %lld %lld %lld %lld %lld\n",s,f,le,re,ans);
    return ans;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    LL t,n,m,i,j,k,l=0;
    Sl(t);
    while(t--)
    {
        Sl(e);  Sl(r);  Sl(n);
        r=min(r,e);
        for(i=1;i<=n;i++)
        {
            Sl(val[i]);
        }

        l++;
        //printf("Case #%lld: %lld\n",l,func(1,n,e,r,e));

        printf("Case #%lld: %lld\n",l,solve(1,n,e,r));
    }
    return 0;
}

