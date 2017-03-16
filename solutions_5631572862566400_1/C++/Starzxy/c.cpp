#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cstring>

using namespace std;

int T;
int n;
int a[1010];
bitset<1010>v;
int M,g[1010];

struct edge
{
    int t,next;
}e[1010];
inline void add_edge(int x,int y)
{
    e[++M].t=y;
    e[M].next=g[x];
    g[x]=M;
}

inline int go(int num,int st)
{
    v.set(num);
    if(num==st)return 1;
    if(!v.test(a[num]))
        return go(a[num],st)+1;
    else
        return -100000;
}

inline int fnd1(int n)
{
    int ma=0;
    for(int i=1;i<=n;i++)
    {
        v.reset();
        int temp=go(a[i],i);
        if(temp>ma)ma=temp;
    }
    return ma;
}
inline int dfs(int x)
{
    v.set(x);
    int ma=0;
    for(int i=g[x];i;i=e[i].next)
        if(!v.test(e[i].t))
            ma=max(ma,dfs(e[i].t));
    return ma+1;
}
inline int fnd2(int n)
{
    int ans=0;
    v.reset();

    for(int i=1;i<=n;i++)
    {
        if(a[a[i]]==i&&(!v.test(i))&&(!v.test(a[i])))
        {
            v.set(i);v.set(a[i]);
            ans+=2;
            ans+=dfs(i)-1;
            ans+=dfs(a[i])-1;
        }
    }
    return ans;
}
int main()
{
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        M=0;
        memset(g,0,sizeof(g));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",a+i);
            add_edge(a[i],i);
        }

        int ans=fnd1(n);

        ans=max(ans,fnd2(n));

        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
