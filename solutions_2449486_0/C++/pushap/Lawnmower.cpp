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
int a[105][105];
int dpr[105];
int dpc[105];
int main()
{
    int n,m,t,max,flag,count=1,i,j;
    freopen("B-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    S(t);
    while(t--)
    {
        S(n);S(m);
        flag=0;
        CLR(dpc);
        CLR(dpr);
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                S(a[i][j]);
            }
        }
        for(i=1;i<=n;i++)//row max
        {
            max=0;
            for(j=1;j<=m;j++)
            {
                if(a[i][j]>max)
                max=a[i][j];
            }
            dpr[i]=max;
        }
        for(j=1;j<=m;j++)//col max
        {
            max=0;
            for(i=1;i<=n;i++)
            {
                if(a[i][j]>max)
                max=a[i][j];
            }
            dpc[j]=max;
        }
        //////////////
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=m;j++)
            {
                if(a[i][j]<dpr[i]&&a[i][j]<dpc[j])
                {
                    flag=1;
                    //printf("%d %d\n",i,j);
                    break;
                }
            }
        }
        if(flag==1)
        {
            printf("Case #%d: NO\n",count++);
        }
        else
        {
            printf("Case #%d: YES\n",count++);
        }
    }
}
