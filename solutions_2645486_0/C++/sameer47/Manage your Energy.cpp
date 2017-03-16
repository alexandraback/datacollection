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

LL val[15];

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

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    LL t,n,m,i,j,k,e,r,l=0;
    Sl(t);
    while(t--)
    {
        Sl(e);  Sl(r);  Sl(n);
        for(i=1;i<=n;i++)
        {
            Sl(val[i]);
        }

        l++;
        printf("Case #%lld: %lld\n",l,func(1,n,e,r,e));

    }
    return 0;
}

