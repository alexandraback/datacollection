#include <algorithm>
#include <cstdio>

int main(){
    int T;
    scanf("%d", &T);
    double Naomi[1000], Ken[1000];
    for(int t = 1;t <= T;++t){
        int N;
        scanf("%d", &N);
        for(int i = 0;i < N;++i){
            scanf("%lf", &Naomi[i]);
        }
        for(int i = 0;i < N;++i){
            scanf("%lf", &Ken[i]);
        }
        std::sort(Naomi, Naomi + N);
        std::sort(Ken, Ken + N);
        printf("Case #%d: ", t);
        int score = 0;
        for(int i = 0, j = 0;i < N;++i){
            if(Naomi[i] > Ken[j]){
                ++score;
                ++j;
            }
        }
        printf("%d", score);
        printf(" ");
        for(int i = 0, j = 0;i < N;++i, ++j){
            while(j < N && Naomi[i] > Ken[j]){
                ++j;
            }
            if(j == N){
                printf("%d", N - i);
                break;
            }
            if(i + 1 == N){
                printf("0");
                break;
            }
        }
        printf("\n");
    }
}
