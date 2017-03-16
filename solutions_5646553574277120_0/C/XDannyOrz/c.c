#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int TestCase, i, j, k;
	int C, D, V;
    int Dval[50];
    int tmp;
    int Result;
    
    //FILE* in_file = fopen("c.in", "r");
    FILE* in_file = fopen("c-small.in", "r");
    //FILE* in_file = fopen("c-large.in", "r");
    
    //FILE* out_file = fopen("c.out", "w");
    FILE* out_file = fopen("c-small.out", "w");
    //FILE* out_file = fopen("c-large.out", "w");

	fscanf(in_file, "%d", &TestCase);
    
    for (i = 1; i <= TestCase; i++) {
        for (j = 0; j <= 30; j++) {
            Dval[j] = 0;
        }
        
        Result = 0;
        fscanf(in_file, "%d", &C);
        fscanf(in_file, "%d", &D);
        fscanf(in_file, "%d", &V);
        
        for (j = 0; j < D; j++) {
            fscanf(in_file, "%d", &tmp);
            Dval[tmp] = 1;
        }
        
        for (j = 1; j <= V; j++) {
            tmp = j;
            for (k = j; k > 0; k--) {
                if (Dval[k] == 1) {
                    if (tmp >= k) {
                        tmp -= k;    
                    }
                }
            }
            if (tmp != 0) {
                Result++;
                k = 1;
                while (Dval[k] == 1) {
                    k++;    
                }
                Dval[k] = 1;
                j--;
            }
        }

        // main program here
        fprintf(out_file ,"Case #%d: %d\n", i, Result);
    }
    
    fclose(in_file);
    fclose(out_file);
	return 0;
}
