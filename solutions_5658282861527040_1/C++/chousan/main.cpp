#include<stdio.h>
#include<iostream>
#include<string.h>
#define MAX 600
#define INF 9999999
using namespace std;
struct hh
{
    int from,to,c,next;
}edges[1000000];
struct mm
{
    int from,to,next;
}qq[1000000];
int box[10000];
int box1[1000];
int n,m,K,ss,tt;
void ad(int from,int to,int kk)
{
    qq[kk].from=from;
    qq[kk].to=to;
    qq[kk].next=box1[from];
    box1[from]=kk;
}
struct ee
{
    int x,step;
}que[100000];
int level[100000];
int pre[100000];
bool makelevel(int s,int t)
{
    int i;
   // cout<<"***"<<endl;
    memset(level,0,sizeof(level));
    level[s]=1;
    int q[MAX+10];
    q[0]=s;
    int head=0,end=1;
    bool flag=false;
   // cout<<edges[0].from<<endl;
    while(head<end)
    {
        //cout<<edges[box[q[head]]].from<<endl;
        for(i=box[q[head]];i!=-1;i=edges[i].next)
        {
           // cout<<i<<endl;
            if(!level[edges[i].to]&&edges[i].c)
            {
                level[edges[i].to]=level[q[head]]+1;
                q[end]=edges[i].to;
                end++;
                if(edges[i].to==t)
                {
                    flag=true;
                    break;
                }
            }
        }
        head++;
        if(flag)break;
    }
    if(flag)
    {
        for(int i=0;i<t;++i)pre[i]=box[i];
        return true;
    }
    return false;
}
int dinic(int v,int t,int mincap)
{
    int i;
    //cout<<v<<"^^^"<<endl;
    if(v==t)return mincap;
    if(level[v]==level[t])return 0;
    int ret=0,flow;
    for(i=pre[v];i!=-1;i=edges[i].next)
    {
        pre[v]=i;
        if(edges[i].c>0&&level[edges[i].to]>level[v])
        {
            int min;
            if(mincap-ret<edges[i].c)min=mincap-ret;
            else min=edges[i].c;
            flow=dinic(edges[i].to,t,min);
            edges[i].c-=flow;edges[i^1].c+=flow;
            ret+=flow;
            if(ret==mincap)return ret;
        }
    }
    return ret;
}
void add(int from,int to,int c,int kk)
{
    edges[kk].from=from;
    edges[kk].to=to;
    edges[kk].c=c;
    edges[kk].next=box[from];
    box[from]=kk;

}
void jian(int mid)
{
    int i;int k=0;
   int head=0,end=1;

    que[0].x=ss;
    que[0].step=0;
    int visit[20000]={0};
    while(head<end)
    {
        ee ima=que[head];
        if(ima.step>=mid)break;
        int xx=ima.x;
        for(int j=box1[xx];j!=-1;j=qq[j].next)
        {
            int w=qq[j].to;
            if(visit[j])continue;
            for(i=1;i<=mid;++i)
           {
               if(ima.step<i)
               { add((i-1)*n+xx,(i-1)*n+w,1,k++);
            add((i-1)*n+w,(i-1)*n+xx,0,k++);
               }
           }
            visit[j]=1;
            que[end].x=w;
            que[end].step=ima.step+1;
            end++;
        }

    head++;
    }
    for(i=1;i<=mid;++i)
   { add(0,n*(i-1)+ss,INF,k++);
    add(n*(i-1)+ss,0,0,k++);
    add(n*(i-1)+tt,n*mid+1,INF,k++);
    add(n*mid+1,n*(i-1)+tt,0,k++);
   }
    //cout<<'k'<<' '<<k<<endl;

    // cout<<n*mid+1<<endl;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j;
    while(scanf("%d%d%d%d%d",&n,&m,&K,&ss,&tt)!=EOF)
    {
        memset(box1,-1,sizeof(box1));
        int k=0;
        for(i=0;i<m;++i)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            ad(x,y,k++);
            ad(y,x,k++);
        }
        int max=50, min=0;
        while(min<=max)
        {
            int mid=(min+max)/2;
           // cout<<mid<<endl;
            memset(box,-1,sizeof(box));
            jian(mid);
//            for(int j=0;j<=n*mid+1;++j)
//            {
//                for(int g=box[j];g!=-1;g=edges[g].next)
//                cout<<edges[g].from<<' '<<edges[g].to<<' '<<edges[g].c<<endl;
//            }
            int aaa=0;
            while(makelevel(0,mid*n+1))
              {
                  aaa+=dinic(0,mid*n+1,INF);
              }
             // cout<<"aaa"<<' '<<aaa<<endl;
              if(aaa>=K)max=mid-1;
              else min=mid+1;
        }
        printf("%d\n",min);
    }
    return 0;
}

