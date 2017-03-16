#include <cstdio>
#include<memory.h>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
long long mpfeji[105][105];
long long nopd[105][105];
long long mped[105][105];
struct mps
{
    long long t,v;
} a[105],b[105];
long long pijdd(long long a,long long b)
{
    return a>b?a:b;
}
long long moedcc(long long a,long long b)
{
    return a<b?a:b;
}
int main()
{
    freopen("C-large.in","r",stdin);
    freopen("ddut.txt","w",stdout);
    int i,j,k,t,n;
    int m,mpde=1,x,y;scanf("%d",&t);
    while(t--)
    {
memset(nopd,0,sizeof(nopd));
memset(mped,0,sizeof(mped));
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
        {
scanf("%lld%lld",&a[i].v,&a[i].t);nopd[a[i].t][i+1]=a[i].v;
        }
        for (i=0; i<n; i++)
            for (k=0; k<=100; k++)
                nopd[k][i+1]+=nopd[k][i];
        for (i=0; i<m; i++)
        {
scanf("%lld%lld",&b[i].v,&b[i].t);
    mped[b[i].t][i+1]=b[i].v;
        }
        for (i=0; i<m; i++)
for (k=0; k<=100; k++)
                mped[k][i+1]+=mped[k][i];
memset(mpfeji,0,sizeof(mpfeji));

        for (i=1; i<=n; i++)
            for (j=1; j<=m; j++)
            {
                if (a[i-1].t!=b[j-1].t)
                {
                    mpfeji[i][j]=pijdd(mpfeji[i-1][j],mpfeji[i][j-1]);
                }
                else
                {
                    for (x=0; x<i; x++)
                        for (y=0; y<j; y++)
                            mpfeji[i][j]=pijdd(mpfeji[i][j],mpfeji[x][y]+moedcc(nopd[a[i-1].t][i]-nopd[a[i-1].t][x],mped[b[j-1].t][j]-mped[b[j-1].t][y]));
                }
            }

        long long mpode=0;
        for (i=0; i<=n; i++)
            for (j=0; j<=m; j++)
                mpode=pijdd(mpode,mpfeji[i][j]);
        printf("Case #%d: %lld\n",mpde++,mpode);
    }
    return 0;
}
