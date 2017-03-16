#include <cstdio>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <algorithm>
#include <map>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <utility>
#include <functional>
#include <sstream>
#include <list>
#include <complex>
#include <ctime>

#define maxlongint 2147483647
#define biglongint 2139062143
#define LL long long
#define ULL unsigned long long
#define p_b push_back
#define m_p make_pair
#define l_b lower_bound
#define w1 first
#define w2 second

using namespace std;

typedef pair<int,int> PII;
typedef pair<pair<int,int>,int> PIII;
typedef pair<pair<int,int>,pair<int,int> > PIIII;
typedef pair<double,double> PDD;
typedef pair<double,int> PDI;
typedef pair<string,int> PSI;
typedef pair<pair<double,double>,double> PDDD;
typedef pair<pair<double,double>,pair<double,double> > PDDDD;

int vi[10],vj[10],M,N,TT,K,sm,rc,fc,jc,xc,yc,ans;
int a[25][25],b[25],z[25][25],x[25],y[25];

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.out","w",stdout);
    vi[1]=-1,vj[1]=0;
    vi[2]=0,vj[2]=-1;
    vi[3]=0,vj[3]=1;
    vi[4]=1,vj[4]=0;
    scanf("%d",&TT);
    for (int gb=1;gb<=TT;gb++)
    {
        scanf("%d %d %d",&M,&N,&K);
        memset(b,0,sizeof(b));
        ans=maxlongint;
        while (b[0]==0)
        {
            memset(a,0,sizeof(a));
            sm=0;
            for (int i=1;i<=M;i++)
                for (int j=1;j<=N;j++)
                    a[i][j]=b[(i-1)*N+j],sm+=a[i][j];
            if (sm<ans)
            {
                memset(z,0,sizeof(z));
                rc=fc=1,x[1]=y[1]=0;
                z[0][0]=1;
                while (rc<=fc)
                {
                    for (int ic=1;ic<=4;ic++)
                    {
                        xc=x[rc]+vi[ic];
                        yc=y[rc]+vj[ic];
                        if ((xc>=0)&&(xc<=M+1)&&(yc>=0)&&(yc<=N+1)&&(a[xc][yc]==0)&&(z[xc][yc]==0))
                        {
                            z[xc][yc]=1;
                            ++fc,x[fc]=xc,y[fc]=yc;
                        }
                    }
                    ++rc;
                }
                if ((M+2)*(N+2)-fc>=K) ans=sm;
            }
            jc=M*N;
            while (b[jc]==1)
            {
                b[jc]=0;
                --jc;
            }
            b[jc]=1;
        }
        printf("Case #%d: %d\n",gb,ans);
    }
    return 0;
}
