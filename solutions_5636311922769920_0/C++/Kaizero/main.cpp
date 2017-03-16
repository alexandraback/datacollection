#include<stdio.h>
long long K,C,S,t;
int main(){
    int TC, TT, i, j;
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d",&TC);
    for(TT=1;TT<=TC;TT++){
        printf("Case #%d: ",TT);
        scanf("%lld%lld%lld",&K,&C,&S);
        if(C*S < K){
            printf("IMPOSSIBLE\n");
        }
        else{
            for(i=0;i<(K-1)/C+1;i++){
                t=0;
                for(j=0;j<C;j++){
                    t*=K;
                    t+=(i*C+j)%K;
                }
                printf("%lld ",t+1);
            }
            printf("\n");
        }
    }
}
