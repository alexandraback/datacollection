#define DCODE
#ifdef DCODE
#include "stdio.h"
#include "stdlib.h"
#define SUBMIT
#define MN 210
#define SK 410
#define KTYPE 210
//#define KTYPE 6

int main(){
    
#ifdef SUBMIT
    FILE *infile = fopen("D-large.in", "r"),
    *outfile = fopen("D-large.txt", "w");
#else
    FILE *infile = fopen("/CodeJam/D-large.in", "r"),
    *outfile = fopen("/CodeJam/D-large.txt", "w");
#endif
    
    int T;
    fscanf(infile, "%d", &T);
    
    for (int t = 1; t <= T; t++) {
        //printf("Case %d\n", t);
        long n = 0, k = 0;
        fscanf(infile, "%ld%ld", &k, &n);
        
        int totalSum[KTYPE] = {0};
        int skeys[SK] = {0};
        
        for (int i = 0; i < k; i++) {
            fscanf(infile, "%d", skeys + i);
            totalSum[skeys[i]]++;
        }
        
        int needKey[MN] = {0};
        int keysCnt[MN] = {0};
        int keysInside[MN][KTYPE] = {0};
        
                
        for (int i = 0; i < n; i++) {
            fscanf(infile, "%d%d", needKey + i, keysCnt + i);
            totalSum[needKey[i]]--;
            
            for (int j = 0; j < keysCnt[i]; j++) {
                int keyInside = 0;
                fscanf(infile, "%d", &keyInside);
                keysInside[i][keyInside]++;
                totalSum[keyInside]++;
            }
        }
        
        bool solved = true;
        
        long sol[MN] = {0};
        bool used[MN] = {0};
        for (int ind = 0; ind < n; ind++) {
            bool correct = true;
            for (int i = 0; i < KTYPE; i++) {
                if (totalSum[i] < 0)
                {
                    correct = false;
                    break;
                }
            }
            
            if (!correct) {
                solved = false; break;
            }
            
            bool founded = false;
            for (long chest = n - 1; chest >= 0; chest--)
                if (!used[chest]) {
                   bool correct = true;
                    
                    for (int i = 0; i < KTYPE; i++) {
                        if (totalSum[i] - keysInside[chest][i] < 0) {
                            correct = false; break;
                        }
                    }
                    
                    if (correct) {
                        founded = true;
                        used[chest] = true;
                        sol[n - ind] = chest + 1;
                        
                        for (int i = 0; i < KTYPE; i++) {
                            totalSum[i] -= keysInside[chest][i];
                        }
                        
                        totalSum[needKey[chest]]++;
                        break;
                    }
                }
            
            if (!founded) {
                solved = false; break;
            }
        }
        
        fprintf(outfile, "Case #%d:", t);
        if (!solved)
            fprintf(outfile, " IMPOSSIBLE\n");
        else {
            for (int i = 1; i <= n; i++) {
                fprintf(outfile, " %ld", sol[i]);
            }
            fprintf(outfile, "\n");
        }
        
    }
    
    fclose(infile);
    fclose(outfile);
}
#endif