#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#define mod 1000000007
using namespace std;

long long tree[50000],a[10010];

void build(int l,int r,int pos)
{
    if(l==r)
    {
        tree[pos]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(l,mid,pos*2);
    build(mid+1,r,pos*2+1);
    tree[pos]=max(tree[pos*2],tree[pos*2+1]);
    return;
}

int query(long long num,int x,int l,int r,int pos)
{
    if(l==r)
    {
        if(tree[pos]<num)
            return -1;
        else
            return l;
    }
    int mid=(l+r)/2,temp;
    if(x<=mid)
    {
        temp=query(num,x,l,mid,pos*2);
        if(temp>0)
            return temp;
        return query(num,x,mid+1,r,pos*2+1);
    }
    else
        return query(num,x,mid+1,r,pos*2+1);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=0,i;
    long long E,R,n,x,y,r;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld%lld%lld",&E,&R,&n);
        memset(tree,0,sizeof(tree));
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        a[n+1]=0;
        build(1,n+1,1);
        long long now=E,ans=0;
        for(i=1;i<=n;i++)
        {
            x=query(a[i],i+1,1,n+1,1);
            if(x==-1)
            {
                ans=ans+now*a[i];
                now=R;
                continue;
            }
            y=(x-i)*R;
            if(y>=E)
            {
                ans=ans+now*a[i];
                now=R;
            }
            else
            {
                r=E-y;
                if(now>r)
                {
                    ans=ans+(now-r)*a[i];
                    now=r+R;
                }
                else
                    now=now+R;
            }
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
