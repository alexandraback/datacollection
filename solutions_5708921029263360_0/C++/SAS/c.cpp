#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

using namespace std;

int J, P, S, K;
int main(){
    int T;
    scanf("%d",&T);
    for(int ca= 1;ca <=T;ca++){
        scanf("%d %d %d %d", &J, &P, &S, &K);

        printf("Case #%d: ", ca);

        int ans = J * P * min(K, S);
        printf("%d\n", ans);
        if(P <= K){
            for(int k=0;k<min(K, S);k++){
                for(int i=0;i<J;i++){
                    for(int j=0;j<P;j++){
                        printf("%d %d %d\n", i + 1, j + 1, k + 1);
                    }
                }
            }
            continue;
        }
            
        for(int k=0;k<K;k++){
            for(int i=0;i<J;i++){
                for(int j=0;j<P;j++){
                    printf("%d %d %d\n", i + 1, j + 1, (i + j + k) % S + 1);
                }
            }
        }

    }
    return 0;
}
