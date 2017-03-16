#include<stdio.h>
#include<algorithm>
int pass[1010];
int map[1010][1010];
int re[1010];
int ok;
void dfs(int x){
    if(pass[x]==1){
        ok=1;
        return;
        }
    else{
        pass[x]++;
        for(int i=0;i<re[x];i++){
            dfs(map[x][i]);
            }
        }
    }
main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,n;
    scanf("%d",&t);
    for(int T=1;T<=t;T++){
        printf("Case #%d: ",T);
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&re[i]);
            for(int j=0;j<re[i];j++){
                scanf("%d",&map[i][j]);
                }
            }
        //«e¸m
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                pass[j]=0;
                }
            ok=0;    
            dfs(i);
            if(ok==1){
                break;
                }
            } 
        if(ok==1){
            printf("Yes\n");
            }
        else{
            printf("No\n");
            }
        }
    }
