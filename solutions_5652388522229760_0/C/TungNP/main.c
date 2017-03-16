//
//  main.c
//  ProblemA
//
//  Created by ianto on 4/9/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


int main(int argc, const char * argv[]) {
    FILE *input = fopen("A-small-attempt0.in.txt", "r");
    FILE *output = fopen("A-small-attempt0.out.txt", "w");
    
    int T;
    fscanf(input, "%d", &T);
    
    for (int Case = 0; Case < T; Case++) {
        int N;
        fscanf(input, "%d", &N);
        
        if (N == 0) {
            fprintf(output, "Case #%d: INSOMNIA\n", Case + 1);
        }
        else{
            int appeared[10];
            int count = 0;
            int currentN = N;
            while (count < 10) {
                int NCopy = currentN;
                while (NCopy > 0) {
                    int digit = NCopy % 10;
                    bool repeated = false;
                    for (int i = 0; i < count; i++) {
                        if (appeared[i] == digit) {
                            repeated = true;
                            break;
                        }
                    }
                    if (!repeated) {
                        appeared[count] = digit;
                        count++;
                    }
                    NCopy /= 10;
                }
                if (count != 10) {
                    currentN += N;
                }
            }
            fprintf(output, "Case #%d: %d\n",Case + 1, currentN);
        }
    }
    
    fclose(input);
    fclose(output);
    return 0;
}
