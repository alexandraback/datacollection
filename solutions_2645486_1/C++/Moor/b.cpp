#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#define DBLE 1e-8
#define PI 3.1415926535898
#define INF 1000000000
#define MAXN 100010
#define MP(x,y) (make_pair((x),(y)))
#define FI first
#define SE second
using namespace std;
int v[MAXN],lef[MAXN];
int main()
{
//    freopen("J:\\MyDocument\\Code\\input.txt","r",stdin);
//    freopen("J:\\MyDocument\\Code\\output3.txt","w",stdout);
    int ncase;
    int e,r,n,now,pre;
    long long ans;
    scanf("%d",&ncase);
    for(int h=1;h<=ncase;++h)
    {
        scanf("%d%d%d",&e,&r,&n);
        memset(lef,0,sizeof(lef));
        for(int i=0;i<n;++i)
            scanf("%d",&v[i]);
        now=0,pre=v[n-1];
        for(int i=n-1;i>=0;--i,now+=r)
        {
            if(v[i]<pre&&now<e)
                lef[i]=e-now;
            else    lef[i]=0,now=0,pre=v[i];
            if(i<n-1&&v[i]<v[i+1])
                lef[i]=max(lef[i],e-r);
        }
        ans=0;
        now=e;
        for(int i=0;i<n;++i,now=min(now+r,e))
            if(now>lef[i])
                ans+=(long long)(now-lef[i])*v[i],now=lef[i];
        printf("Case #%d: ",h);
        cout<<ans<<'\n';
    }
    return 0;
}
