#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

int T, N;
int bffs[1005];
int maxl;
int done[1005];

int solve(int stop, int start, int len, int prev){
    int k;
    if(done[bffs[stop]] == 1){
        if(bffs[stop] == start){
            return len;
        }
        else{
            int M = len;
            int t;
            int s = 1;
            for(k = 1; k <= N; k++){
                if(done[k] == 0 && bffs[k] == stop){
                    done[k] = 1;
                    s = 0;
                    t = solve(k, start, len+1, stop);
                    done[k] = 0;
                    if(t > M) M = t;
                }
            }
            if(s){
                if(prev == bffs[stop]) return len;
                else return 0;
            }
            else return M;
        }
    }
    done[bffs[stop]] = 1;
    return solve(bffs[stop], start, len + 1, stop);
}

main(){
    FILE *inp = fopen("bffS.in", "r"), *outp = fopen("bff.out", "w");
    fscanf(inp, "%d", &T);
    int i,j, k;
    int temp;
    for(i = 0; i < T; i++){
        maxl = 1;
        fscanf(inp, "%d", &N);
        for(j = 1; j <= N; j++){
            fscanf(inp, "%d", bffs+j);
        }
        for(j = 1; j <= N; j++){
            for(k = 1; k <= N; k++) done[k] = 0;
            done[j] = 1;
            done[bffs[j]] = 1;
            temp = solve(bffs[j], j, 2, j);
            if(temp > maxl){
                maxl = temp;
            }
        }
        fprintf(outp, "Case #%d: %d\n", i + 1, maxl);
    }
    return 0;
}
