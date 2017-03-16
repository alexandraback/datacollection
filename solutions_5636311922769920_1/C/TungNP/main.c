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

typedef unsigned long long ul;

ul descendent(ul index, int K, int C){
    ul des = 0;
    while (C > 0) {
        C--;
        des += powl(K, C) * index;
    }
    return des;
}

int main(int argc, const char * argv[]) {
    FILE *input = fopen("D-large.in.txt", "r");
    FILE *output = fopen("D-large.out.txt", "w");

    int T;
    fscanf(input, "%d", &T);

    for (int Case = 0; Case < T; Case++) {
        int K, C, S;
        fscanf(input, "%d %d %d", &K, &C, &S);
        
        if (C == 1 || K == 1) {
            if (S >= K) {
                fprintf(output, "Case #%d:", Case + 1);
                for (int i = 0; i < K; i++) {
                    fprintf(output, " %d", i + 1);
                }
                fprintf(output, "\n");
            }
            else{
                fprintf(output, "Case #%d: IMPOSSIBLE\n", Case + 1);
            }
        }
        else{
            int studentNeeded = K / 2 + K % 2;
            if (S < K / 2 + K % 2) {
                fprintf(output, "Case #%d: IMPOSSIBLE\n", Case + 1);
            }
            else{
                ul indexes[studentNeeded];
                for (ul i = 0; i < K / 2; i++) {
                    indexes[i] = descendent(i * 2, K, C) + 1;
                }
                if (K % 2 == 1) {
                    indexes[K / 2] = descendent(K - 1, K, C);
                }
                fprintf(output, "Case #%d:", Case + 1);
                for (ul i = 0; i < studentNeeded; i++) {
                    fprintf(output, " %llu", indexes[i] + 1);
                }
                fprintf(output, "\n");
            }
        }
    }

    fclose(input);
    fclose(output);
    return 0;
}
