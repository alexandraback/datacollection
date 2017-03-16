#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <set>
#include <vector>
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int E,R,n;
struct AA
{
    int i;
    long long v;
}a[100010];
bool cmp(AA a,AA b)
{
    return a.v>b.v;
}

int tre[100010];
void update(int idx,int v)
{
    if (idx==0) return;
    while (idx<=n)
    {
        tre[idx]+=v;
        idx+=idx&-idx;
    }
}
int read(int idx)
{
    int ret=0;
    while (idx>0)
    {
        ret+=tre[idx];
        idx-=idx&-idx;
    }
    return ret;
}
int readk(int k)
{
    if (k>read(n)) return 0;
    if (k==0) return 0;
    int idx=1;
    while (tre[idx]<k)
    {
       // cout<<idx<<endl;
        while (idx+(idx&-idx)<=n && tre[idx+(idx&-idx)]<k)
        {
            idx+=idx&-idx;
        }
        k-=tre[idx];
        idx++;
    }
    return idx;
}


int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int cas=1;
    int T;
    scanf("%d",&T);
    while (T--)
    {
        //cout<<T<<endl;
        scanf("%d%d%d",&E,&R,&n);
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i].v);
            a[i].i=i;
        }
        sort(a+1,a+1+n,cmp);

        long long ans=0;
        for (int i=1;i<=n;i++) tre[i]=0;
        for (int i=1;i<=n;i++)
        {
           int x,pre;
           pre=readk(read(a[i].i));
           if (pre==0)
           {
               x=E;
           }
           else
           {
               x=min(E,(a[i].i-pre)*R);
           }
          // cout<<x<<endl;
           int nxt;
           nxt=readk(read(a[i].i)+1);
           if (nxt==0)
           {
               ans+=a[i].v*x;
           }
           else
           {
               ans+=a[i].v*max(0,min(x,x+(nxt-a[i].i)*R-E));
           }
         //  cout<<x<<' '<<pre<<' '<<nxt<<endl;
           update(a[i].i,1);
         //  cout<<x<<endl;
        }
        printf("Case #%d: %lld\n",cas++,ans);
    }
}
