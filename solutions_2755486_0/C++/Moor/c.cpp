#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#define MAXN 1010
#define MP(x,y) make_pair((x),(y))
using namespace std;
struct _no
{
    int n,w,e,s;
    bool operator <(const _no &b)const
    {
        return n<b.n;
    }
    void add(int nn,int ww,int ee,int ss)
    {
        n=nn,w=ww,e=ee,s=ss;
    }
}no[MAXN];
int ni[MAXN],di[MAXN],ddi[MAXN],wi[MAXN],ei[MAXN],si[MAXN],dpi[MAXN],dsi[MAXN];
int lis[MAXN],ltop,ntop,tlis[MAXN];
int wall[MAXN],twall[MAXN];
int bs(int key,int r)
{
    int l=0,mid;
    while(l<r)
    {
        mid=(l+r)/2;
        if(lis[mid]>=key)   r=mid;
        else    l=mid+1;
    }
    return l;
}
int main()
{
    freopen("/home/moor/Code/input.txt","r",stdin);
    freopen("/home/moor/Code/output.txt","w",stdout);
    int ncase,nn,ans;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d",&nn);
        for(int i=0;i<nn;++i)
            scanf("%d%d%d%d%d%d%d%d",&di[i],&ni[i],&wi[i],&ei[i],&si[i],&ddi[i],&dpi[i],&dsi[i]);
        ltop=0;
        ntop=0;
        for(int i=0;i<nn;++i)
            for(int j=0;j<ni[i];++j)
            {
                no[ntop].add(di[i]+j*ddi[i],wi[i]+j*dpi[i],ei[i]+j*dpi[i],si[i]+j*dsi[i]);
                ++ntop;
                lis[ltop++]=wi[i]+j*dpi[i],lis[ltop++]=ei[i]+j*dpi[i];
            }
        sort(lis,lis+ltop);
        int tmp=0;
        tlis[0]=lis[0];
        for(int i=1;i<ltop;++i)
            if(lis[i]!=lis[i-1])
                tlis[++tmp]=lis[i];
        ltop=tmp+1;
        for(int i=0;i<ltop;++i)
        {
            lis[2*i]=2*tlis[i];
            if(i+1<ltop)
                lis[2*i+1]=tlis[i]+tlis[i+1];
        }
        ltop=2*ltop-1;
        ans=0;
        sort(no,no+ntop);
        memset(wall,0,sizeof(wall));
        memset(twall,0,sizeof(twall));
        for(int i=0;i<ntop;++i)
        {
            bool f=0;
            int l=bs(no[i].w*2,ltop),r=bs(no[i].e*2,ltop);
            if(i&&no[i].n>no[i-1].n)
                for(int j=0;j<ltop;++j)
                    wall[j]=max(wall[j],twall[j]);
            for(;l<=r;++l)
                if(wall[l]<no[i].s)
                {
                    twall[l]=max(no[i].s,twall[l]);
                    if(!f)
                        f=1,++ans;
                }
        }
        printf("Case #%d: %d\n",h,ans);
    }
    return 0;
}
