#include<stdio.h>
int val[100],v,n,c;
int coin[100],sel[100];
void dfs(int depth){
    if(depth>=n){
        int sum=0;
        for(int i=0;i<n;i++){
            if(sel[i]) sum+=coin[i];
        }
        val[sum]=1;
        return;
    }
    sel[depth] = 1;
    dfs(depth+1);
    sel[depth] = 0;
    dfs(depth+1);
}
int main(){
    freopen("C-small-attempt0.in","r",stdin);
    freopen("C-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        scanf("%d%d%d",&c,&n,&v);
        for(int i=0;i<=v;i++) val[i]=0;
        for(int i=0;i<n;i++){
            scanf("%d",&coin[i]);
        }
        dfs(0);
        int ans = 0;
        for(int i=0;i<v;i++){
            if(val[i]==0){
                ans++;
                coin[n] = i;
                n++;
                dfs(0);
            }
        }
        printf("Case #%d: %d\n",tt,ans);
    }
}
