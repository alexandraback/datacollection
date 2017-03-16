#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#define maxn 1010
using namespace std;
struct edge{
    int to,next;
}e[maxn<<2];
int box[maxn],cnt,vis[maxn],dep[maxn];
void init(){
    memset(box,-1,sizeof(box));
    memset(vis,0,sizeof(vis));
    memset(dep,0,sizeof(dep));
    cnt=0;
}
void add(int from,int to){
    e[cnt].to=to;
    e[cnt].next=box[from];
    box[from]=cnt++;
}
int st[maxn],top=0,maxdep,next;
void dfs(int now,int fa,int id){
    dep[now]=dep[fa]+1;
    if(dep[now]>maxdep){
        maxdep=dep[now];
        next=now;
    }
    vis[now]=id;
    for(int t=box[now];t+1;t=e[t].next){
        int v=e[t].to;
        if(vis[v]!=id&&v!=fa){
            dfs(v,now,id);
        }
    }
}
int solve(int root,int id,int n){//—∞’“÷±æ∂
    memset(dep,0,sizeof(dep));
    maxdep=0,next=0;
    dfs(root,0,id);
    printf("%d %d\n",next,dep[next]);
    memset(dep,0,sizeof(dep));
    for(int i=1;i<=n;i++){
        if(vis[i]==id)
            vis[i]=0;
    }
    maxdep=0;
    dfs(next,0,id);
    printf("%d %d\n",next,dep[next]);
    return dep[next];
}
vector<int> Cir;
vector<int> Len;
bool find(int now,int fa,int id){
    st[top++]=now;
    vis[now]=id;
    for(int t=box[now];t+1;t=e[t].next){
        int v=e[t].to;
        if(v!=fa&&vis[v]==id){
            Cir.push_back(v);
            while(top>0&&st[top-1]!=v){
                Cir.push_back(st[top-1]);
                top--;
            }
            return true;
        }
        if(vis[v]!=id){
            if(find(v,now,id)){
                return true;
            }

        }
    }
    top--;
    return false;
}
int c[maxn];
int findlen(int now,int fa){
    int ma=0;
    for(int t=box[now];t+1;t=e[t].next){
        int v=e[t].to;
        if(v!=fa&&!c[v]){
            ma=max(ma,findlen(v,now));
        }
    }
    return ma;
}
int circle(int root,int id){// —∞’“ª∑
    top=0;
    Cir.clear();
    Len.clear();
    memset(c,0,sizeof(c));
    find(root,0,id);
    if(Cir.size()==0){
        return 0;
    }
    int size=Cir.size();
    for(int i=0;i<size;i++){
        c[Cir[i]]=1;
    }
    for(int i=0;i<size;i++){
        Len.push_back(findlen(Cir[i],0));
    }
    int ans=0;
    for(int i=0;i<size;i++){
        for(int j=i+1;j<size;j++){
            int x=j-i+1;
            int y=size-x+2;
            ans=max(ans,max(x,y)+Len[i]+Len[j]);
        }
    }
    return ans;
}

int main()
{
    freopen("dd.txt","r",stdin);
    //freopen("out.txt","w+",stdout);
    int ncase,T=0;
    scanf("%d",&ncase);
    while(ncase--){
        printf("Case #%d: ",++T);
        int n;
        scanf("%d",&n);
        init();
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d",&x);
            add(i,x);
            add(x,i);
        }
        int id=0,ans=0;
        for(int i=1;i<=n;i++){
            if(vis[i])
                continue;
            ans=max(ans,solve(i,++id,n));
            //ans=max(ans,circle(i,++id));
        }
        printf("%d\n",ans);
    }
    return 0;
}
