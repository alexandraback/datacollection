#include <iostream>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <functional>
#include <queue>
#include <vector>
#include <cstdlib>
#include <string>
#define N 10010
using namespace std;
long long v[N];
long long s[N],last[N];
int trees[N],treet[N];
int set[N];
int lowbit(int x)
{
    return x&(-x);
}
void updates(int k,int val)
{
    while(k)
    {
        trees[k]+=val;
        k-=lowbit(k);
    }
}
int get_vals(int k)
{
    int ret=0;
    while(k<N)
    {
        ret+=trees[k];
        k+=lowbit(k);
    }
    return ret;
}
void updatet(int k,int val)
{
    while(k)
    {
        treet[k]+=val;
        k-=lowbit(k);
    }
}
int get_valt(int k)
{
    int ret=0;
    while(k<N)
    {
        ret+=treet[k];
        k+=lowbit(k);
    }
    return ret;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t,T=0;
    scanf("%d",&t);
    while(t--)
    {
        int E,R,n;
        scanf("%d%d%d",&E,&R,&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&v[i]);
        long long ans=0;
        if(R>=E)
        {
            for(int i=1;i<=n;i++)
                ans+=v[i]*E;
        }
        else
        {
            memset(trees,0,sizeof(trees));
            memset(treet,0,sizeof(treet));
            for(int i=1;i<=n;i++)
                set[i]=i;
            ans+=v[1]*E;
            updates(1,E);
            for(int i=2;i<=n;i++)
            {
                int now=get_valt(i-1)+R;
                updates(i,now);updates(i-1,-now);
                ans+=now*v[i];
                int ned=E-now,p=i-1;
                while(p>=1&&ned>0&&v[i]>=v[p])
                {
                    int eat=get_vals(p)-get_valt(p);
                    int hh=min(eat,ned);
                    ans+=v[i]*ned-v[p]*ned;
                    updatet(i-1,hh);updatet(p-1,-hh);
                    updates(i,hh);updates(p,-hh);
                    ned-=hh;
                    p--;
                }
            }
        }
        printf("Case #%d: %lld\n",++T,ans);
    }
    return 0;
}
