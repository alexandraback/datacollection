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

int mt[200];

int main()
{
    int t,n,m,a,i,j,k,count=0;
    freopen("A-small-attempt1.in","r",stdin);
    freopen("output.txt","w",stdout);

    S(t);
    while(t--)
    {
        S(a);  S(n);
        for(i=1;i<=n;i++)
            S(mt[i]);

        sort(mt+1,mt+n+1);

        if(a==1)
        {
            printf("Case #%d: %d\n",++count,n);
            continue;
        }

        int ans=n,tmp=0;
        i=1;
        while(i<=n)
        {
            //printf("    %d %d\n",a,mt[i]);
            if(mt[i]<a)
            {
                a+=mt[i];
                ans=min(ans,tmp+n-i);
            }
            else
            {
                ans=min(ans,tmp+n-i+1);
                while(a<=mt[i])
                {
                    a=a+a-1;
                    tmp++;
                }
                a+=mt[i];
                ans=min(ans,tmp+n-i);
            }

            i++;
        }

        printf("Case #%d: %d\n",++count,ans);
    }
    return 0;
}
