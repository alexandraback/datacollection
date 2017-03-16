//#define LOCAL
//#define SMALL
#include<bits/stdc++.h>
using namespace std;
const int maxn=1000+5;
int indeg[maxn],viscnt,Max[maxn],cyclen[maxn],out[maxn],dep[maxn],ans,vis[maxn];
void dfs1(int now,int depth)
{
    dep[now]=depth;vis[now]=viscnt;
    int to=out[now];
    if(dep[to]==-1) dfs1(to,depth+1);
    else if(vis[to]==viscnt) cyclen[now]=cyclen[to]=dep[now]-dep[to]+1,ans=max(ans,cyclen[now]);
}
void dfs2(int now,int depth)
{
    dep[now]=depth;
    int to=out[now];
    if(dep[to]==-1 && cyclen[to]==0) dfs2(to,depth+1);
    if(cyclen[to]==2 && out[to]!=now) // to,out[to]
            Max[to]=max(Max[to],depth+1);
    dep[now]=-1;
}
int main()
{
    #ifndef LOCAL
    #ifdef SMALL
    freopen("smallC.in","r",stdin);
    freopen("smallC.out","w",stdout);
    #else
    freopen("largeC.in","r",stdin);
    freopen("largeC.out","w",stdout);
    #endif
    #endif
    int kase=0,T;
    scanf("%d",&T);
    while(T--)
    {
        memset(cyclen,0,sizeof cyclen);
        memset(Max,0,sizeof Max);
        memset(indeg,0,sizeof indeg);
        memset(vis,0,sizeof vis);
        viscnt=0;ans=0;

        int N;
        scanf("%d",&N);
        for(int i=1;i<=N;i++) {scanf("%d",out+i);indeg[out[i]]++;}
        
        memset(dep,-1,sizeof dep);
        for(int i=1;i<=N;i++) if(dep[i]==-1) {viscnt++;dfs1(i,0);}
                
        memset(dep,-1,sizeof dep);
        for(int i=1;i<=N;i++) if(indeg[i]==0) {viscnt++;dfs2(i,0);}

        int now=0;
        for(int i=1;i<=N;i++) if(cyclen[i]==2) now+=1+Max[i];
        printf("Case #%d: %d\n",++kase,max(ans,now));
    }
}
