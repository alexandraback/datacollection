#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <queue>
#include <cstdio>
using namespace std;
#define N 60
typedef __int64 ll;
ll a[N][N];
ll fange[N];
int main()
{
    ll T,n,i,i1=1,j;
    ll k,p;
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    scanf("%I64d",&T);
    fange[0]=1;
    fange[1]=2;
    for(i=2;i<=50;i++)
        fange[i]=fange[i-1]*2;
    while(T--)
    {
        memset(a,0,sizeof(a));
        scanf("%I64d%I64d",&n,&k);
        printf("Case #%I64d: ",i1++);
        if(k>fange[n-2])
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        if(k>0)
        {
            k--;a[1][n]=1;
        }
        for(i=2;i<n;i++)
        {
            a[i][n]=1;
            for(j=2;j<i;j++)
            {
                a[i][j]=1;
            }
        }
        p=2;
        while(k&&p<n)
        {
            if(k&1)
            {
                a[1][p]=1;
            }
            k>>=1;
            p++;
        }
        if(!k)
            printf("POSSIBLE\n");
        else
        {
            printf("IMPOSSIBLE\n");
            continue;
        }
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
                printf("%I64d",a[i][j]);
            printf("\n");
        }
    }
    return 0;
}
