#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){
    if(argc != 2){
        printf("Forgot file name or added extra arguments.\n");
        return -1;
    }
    
    FILE* fp = fopen(argv[1], "r");
        
    int n_inputs = 0;
    fscanf(fp, "%d", &n_inputs);
    
    int test_case;
    int A, B, K;
    for(test_case = 0; test_case < n_inputs; test_case++){
        int i, j;
        int possible = 0;
        
        fscanf(fp, "%d", &A);
        fscanf(fp, "%d", &B);
        fscanf(fp, "%d", &K);
        
        for(i = 0; i < A; i++){
            for(j = 0; j < B; j++){
                if ((i&j) < K){
                    possible++;
                }
            }
        }
        
        
        printf("Case #%d: %d\n", test_case+1, possible);
    }
    
    fclose(fp);
    
    return 1;
}