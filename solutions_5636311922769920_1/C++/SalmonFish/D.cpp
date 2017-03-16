#include<cstdio>
#include<cmath>


int main(){
    int t;
    scanf("%d", &t);
    for(int i=0;i<t;i++){
        printf("Case #%d:", i+1);
        int K, C, S;
        scanf("%d %d %d", &K, &C, &S);
        if(K <= C){
            if(K == 1){
                printf(" 1\n");
            }
            else{
                long long temp_K = K;
                long long ans = (pow(temp_K, temp_K) - temp_K) / (pow(temp_K-1, 2));
                printf(" %lld\n", ans);
            }
        }   
        else if(C == 1){
            if(S == K){
                for(int j=1;j<=K;j++){
                    printf(" %d", j);  
                }
                printf("\n");
            }
            else{
                printf(" IMPOSSIBLE\n");
            }

        }
        else if(K == 3){
            long long ans1 = pow(K, C) - 1;
            long long ans2 = 2;
            printf(" %lld %lld\n", ans1, ans2);
        }
        else{
            int cc = K-2;
            if(cc <= S){
                long long ans1 = 1;
                long long ans2 = pow(K, C);
                for(int j=0;j<cc;j++){
                    if(!(j%2)){
                        ans1++;
                        printf(" %lld", ans1);
                    }
                    else{
                        ans2--;
                        printf(" %lld", ans2);
                    }
                }
                printf("\n");
            }
            else{
                printf(" IMPOSSIBLE\n");
            }
        }
    } 
}
