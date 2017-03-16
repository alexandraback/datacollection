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
#define S(n) scanf("%d",&n)
#define P(n) printf("%d",n)
#define sl(n) scanf("%lld",&n)
#define mod 1000000007
#define ull unsigned long long
using namespace std;
int main()
{
    freopen("B-small-attempt0 (1).in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    int x,y,flag=0,i,count=0;
    S(t);
    while(t--)
    {
     printf("Case #%d: ",++count);

    S(x);S(y);
    if(x>0)
    {
        for(i=1;i<=x;i++)
        {
            printf("WE");

        }

    }
    else
    {
        for(i=1;i<=x*-1;i++)
        {
            printf("EW");

        }
    }
    if(y>0)
    {

        for(i=1;i<=y;i++)
        {

                printf("SN");
        }
    }
    else
    {

        for(i=1;i<=y*-1;i++)
        {

                printf("NS");
        }
    }
    printf("\n");
    }
    return 0;
}
