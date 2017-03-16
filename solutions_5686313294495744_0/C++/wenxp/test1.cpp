//HDU 1150
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<map>
#include<string>
using namespace std;
const int N=5000+10;
const int M=5000+10;
struct Edge{
    int to,next;
    Edge(){}
    Edge(int To,int Next){
        to=To,next=Next;
    }
}e[M];
int head[N];
int n;
int vis[N],match[N];
int total;
void init(){
    total=0;memset(head,-1,sizeof(head));
}
void adde(int u,int v){
    e[total]=Edge(v,head[u]);head[u]=total++;
}
int dfs(int u){
    for(int i=head[u];i!=-1;i=e[i].next){
        int v=e[i].to;
        if(!vis[v]){
            vis[v]=1;
            if(match[v]==-1||dfs(match[v]))
            {
                match[v]=u;
                return 1;
            }
        }
    }
    return 0;
}
int _hu(int x,int y)
{
    int ans=0;
    memset(match,-1,sizeof(match));
    for(int i=0;i<x;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i))ans++;
    }
    return ans;
}
map<string,int> mpx,mpy;
char ss[30],tt[30];
int xx,yy;
int sta[N],top;
int aa[N],bb[N];
int main(){
    #ifdef DouBi
    freopen("in.cpp","r",stdin);
    freopen("out.cpp","w",stdout);
    #endif // DouBi
    int T;scanf("%d",&T);int cas=1;
    while(T--){
        int n;scanf("%d",&n);
        mpx.clear();mpy.clear();
        xx=1;yy=1;
        init();
        for(int i=0;i<n;i++){
            scanf("%s%s",ss,tt);
            if(!mpx[ss]){
                mpx[ss]=xx++;
            }
            if(!mpy[tt]){
                mpy[tt]=yy++;
            }
            adde(mpx[ss]-1,mpy[tt]-1);
            aa[i]=mpx[ss]-1;bb[i]=mpy[tt]-1;
        }
        xx--;yy--;
        int cd=_hu(xx,yy);
        //printf("%d %d %d\n",xx,yy,cd);
        top=0;
        for(int i=0;i<yy;i++){
            if(match[i]!=-1){
                sta[top++]=match[i];sta[top++]=i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int flag=0;
            for(int j=0;j<top;j+=2){
                if(sta[j]==aa[i]&&sta[j+1]==bb[i]){
                    flag=1;break;
                }
            }
            if(flag==1)continue;
            for(int j=0;j<top;j+=2){
                if(sta[j]==aa[i]){
                    flag++;break;
                }
            }
            for(int j=0;j<top;j+=2){
                if(sta[j+1]==bb[i]){
                    flag++;break;
                }
            }
            if(flag==2)ans++;
            sta[top++]=aa[i];sta[top++]=bb[i];
        }
        printf("Case #%d: %d\n",cas++,ans);
    }
}
