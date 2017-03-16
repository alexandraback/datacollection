#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int T;
int N;
int counts[2505];

main(){
    FILE *inp = fopen("rankfileS.in", "r"), *outp = fopen("rankfile.out", "w");
    fscanf(inp, "%d", &T);
    int i,j,k;
    int temp;
    for(i = 0; i < T; i++){
        fscanf(inp, "%d", &N);
        for(j = 0; j < 2505; j++) counts[j] = 0;
        for(j = 0; j < 2*N - 1; j++){
            for(k = 0; k < N; k++){
                fscanf(inp, "%d", &temp);
                counts[temp] = (counts[temp] + 1) % 2;
            }
        }
        fprintf(outp, "Case #%d:", i+1);
        for(j = 1; j < 2505; j++){
            if(counts[j] % 2) fprintf(outp, " %d", j);
        }
        fprintf(outp, "\n");
    }
    return 0;
}
