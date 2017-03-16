//
//  main.c
//  ProblemC
//
//  Created by ianto on 4/9/16.
//  Copyright © 2016 TungNguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef unsigned long long ul;

ul generatePrimeNumber(ul count, ul *primeNumber){
    if (count <= 2) {
        return 0;
    }
    primeNumber[0] = 2;
    ul primeCount = 1;
    for (ul num = 3; num < count; num += 2) {
        ul root = sqrtl(num);
        bool isPrime = true;
        for (ul i = 0; i < primeCount; i++) {
            if (primeNumber[i] > root) {
                break;
            }
            if (num % primeNumber[i] == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime){
            primeNumber[primeCount] = num;
            primeCount++;
        }
    }
    return primeCount;
}

ul base10ToBase(ul num, int base){
    if (base == 10) {
        return num;
    }
    ul result = 0;
    ul mul = 1;
    while (num > 0) {
        result += (num % 10) * mul;
        mul *= base;
        num /= 10;
    }
    return result;
}

ul base2ToBase10(ul num){
    ul result = 0;
    ul mul = 1;
    while (num > 0) {
        result += (num % 2) * mul;
        mul *= 10;
        num /= 2;
    }
    return result;
}

int main(int argc, const char * argv[]) {
    FILE *input = fopen("C-small-attempt1.in.txt", "r");
    FILE *output = fopen("C-small-attempt1.out.txt", "w");
    
    int T;
    fscanf(input, "%d", &T);
    
    for (int Case = 0; Case < T; Case++) {
        int N, J;
        fscanf(input, "%d %d", &N, &J);
        fprintf(output, "Case #%d:\n", Case + 1);
        ul numMax = 0;
        ul numMin = 0;
        for (int i = N - 1; i >= 0; i--) {
            numMax += powl(10, i);
            if (i == N - 1 || i == 0) {
                numMin += powl(10, i);
            }
        }
        ul square = sqrtl(numMax);
        ul *primeNumber = malloc(sizeof(ul) * square);
        ul primeCount = generatePrimeNumber(square, primeNumber);
        
        int jamCoinCount = 0;
        ul base2Min = powl(2, N - 1) + 1;
        ul base2Max = powl(2, N) - 1;
        for (ul num = base2Min; num <= base2Max; num += 2) {
            ul divisors[9];
            bool isJamCoin = true;
            ul base10Num = base2ToBase10(num);
            for (int base = 2; base <= 10; base++) {
                ul baseNum = base10ToBase(base10Num, base);
                ul squareBaseNum = sqrtl(baseNum);
                
                bool found = false;
                for (ul i = 0; i < primeCount; i++) {
                    if (primeNumber[i] <= squareBaseNum && baseNum % primeNumber[i] == 0) {
                        divisors[base - 2] = primeNumber[i];
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    isJamCoin = false;
                    break;
                }
            }
            if (isJamCoin) {
                fprintf(output, "%llu", base10Num);
                for (int i = 0; i < 9; i++) {
                    fprintf(output, " %llu", divisors[i]);
                }
                fprintf(output, "\n");
                jamCoinCount++;
                if (jamCoinCount == J) {
                    break;
                }
            }
        }
        free(primeNumber);
    }
    
    fclose(input);
    fclose(output);
    
    
    return 0;
}
