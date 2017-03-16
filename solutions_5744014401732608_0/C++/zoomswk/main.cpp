#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;

int mat[55][55];

int main(){
    int T;
    scanf("%d", &T);
    for(int test=1; test<=T; test++){
        long long B, M;
        for(int i=0; i<55; i++) for(int j=0; j<55; j++) mat[i][j] = 0;
        int mark[100];
        for(int i=0; i<100; i++) mark[i] = 0;
        scanf("%lld%lld", &B, &M);
        printf("Case #%d: ", test);
        if(1<<(B-2) < M){ printf("IMPOSSIBLE\n"); continue; }
        printf("POSSIBLE\n");
        long long need = M;
        int time=0;
        for(int i=1; i<B; i++) mat[i][i+1] = 1;
        int biggest=0;
        while(need > 0){
            if(need % 2) mark[time] = 1;
            need /= 2;
            time++;
        }
        time--;
        for(int i=B-time-1; i<B; i++){
            for(int j=i+1; j<=B; j++) mat[i][j] = 1;
        }
        for(int i=0; i<time; i++){
            //printf("%d\n", mark[i]);
            //if(i == 0 && mark[i]) mat[1][B] = 1;
            if(mark[i]) mat[1][B-i-1] = 1;
        }
        /*
        for(int i=time-1; time>=0; time--){
            if(!mark[i]) continue;
            int tofill = (1<<i);
            
        }
         */
        for(int i=1; i<=B; i++){
            for(int j=1; j<=B; j++){
                printf("%d", mat[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}