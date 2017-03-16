#include<stdio.h>
#include<string>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<set>
#include<bitset>
#include<map>
#include<vector>
#include<algorithm>
#include<iostream>
#include<list>
#include<queue>
#include<stack>
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RS(X) scanf("%s", (X))
#define CASET int ___T, case_n = 1; scanf("%d ", &___T); while (___T-- > 0)
using namespace std;


int heights[3000];

void q(){
    memset(heights, 0, sizeof(heights));

    DRI(N);

    for(int i=0; i<2*N-1; i++){
        for(int j=0; j<N; j++){
            DRI(v);
            if(v<1 || v>=3000){
                printf("IN error\n");
                exit(0);
            }
            heights[v]++;
        }
    }
    
    for(int i=0; i < 3000; i++){
        if(heights[i] % 2){
            printf("%d ", i);
        }
    }
    printf("\n");
}
    

int main(){
    CASET {
        printf("Case #%d: ", case_n++);
        q();
        fflush(stdout);
    }
    return 0;
}

