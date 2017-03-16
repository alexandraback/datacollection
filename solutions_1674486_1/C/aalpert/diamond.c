#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#define debug(x...) 0
const int MAX_N = 1000 + 1;
int adjmat[MAX_N][MAX_N];
int tracker[MAX_N];
int dfflood(int n)
{
    tracker[n]++;
    if (tracker[n] > 1)
        return 1;
    int i,j,k=0;
    for (i = 1; i<=MAX_N; i++)
        if (adjmat[n][i])
            k += dfflood(i);
    debug("%d\n", k);
    return k;
}

int solve(int N)
{
    int i,j,k;
    for (i = 1; i<=N; i++){
        memset(tracker, 0, MAX_N*sizeof(int));
        if(dfflood(i))
            return 1;
    }
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Usage: You're doing it wrong\n");
        return 1;
    }

    FILE* fin = fopen(argv[1], "r");
    FILE* fout = fopen(argv[2], "w");
    int T,N,t,i,j,k,n;
    fscanf(fin, "%d", &T);
    for (t=0; t<T; t++) {
        memset(adjmat, 0, MAX_N*MAX_N*sizeof(int));
        fscanf(fin, "%d", &N);
        for (n = 1; n<=N; n++) {
            int M,m;
            fscanf(fin, "%d", &M);
            for(m=0; m<M; m++) {
                int o = 0;
                fscanf(fin, "%d", &o);
                adjmat[n][o] = 1;
            }
        }
        fprintf(fout, solve(N) ? "Case #%d: Yes\n" : "Case #%d: No\n", t+1);
    }
    fclose(fin);
    fclose(fout);
    return 0;
}
