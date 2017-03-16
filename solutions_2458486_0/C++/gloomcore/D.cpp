#define DCODE
#ifdef DCODE
#include "stdio.h"
#include "stdlib.h"
#define SUBMIT
#define MN 50
#define SK 50
#define KTYPE 50

int main(){
    
#ifdef SUBMIT
    FILE *infile = fopen("/CodeJam/D-small.in", "r"),
    *outfile = fopen("/CodeJam/D-small.txt", "w");
#else
    FILE *infile = stdin,
    *outfile = stdout;
#endif
    
    int T;
    fscanf(infile, "%d", &T);
    
    for (int t = 1; t <= T; t++) {
        printf("Case %d\n", t);
        long n, k;
        fscanf(infile, "%ld%ld", &k, &n);
        
        int skeys[SK] = {0};
        for (int i = 0; i < k; i++) {
            fscanf(infile, "%d", skeys + i);
        }
        
        int needKey[MN] = {0};
        int keysCnt[MN] = {0};
        int keysInside[MN][SK] = {0};
        
        
        long size = (1 << (long)n);
        long *stack = (long *)calloc(size, sizeof(long));
        bool *used = (bool *)calloc(size, sizeof(bool));
        long *prev = (long *)calloc(size, sizeof(long));
        int *step = (int *)calloc(size, sizeof(int));
        short **kcnt = (short **)calloc(size, sizeof(short *));
        
        for (int i = 0; i < n; i++) {
            fscanf(infile, "%d%d", needKey + i, keysCnt + i);
            
            for (int j = 0; j < keysCnt[i]; j++) {
                fscanf(infile, "%d", &keysInside[i][j]);
            }
        }
        
        long cnt = 1, cur = 0;
        used[0] = true;
        stack[0] = 0;
        prev[0] = -1;
        step[0] = -1;
        
        kcnt[0] = (short *)calloc(KTYPE, sizeof(short));
        for (int i = 0; i < k; i++) {
            kcnt[0][skeys[i]]++;
        }
        
        long bit[MN] = {0};
        for (int i = 0; i < n; i++)
            bit[i] = 1 << i;
        
        long finVal = (1 << n) - 1;
        bool solved = false;
        
        while (cur < cnt && !solved) {
            long val = stack[cur];
            short *keys = kcnt[cur];
            
            for (int i = 0; i < n; i++) {
                if (!used[val | bit[i]] &&
                    keys[needKey[i]] > 0) {
                    long nval = val | bit[i];
                    used[nval] = true;
                    prev[cnt] = cur;
                    step[cnt] = i;
                    stack[cnt] = nval;
                    kcnt[cnt] = (short *)calloc(KTYPE, sizeof(short));
                    for (int j = 0; j < KTYPE; j++) {
                        kcnt[cnt][j] = keys[j];
                    }
                    for (int j = 0; j < keysCnt[i]; j++) {
                        kcnt[cnt][keysInside[i][j]]++;
                    }
                    kcnt[cnt][needKey[i]]--;
                    
                    if (nval == finVal) {
                        solved = true;
                        break;
                    }
                    cnt++;
                }
            }
            
            cur++;
        }
        
        fprintf(outfile, "Case #%d:", t);
        if (!solved)
            fprintf(outfile, " IMPOSSIBLE\n");
        else {
            long ind = cnt;
            int sol[MN] = {0};
            long st = n;
            while (ind != -1) {
                sol[st] = step[ind] + 1;
                st--;
                ind = prev[ind];
            }
            
            for (int i = 1; i <= n; i++) {
                fprintf(outfile, " %d", sol[i]);
            }
            fprintf(outfile, "\n");
        }
        
        for (int i = 0; i < cnt; i++)
            free(kcnt[i]);
        free(stack);
        free(used);
        free(prev);
        free(step);
        free(kcnt);
    }
    
    fclose(infile);
    fclose(outfile);
}
#endif