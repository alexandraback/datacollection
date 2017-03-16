#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int Maxn=100010;
typedef long long ll;
struct Node
{
    int from,to;
    ll lazy;
    ll sum;
}node[Maxn*4];
int n,q;
void build(int p,int from,int to)
{
    node[p].from=from,node[p].to=to;
    node[p].sum=0;node[p].lazy=0;
    if(from==to)return;
    int mid=(from+to)>>1;
    build(p*2,from,mid);
    build(p*2+1,mid+1,to);
}
void makeLazy(int p,ll lazy)
{
    node[p].lazy+=lazy;
    node[p].sum+=(node[p].to-node[p].from+1)*lazy;
}
void doLazy(int p)
{
    makeLazy(p*2,node[p].lazy);
    makeLazy(p*2+1,node[p].lazy);
    node[p].lazy=0;
}
void update(int p)
{
    node[p].sum=node[p*2].sum+node[p*2+1].sum;
}
void insert(int p,int from,int to,int x)
{
    if(node[p].from==from&&node[p].to==to)
    {
        node[p].lazy+=x;
        node[p].sum+=(to-from+1)*(ll)x;
        return;
    }
    doLazy(p);
    int mid=node[p*2].to;
    if(to<=mid)insert(p*2,from,to,x);
    else if(from>mid)insert(p*2+1,from,to,x);
    else
    {
        insert(p*2,from,mid,x);
        insert(p*2+1,mid+1,to,x);
    }
    update(p);
}
ll search(int p,int from,int to)
{
    if(node[p].from==from&&node[p].to==to)return node[p].sum;
    doLazy(p);
    int mid=node[p*2].to;
    ll ret;
    if(to<=mid)ret=search(p*2,from,to);
    else if(from>mid)ret=search(p*2+1,from,to);
    else
    {
        ret=search(p*2,from,mid);
        ret+=search(p*2+1,mid+1,to);
    }
    update(p);
    return ret;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&q);
    build(1,1,n);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        insert(1,i,i,x);
    }
    for(int i=1;i<=q;++i)
    {
        char s[4];
        scanf("%s",s);
        if(s[0]=='Q')
        {
            int from,to;
            scanf("%d%d",&from,&to);
            if(from>to)swap(from,to);
            printf("%lld\n",search(1,from,to));
        }
        else
        {
            int from,to,x;
            scanf("%d%d%d",&from,&to,&x);
            if(from>to)swap(from,to);
            insert(1,from,to,x);
        }
    }
    return 0;
}