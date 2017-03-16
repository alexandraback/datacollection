//
//  main.c
//  ProblemCLarge
//
//  Created by ianto on 4/9/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, const char * argv[]) {
        FILE *input = fopen("C-large.in.txt", "r");
        FILE *output = fopen("C-large.out.txt", "w");
    
        int T;
        fscanf(input, "%d", &T);
    
    for (int Case = 0; Case < 1; Case++) {
        int N, J;
        fscanf(input, "%d %d", &N, &J);
        fprintf(output, "Case #%d:\n", Case + 1);
        
        char baseString[N];
        for (int i = 0; i < N; i++) {
            if (i == 0 || i == N - 1) {
                baseString[i] = '1';
            }
            else{
                baseString[i] = '0';
            }
        }
        int count = 0;
        baseString[1] = baseString[3] = baseString[5] = '1';
        baseString[2] = baseString[4] = '1';
        for (int i = 7; i < N - 1; i += 2) {
            for (int j = 6; j < N - 1; j += 2) {
                for (int k = j + 2; k < N - 1; k += 2) {
                    char string[N];
                    for (int l = 0; l < N; l++) {
                        string[l] = baseString[l];
                    }
                    string[i] = string[j] = string[k] = '1';
                    for (int l = 0; l < N; l++) {
                        fprintf(output, "%c", string[l]);
                    }
                    fprintf(output, " 3 2 5 2 5 2 3 2 11\n");
                    count++;
                    
                    if (count == J) {
                        fclose(input);
                        fclose(output);
                        return 0;
                    }
                }
            }
        }
    }
    
        fclose(input);
        fclose(output);
    return 0;
}
