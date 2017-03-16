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

void flip(int count, int *cakes, int flipCount){
    int flipCakes[flipCount];
    for (int i = 0; i < flipCount; i++) {
        flipCakes[i] = -cakes[i];
    }
    for (int i = 0; i < flipCount; i++) {
        cakes[i] = flipCakes[flipCount - 1 - i];
    }
}

int needFlipCakes(int count, int *cakes){
    int needFlip = count;
    for (int i = count - 1; i >= 0; i--) {
        if (cakes[i] > 0) {
            needFlip--;
        }
        else{
            break;
        }
    }
    return needFlip;
}

int main(int argc, const char * argv[]) {
    FILE *input = fopen("B-small-attempt1.in.txt", "r");
    FILE *output = fopen("B-small-attempt1.out.txt", "w");
    
    int T;
    fscanf(input, "%d\n", &T);
    
    for (int Case = 0; Case < T; Case++) {
        char *in;
        size_t t;
        int count = (int)getline(&in, &t, input);
        if (in[count - 1] == '\n') {
            count--;
        }
        int cakes[count];
        for (int i = 0; i < count; i++) {
            cakes[i] = in[i] == '+' ? 1 : -1;
        }
        int needFlip = needFlipCakes(count, cakes);
        int flipCount = 0;
        while (needFlip > 0) {
            int negativeFlipCount = 0;
            for (int i = 0; i < needFlip; i++) {
                if (cakes[i] < 0) {
                    negativeFlipCount++;
                }
                else{
                    break;
                }
            }
            if (negativeFlipCount > 0) {
                flipCount++;
                flip(count, cakes, needFlip);
                needFlip = needFlipCakes(count, cakes);
            }
            else{
                int positiveFlipCount = 0;
                int maxPositive = 0;
                int positive = 0;
                for (int i = 0; i < needFlip; i++) {
                    if (cakes[i] > 0) {
                        positive++;
                        if (positive > maxPositive) {
                            maxPositive = positive;
                            positiveFlipCount = i + 1;
                        }
                        else{
                            positive = 0;
                        }
                    }
                }
                
                if (positiveFlipCount == needFlip) {
                    break;
                }
                else if (positiveFlipCount == 0){
                    flipCount++;
                    break;
                }
                else{
                    flipCount += 2;
                    flip(count, cakes, positiveFlipCount);
                    flip(count, cakes, needFlip);
                    needFlip = needFlipCakes(count, cakes);
                }
            }
            
            
        }
        fprintf(output, "Case #%d: %d\n", Case + 1, flipCount);
    }
    
    fclose(input);
    fclose(output);
    return 0;
}
