#include<cstdio>
#include<cstdlib>

int T, K, C, S;
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%d%d%d", &K, &C, &S);
        printf("Case #%d:", t);
        /*long long m = 1, s = 0;
        for(int i=0;i<C-1;i++) m *= K;*/

        for(int i=1;i<=S;i++){
            printf(" %d", i);
            //s += m;
        }
        printf("\n");
    }
    return 0;
}
