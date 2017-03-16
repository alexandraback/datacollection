#include<stdio.h>
int pp[110], N, J, TC, w[50][11][110], Ans[110], G[11], Res[11];
void Add(int L, int a){
    int i, j;
    for(i=2;i<=10;i++){
        G[i]+=a;
        for(j=1;j<=100;j++){
            w[L][i][j] = (w[L][i][j]+a+pp[j])%pp[j];
        }
    }
}
void DFS(int L){
    if(!J)return;
    int i, j;
    for(i=2;i<=10;i++){
        G[i]=G[i]*i;
        if(G[i]>1000)G[i] = 9999;
        for(j=1;j<=100;j++){
            w[L][i][j] = w[L-1][i][j]*i%pp[j];
        }
    }
    if(L!=N-1){
        Ans[L] = 0;
        DFS(L+1);
        if(!J)return;
    }
    Ans[L] = 1;
    Add(L,1);
    if(L == N-1){
        for(i=2;i<=10;i++){
            for(j=1;j<=100;j++)if(pp[j]!=G[i] && !w[L][i][j])break;
            if(j==101)break;
            Res[i] = j;
        }
        if(i==11){
            for(i=0;i<N;i++)printf("%d",Ans[i]);
            for(i=2;i<=10;i++)printf(" %d",pp[Res[i]]);
            printf("\n");
            J--;
        }
        return;
    }
    DFS(L+1);
}
int main(){
    int i, j, p_c=0;
    for(i=2;i<=1000;i++){
        for(j=2;j*j<=i;j++)if(i%j==0)break;
        if(j*j>i && p_c<100)pp[++p_c] = i;
    }
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    while(TC--){
        printf("Case #%d:\n",1);
        scanf("%d%d",&N,&J);
        for(i=2;i<=10;i++){
            G[i] = 1;
            for(j=1;j<=100;j++)w[0][i][j] = 1;
        }
        Ans[0]=1;
        DFS(1);
    }
}
