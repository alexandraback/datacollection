#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
#include <time.h>
#include <cstdlib>
#include <cmath>
#include <iostream>
using namespace std;
#define mp make_pair
#define pii pair<int,int>
#define pb push_back
#define eps 1e-6

int start[5000001],ti[5000001],tot;

int calc(double Ti)
{
    int ret=0;
    for (int i=1;i<=tot;++i)
    {
        if (Ti<ti[i])
        {
            if (ti[i]*(360-start[i])>=Ti*360) ++ret;
        }
        else if (Ti>ti[i])
        {
            if (ti[i]*(720-start[i])<=Ti*360)
            {
                ++ret;
                Ti-=ti[i]*(720-start[i])*1./360;
                ret+=Ti/ti[i];
            }
        }
    }
    return ret;
}

int test()
{
    if (start[1]>start[2]||(start[1]==start[2]&&ti[1]<ti[2]))
    {
        swap(start[1],start[2]);
        swap(ti[1],ti[2]);
    }
    if (ti[1]<ti[2])
    {
        if (1ll*ti[1]*(720-start[1])<=1ll*ti[2]*(360-start[2]))
        {
            return 1;
        }
    }
    else if (ti[1]>ti[2])
    {
        if (1ll*ti[1]*(360-start[1])>=1ll*ti[2]*(720-start[2])) return 1;
    }
    return 0;
}

int main()
{
    freopen("C.in","r",stdin);
    freopen("C.txt","w",stdout);
    int t,n,d[1111],h[1111],m[1111];
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        tot=0;
        scanf("%d",&n);
        for (int i=1;i<=n;++i)
        {
            scanf("%d%d%d",d+i,h+i,m+i);
            for (int j=1;j<=h[i];++j)
            {
                start[++tot]=d[i];
                ti[tot]=m[i]+j-1;
            }
        }
        printf("Case #%d: ",cas);
        if (tot==1) puts("0");
        else
        {
            printf("%d\n",test());
//            int ans=999999999;
//            double l=1,r=100000000;
//            while (fabs(r-l)>1e-4)
//            {
//                double mid1=(l+r)/2,mid2=(mid1+r)/2;
//                int tmp1,tmp2;
//                tmp1=calc(mid1);
//                tmp2=calc(mid2);
//                if (tmp1<tmp2) r=mid2,ans=min(ans,tmp1);
//                else l=mid1,ans=min(ans,tmp2);
//            }
//            printf("%d\n",ans);
        }
    }
    return 0;
}
