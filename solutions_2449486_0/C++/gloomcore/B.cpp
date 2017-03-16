#define BCODE
#ifdef BCODE
#define SUBMIT
#include "stdio.h"

int main(){
#ifdef SUBMIT
    FILE *infile = stdin,
    *outfile = stdout;
#else
    FILE *infile = fopen("/CodeJam/B.in", "r"),
    *outfile = fopen("/CodeJam/B.txt", "w");
#endif
    
    int T;
    fscanf(infile, "%d", &T);
    
    for (int t = 1; t <= T; t++) {
        bool possible = true;
        int count[101] = {0};
        
        int mat[101][101] = {0};
        int n, m;
        fscanf(infile, "%d%d", &n, &m);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                fscanf(infile, "%d", &mat[i][j]);
                count[mat[i][j]]++;
            }
        
        bool used[101][101] = {0};
        bool rcut[101] = {0}, ccut[101] = {0}, rsame[101] = {0}, csame[101] = {0};
        int rval[101] = {0}, cval[101] = {0};
        
        for (int ind = 1; ind <= 100; ind++)
            if (count[ind] > 0) {
                for (int i = 0; i < n; i++)
                    if (!rcut[i] && !rsame[i]){
                        rval[i] = -1;
                        rsame[i] = true;
                        
                        for (int j = 0; j < m; j++) {
                            if (used[i][j])
                                continue;
                            else if (rval[i] == -1)
                                rval[i] = mat[i][j];
                            else if (mat[i][j] != rval[i])
                            {
                                rsame[i] = false; break;
                            }
                        }
                    }
                
                for (int i = 0; i < m; i++)
                    if (!ccut[i] && !csame[i]){
                        cval[i] = -1;
                        csame[i] = true;
                        
                        for (int j = 0; j < n; j++) {
                            if (used[j][i]) {
                                continue;
                            }
                            else if (cval[i] == -1)
                                cval[i] = mat[j][i];
                            else if (mat[j][i] != cval[i])
                            {
                                csame[i] = false; break;
                            }
                        }
                    }
                
                
                for (int i = 0; i < n; i++) {
                    if (!rcut[i] && rsame[i] && rval[i] == ind) {
                        rcut[i] = true;
                        
                        for (int j = 0; j < m; j++)
                            if (!used[i][j])
                            {
                                count[ind]--;
                                used[i][j] = true;
                            }
                    }
                }
                
                for (int i = 0; i < m; i++) {
                    if (!ccut[i] && csame[i] && cval[i] == ind) {
                        ccut[i] = true;
                        
                        for (int j = 0; j < n; j++)
                            if (!used[j][i]) {
                                count[ind]--;
                                used[j][i] = true;
                            }
                    }
                }
                
                if (count[ind] > 0) {
                    possible = false; break;
                }
            }
        
        
        fprintf(outfile, "Case #%d: %s\n", t, (possible ? "YES" : "NO"));
    }
    
    fclose(infile);
    fclose(outfile);
}
#endif