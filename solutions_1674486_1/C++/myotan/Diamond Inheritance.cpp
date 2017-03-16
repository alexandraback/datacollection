
#include<stdio.h>
int adj[1001][1001],v[1001],N,incount[1001];
int flag;
int clear(int *xz){
    for(int i=0;i<N;i++)xz[i]=0;
}
int dfs(int k){
    for(int i=0;i<N;i++){
        if(adj[k][i]==1){
            if(v[i]==0){
                v[i]=1;
                if(dfs(i))break;
            }
            else {
                flag=1;
                return 1;
            }
        }
    }
}
int main(){
    int T,a,b;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d",&N);
        clear(incount);
        for(int j=0;j<N;j++)
            clear(adj[j]);
        for(int j=0;j<N;j++){
            scanf("%d",&a);
            for(int k=0;k<a;k++){
                scanf("%d",&b);
                adj[b-1][j]=1;
                incount[j]++;
            }
        }
        flag=0;
        for(int j=0;j<N&&flag==0;j++)if(incount[j]==0){clear(v);dfs(j);
        //for(int fj=0;fj<N;fj++)printf("%d ",v[fj]);
        }
        if(flag==1)printf("Case #%d: Yes\n",i+1);
        else printf("Case #%d: No\n",i+1);
    }
}
