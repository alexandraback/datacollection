#include <cstdio>
#include <cstdlib>
#include <cstring>

int f[10005],n,e,r;

struct point
{
    int data,pos;
}tree[4*10005];

void up(int pos)
{
    if(tree[pos<<1].data>tree[(pos<<1)|1].data)tree[pos]=tree[pos<<1];
    else tree[pos]=tree[(pos<<1)|1];
}

void ini(int pos,int begin,int end)
{
    if(begin==end)
    {
        tree[pos].data=f[begin];
        tree[pos].pos=begin;
    }
    else
    {
        int mid=(begin+end)>>1;
        ini(pos<<1,begin,mid);
        ini((pos<<1)|1,mid+1,end);
        up(pos);
    }
    //printf("[%d,%d]:%d,%d\n",begin,end,tree[pos].pos,tree[pos].data);
}

void change(int pos,int begin,int end,int x)
{
    if(begin==end)
    {
        tree[pos].data=0;
    }
    else
    {
        int mid=(begin+end)>>1;
        if(x<=mid)change(pos<<1,begin,mid,x);
        else change((pos<<1)|1,mid+1,end,x);
        up(pos);
    }
    //printf("[%d,%d]:%d,%d\n",begin,end,tree[pos].pos,tree[pos].data);
}

int find(int pos,int begin,int end,int x)
{
    if(begin==end)return begin;
    int mid=(begin+end)>>1;
    if(tree[pos<<1].data>f[x])return find(pos<<1,begin,mid,x);
    return find((pos<<1)|1,mid+1,end,x);
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d%d%d",&e,&r,&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&f[i]);
        ini(1,1,n);
        long long ans=0;
        int now=e;
        for(int i=1;i<=n;i++)
        {
            change(1,1,n,i);
            int x=find(1,1,n,i);
            //printf("%d(%d,%d)[%d]:%d->",i,tree[1].pos,tree[1].data,x,now);
            if(tree[1].data<=f[i])
            {
                ans+=(long long)f[i]*now;
                now=0;
            }
            else if((x-i)*r+now>e)
            {
                if((x-i)*r+now-e>now)
                {
                    ans+=(long long)f[i]*now;
                    now=0;
                }
                else
                {
                    ans+=(long long)f[i]*((x-i)*r+now-e);
                    now-=((x-i)*r+now-e);
                }
            }
            //printf("%d\n",now);
            now+=r;
        }
        printf("Case #%d: %I64d\n",cas,ans);
    }
    return 0;
}
