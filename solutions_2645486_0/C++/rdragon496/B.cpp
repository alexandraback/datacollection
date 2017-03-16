#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#define MAXN 128
#define INF 1<<30
///dfs
using namespace std;

struct Node
{
    long long l,r;
    long long maxv;
};
Node s[4*10005];

long long val[10005];
long long ans;
long long e,g,n;

void buildtree(int x,long long l,long long r)
{
    s[x].l=l;
    s[x].r=r;
    if(l<r)
    {
        long long mid=(l+r)/2;
        buildtree(2*x,l,mid);
        buildtree(2*x+1,mid+1,r);
        s[x].maxv=max(s[2*x].maxv,s[2*x+1].maxv);
    }
    else
    {
        s[x].maxv=val[l];
    }
}

long long query(int x,long long l,long long r)
{
    if(l>r) return 0;
    if(s[x].l==l&&s[x].r==r)
    {
        return s[x].maxv;
    }
    long long mid=(s[x].l+s[x].r)/2;
    if(r<=mid) return query(2*x,l,r);
    else if(l>=mid+1) return query(2*x+1,l,r);
    else
    {
        return max(query(2*x,l,mid),query(2*x+1,mid+1,r));
    }
}

void dfs(int x,long long tmp,long long leave)
{
    if(x>=n)
    {
        if(tmp>ans) ans=tmp;
        return;
    }
    long long maxv=query(1,x+1,n-1);
    for(int i=0; i<=leave; i++)
    {
        if(tmp+i*val[x]+e*maxv*(n-1-x)>ans)
        {
            if(leave-i+g<=e) dfs(x+1,tmp+i*val[x],leave-i+g);
            else dfs(x+1,tmp+i*val[x],e);
        }
    }
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("out.txt","w",stdout);
    int cases;
    scanf("%d",&cases);
    for(int c=1; c<=cases; c++)
    {
        scanf("%lld %lld %lld",&e,&g,&n);
        for(int i=0; i<n; i++)
        {
            scanf("%lld",&val[i]);
        }
        buildtree(1,0,n-1);
        ans=0;
        printf("Case #%d: ",c);
        dfs(0,0,e);
        printf("%lld\n",ans);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
