#include<stdio.h>
#include<stdlib.h>
int main(){
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.txt","w",stdout);
    int T, N, M, j, k, max;
    int a[102][102], make[102][102];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%d%d",&N,&M);
        for(j=0;j<N;j++){
            for(k=0;k<M;k++){
                scanf("%d",&a[j][k]);
                make[j][k] = 100;
            }
        }
        //horizontal
        for(j=0;j<N;j++){
            max = 0;
            for(k=0;k<M;k++)
                if(a[j][k] > max) max = a[j][k];
            for(k=0;k<M;k++)
                if(make[j][k] > max) make[j][k] = max;
        }
        //vertical
        for(k=0;k<M;k++){
            max = 0;
            for(j=0;j<N;j++)
                if(a[j][k] > max) max = a[j][k];
            for(j=0;j<N;j++)
                if(make[j][k] > max) make[j][k] = max;
        }
        for(j=0;j<N;j++){
            for(k=0;k<M;k++){
                if(a[j][k] != make[j][k]) break;
            }
            if(k != M) break;
        }
        printf("Case #%d: ", i+1);
        if(j == N)  printf("YES\n");
        else        printf("NO\n");
    }
}
