#include<cstdio>
#include<cstring>
bool ma[55][55];
int t,n,tmp,tt;
int dfs(int x,int y){
    if(x==y) return 0;
    int ans=0;
    if(ma[x][y]) ans++;
    for(int i=1;i<=n;i++){
        if(ma[x][i]) ans+=dfs(i,y);
    }
    return ans;
}
int main(){
    //freopen("in.in","r",stdin);
    //freopen("out.txt","w",stdout);
    scanf("%d",&t);
    for(int caseno=1;caseno<=t;caseno++){
        memset(ma,0,sizeof(ma));
        bool jud=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&tmp);
            for(int j=1;j<=tmp;j++){
                scanf("%d",&tt);
                ma[i][tt]=1;
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(jud) break;
                else jud=dfs(i,j)>1?1:0;
            }
        }
        printf("Case #%d: ",caseno);
        if(jud) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
