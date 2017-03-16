#include<stdio.h>

int b,g[50][50];
long long m;

void process(){
    int i,j;
    long long M = m, pw=1;
    for(i=0;i<b-2;i++) pw = pw + pw;
    if(M > pw){
        printf("IMPOSSIBLE\n");
        return;
    }

    printf("POSSIBLE\n");
    for(i=0;i<b;i++) for(j=0;j<b;j++) g[i][j]=0;
    for(i=1;i<b;i++){
        for(j=i+1;j<b;j++){
            g[i][j] = 1;
        }
    }

    if(M == pw){
        for(i=1;i<b;i++) g[0][i] = 1;
    }
    else{
        i = b-2;
        while(M > 0){
            g[0][i--] = int(M%2);
            M = M / 2;
        }
    }

    for(i=0;i<b;i++){
        for(j=0;j<b;j++){
            printf("%d",g[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++){
        scanf("%d%lld",&b,&m);
        printf("Case #%d: ", t);
        process();
    }
    return 0;
}
