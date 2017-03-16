#include <cstdio>

int main(){
    int T;
    scanf("%d",&T);
    for(int ix=1;ix<=T;ix++){
        printf("Case #%d: ",ix);
        int A,B,K;
        scanf("%d%d%d",&A,&B,&K);
        int ans=0;
        for(int i=0;i<A;i++){
            for(int j=0;j<B;j++){
                if((i&j)<K) ans++;
            }
        }
        printf("%d\n",ans);
    }
}
