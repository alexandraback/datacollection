//
//  main.c
//  ProblemD
//
//  Created by ianto on 4/9/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, const char * argv[]) {
    FILE *input = fopen("D-small-attempt0.in.txt", "r");
    FILE *output = fopen("D-small-attempt0.out.txt", "w");

    int T;
    fscanf(input, "%d", &T);

    for (int Case = 0; Case < T; Case++) {
        int K, C, S;
        fscanf(input, "%d %d %d", &K, &C, &S);
        
        if (K != S) {
            //  Google cheat us!!!
        }
        
        fprintf(output, "Case #%d:", Case + 1);
        for (int i = 0; i < K; i++) {
            fprintf(output, " %d", i+1);
        }
        fprintf(output, "\n");
    }

    fclose(input);
    fclose(output);
    return 0;
}
