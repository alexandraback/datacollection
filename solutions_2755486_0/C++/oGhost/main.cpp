#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

#define dx 1100000

struct data
{
    int d,n,w,e,s;
    int dd,dp,ds;
};

data a[1111];
data b[1111];

int w[6333033];
int dw[6330333];


bool cmp(const data &f,const data &g)
{
    return f.d<g.d;
}

void dww()
{
    int k;
    for(k=0;k<=3*dx;k++)
                    dw[k]=w[k];
}

void wdw()
{
    int k;
    for(k=0;k<=3*dx;k++)
        w[k]=dw[k];
}

int main()
{
    int cases,o,n,i,m,j,ans,k;
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C-small-attempt1.out","w",stdout);
    scanf("%d",&cases);
    for(o=1;o<=cases;o++)
    {
        scanf("%d",&n);
        memset(w,0,sizeof(w));
        for(i=1;i<=n;i++)
        {
            scanf("%d%d%d%d%d%d%d%d",&a[i].d,&a[i].n,&a[i].w,&a[i].e,&a[i].s,&a[i].dd,&a[i].dp,&a[i].ds);
            a[i].w*=2;
            a[i].e*=2;
            a[i].dp*=2;
        }
        m=0;
        for(i=1;i<=n;i++)
        {
            m++;
            b[m].d=a[i].d;
            b[m].w=a[i].w;
            b[m].e=a[i].e;
            b[m].s=a[i].s;
            for(j=2;j<=a[i].n;j++)
            {
                m++;
                b[m].d=b[m-1].d+a[i].dd;
                b[m].w=b[m-1].w+a[i].dp;
                b[m].e=b[m-1].e+a[i].dp;
                b[m].s=b[m-1].s+a[i].ds;
            }
        }
        sort(b+1,b+1+m,cmp);

        ans=0;
        for(i=1;i<=m;i++)
        {

            dww();
            for(j=i;j<=m && b[j].d==b[i].d;j++)
            {



                bool flag=false;
                for(k=dx+b[j].w;k<=dx+b[j].e;k++ )
                if(w[k]<b[j].s)
                {
                    flag=true;
                    if(b[j].s>dw[k])
                    {
                        dw[k]=b[j].s;
                    }
                }

                if(flag)
                    ans++;


            }
            i=j-1;


            wdw();

        }
        printf("Case #%d: ",o);
        cout<<ans<<endl;
        printf("%d\n",ans);
    }
    return 0;
}
