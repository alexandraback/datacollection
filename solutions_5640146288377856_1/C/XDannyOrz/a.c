#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
	int TestCase, i;
	int R, C, W;
	int Result;
    
    //FILE* in_file = fopen("a.in", "r");
    //FILE* in_file = fopen("a-small2.in", "r");
    FILE* in_file = fopen("a-large.in", "r");
    
    //FILE* out_file = fopen("a.out", "w");
    //FILE* out_file = fopen("a-small2.out", "w");
    FILE* out_file = fopen("a-large.out", "w");

	fscanf(in_file, "%d", &TestCase);
    
    for (i = 1; i <= TestCase; i++) {
        fscanf(in_file, "%d", &R);
        fscanf(in_file, "%d", &C);
        fscanf(in_file, "%d", &W);
        
        Result = (((C / W) * R) + W - 1);
        if (C % W != 0) {
            Result++;    
        }
        // main program here
        fprintf(out_file ,"Case #%d: %d\n", i, Result);
    }
    
    fclose(in_file);
    fclose(out_file);
	return 0;
}
