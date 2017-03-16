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

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    LL ts,n,m,i,j,k,cnt,ans,l=0;
    double r,t,tmp;
    Sl(ts);
    while(ts--)
    {
        ans=0;
        Sf(r);  Sf(t);
        LL left=0,right=707106780,mid;

        while(left<=right)
        {
            mid=(left+right)/2;
            tmp=2*r*mid+ mid*(1+ (mid-1)*2);
            if(tmp<=t)
            {
                ans=max(ans,mid);
                left=mid+1;
            }
            else
            {
                right=mid-1;
            }
        }

        l++;
        printf("Case #%lld: %lld\n",l,ans);
    }
    return 0;
}

