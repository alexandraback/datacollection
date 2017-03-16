#include <cstdio>
#include <cstring>

int T,N,M,head[1005],next[10005],e[10005],cnt;
int vis[1005];

bool dfs(int c, int d){
    vis[c]=d;
    for (int cur=head[c];cur!=-1;cur=next[cur]){
        if (vis[e[cur]]!=d){
            if (dfs(e[cur],d))
                return 1;
        }
        else return 1;
    }
    return 0;
}

int main(){
    scanf("%d",&T);
    for (int t=1;t<=T;++t){
        memset(head,-1,sizeof head);
        memset(next,-1,sizeof next);
        memset(vis,-1,sizeof vis);
        cnt=0;
        scanf("%d",&N);
        for (int i=1;i<=N;++i){
            scanf("%d",&M);
            for (int j=0;j<M;++j){
                scanf("%d",&e[cnt]);
                next[cnt]=head[i];
                head[i]=cnt++;
            }
        }
        bool flag=0;
        for (int i=1;i<=N && !(flag=dfs(i,i));++i);
        printf("Case #%d: ",t);
        if(flag)
            printf("Yes\n");
        else printf("No\n");
    }
}
