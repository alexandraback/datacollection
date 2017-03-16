#include<cstdio>
#include<cstdlib>

int T, N;
int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        printf("Case #%d: ", t);
        scanf("%d", &N);

        if(N == 0){
            printf("INSOMNIA\n");
            continue;
        }

        int cnt = 0;
        int have[10]={0};
        for(int i=1;;i++){
            long long num = i*N;
            while(num != 0){
                int x = num%10;
                num = num/10;
                if(have[x]) continue;
                have[x] = 1, cnt++;
                if(cnt == 10) break;
            }
            if(cnt == 10){
                printf("%lld\n", ((long long)i)*N);
                break;
            }
        }

    }
    return 0;
}
