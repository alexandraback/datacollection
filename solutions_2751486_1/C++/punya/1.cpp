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

char str[1000006];

bool check(char c)
{
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        return false;
    return true;
}

int main()
{
    freopen("A-large (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    int t,n,m,i,j,k,z;
    S(t);
    for(z=1;z<=t;z++)
    {
        scanf("%s",str);
        S(n);

        int l=strlen(str);

        LL ans=0;

        j=-1;  k=0;

        for(i=0;i<l;i++)
        {
            if(check(str[i]))
                k++;
            else
                k=0;

            if(k>=n)
                j=i;

            if(j>=0)
            {
                ans=ans+ (j-n+2);
            }
        }

        printf("Case #%d: %lld\n",z,ans);
    }
    return 0;
}
