#include <cstdio>
#include <queue>
#include <iostream>
#include <cstring>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int T,t,n,cnt1,cnt2,ans;
string tmp;
map<string,int>mp1,mp2;
int a[2020],b[2020],len[4020],cc;
int s1[1020],s2[1020];
int head[4020],H[4020];
struct edge
{
    int n,t,v;
    edge(int a=0,int b=0,int c=0):n(a),t(b),v(c){}
}e[12000];
void ins(int a,int b,int c)
{
    e[cc]=edge(head[a],b,c);
    head[a]=cc++;
    e[cc]=edge(head[b],a,0);
    head[b]=cc++;
}
void build()
{
    memset(head,-1,sizeof(head));
    cc=0;
    int i,j;
    for(i=0;i<n;++i)
        ++s1[a[i]];
    for(i=0;i<n;++i)
        ++s2[b[i]];
    for(i=1;i<=n;++i)
        if(s1[i]>1)
            ins(0,i,s1[i]-1);
    for(i=1;i<=n;++i)
        if(s2[i]>1)
            ins(i+n,4002,s2[i]-1);
    for(i=0;i<n;++i)
    {
        ins(a[i],a[i]+(n<<1),1);
        ins(b[i]+3*n,b[i]+n,1);
        ins(a[i]+(n<<1),b[i]+3*n,1);
    }
}
queue<int>que;
bool bfs(int s,int t)
{
    memset(len,0x3f,sizeof(len));
    len[s]=0;
    while(!que.empty())que.pop();
    que.push(s);
    while(!que.empty())
    {
        int u=que.front();que.pop();
        for(int i=head[u];i!=-1;i=e[i].n)
        {
            int v=e[i].t;
            if(!e[i].v)
                continue;
            if(len[v]<=len[u]+1)
                continue;
            len[v]=len[u]+1;
            que.push(v);
        }
    }
    return len[t]<0x3f3f3f3f;
}
int dfs(int s,int t,int cur)
{
    if(s==t)return cur;
    int v,ans=0,M;
    for(int&i=H[s];i!=-1;i=e[i].n)
    {
        v=e[i].t;
        if(!e[i].v)
            continue;
        if(len[v]!=len[s]+1)
            continue;
        M=min(cur,e[i].v);
        M=dfs(v,t,M);
        ans+=M;
        e[i].v-=M;
        e[i^1].v+=M;
        cur-=M;
        if(!cur)
            break;
    }
    return ans;
}
int dinic(int s,int t)
{
    int ans=0;
    while(bfs(s,t))
    {
        memcpy(H,head,sizeof(head));
        ans+=dfs(s,t,0x3fffffff);
    }
    return ans;
}
int main()
{
    cin>>T;
    for(t=1;t<=T;++t)
    {
        mp1.clear();
        mp2.clear();
        memset(s1,0,sizeof(s1));
        memset(s2,0,sizeof(s2));
        cnt1=cnt2=0;
        scanf("%d",&n);
        for(int i=0;i<n;++i)
        {
            cin>>tmp;
            if(mp1.find(tmp)!=mp1.end())
                a[i]=mp1[tmp];
            else
            {
                mp1[tmp]=++cnt1;
                a[i]=cnt1;
            }
            cin>>tmp;
            if(mp2.find(tmp)!=mp2.end())
                b[i]=mp2[tmp];
            else
            {
                mp2[tmp]=++cnt2;
                b[i]=cnt2;
            }
        }
        build();
        ans=dinic(0,4002);
        printf("Case #%d: %d\n",t,ans);
    }
    return 0;
}
