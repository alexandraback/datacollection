#include<cstdio>
#include<cstdlib>
#include<cstring>

int cnt[2505];
int T, N;

int main(){
    scanf("%d", &T);
    for(int t=1;t<=T;t++){
        scanf("%d", &N);
        memset(cnt, 0, sizeof(cnt));

        for(int i=0;i<2*N-1;i++){
            for(int j=0;j<N;j++){
                int x;
                scanf("%d", &x);
                cnt[x]++;
            }
        }
        printf("Case #%d:", t);
        for(int i=1;i<=2500;i++)
            if(cnt[i]%2 != 0) printf(" %d", i);
        printf("\n");
    }
    return 0;
}
