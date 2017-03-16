#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>

using namespace std;
const int Maxn=20010,Maxd=90;
struct Node
{
    int next[Maxd<<1];
    int deep,fail,id;
    void clear()
    {
        memset(next,0,sizeof(next));
        deep=fail=0;
    }
}node[Maxn<<1];
int size,end;
void init()
{
    fill(node[0].next,node[0].next+Maxd+Maxd,1);
    node[0].deep=-1;
    node[1].clear();
    size=2,end=1;
}
void addNode(int c,int id)
{
    int p=size++;node[p].clear();
    node[p].deep=node[end].deep+1;node[p].id=id;
    for(;!node[end].next[c];end=node[end].fail)
        node[end].next[c]=p;
    int p1=node[end].next[c];
    if(node[p1].deep==node[end].deep+1)node[p].fail=p1;
    else
    {
        int p2=size++;node[p2]=node[p1];node[p1].fail=node[p].fail=p2;
        node[p2].deep=node[end].deep+1;
        for(;node[end].next[c]==p1;end=node[end].fail)
            node[end].next[c]=p2;
    }
    end=p;
}
struct Edge
{
    int to,next;
    Edge(){}
    Edge(int to,int next):to(to),next(next){}
}edge[Maxn<<1];
int box[Maxn<<1],sizeEdge;
void add(int from,int to)
{
    edge[sizeEdge]=Edge(to,box[from]);
    box[from]=sizeEdge++;
}
void build(int a[],int n)
{
    init();
    for(int i=1;i<n;++i)
        addNode(a[i],i);
    memset(box,-1,sizeof(box));sizeEdge=0;
    for(int i=2;i<size;++i)
        add(node[i].fail,i);

}
int n;
int data[Maxn],ans;
int min0[Maxn<<1],max0[Maxn<<1];
void dfs(int x)
{
  //  cout<<x<<endl;
    min0[x]=max0[x]=node[x].id;
    for(int i=box[x];i!=-1;i=edge[i].next)
    {
        int x1=edge[i].to;
        dfs(x1);
        min0[x]=min(min0[x],min0[x1]);
        max0[x]=max(max0[x],max0[x1]);
    }
   // cout<<x<<" "<<node[x].deep<<" "<<min0[x]<<" "<<max0[x]<<endl;
    ans=max(ans,min(max0[x]-min0[x]-1,node[x].deep));
}
int main()
{
  //  freopen("in.txt","r",stdin);
    while(scanf("%d",&n)!=EOF)
    {
        if(n==0)break;
        for(int i=0;i<n;++i)
            scanf("%d",&data[i]);
        for(int i=n-1;i>=1;--i)
        {
            data[i]-=data[i-1];
            data[i]+=Maxd;
        }
        build(data,n);
        ans=0;
        dfs(1);
        ans++;
        if(ans<5)ans=0;
        printf("%d\n",ans);
    }
    return 0;
}