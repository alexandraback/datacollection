//
//  main.cpp
//  abcd
//
//  Created by cyanic MayDay on 12-4-14.
//  Copyright (c) 2012年 __MyCompanyName__. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <fstream>
#include <math.h>

int vec[8];


bool includeVector(int num, int k)
{
    for (int i = 1; i < k; i ++) {
        if (vec[i] == num) {
            return true;
        }
    }
    return false;
}


int RecycledNumbers(int A, int B)
{
    int total = 0;
    int temp = A;
    int k = 0;
    while (temp) {
        temp /= 10;
        k ++;
    }
    
    for (int i = A; i <= B; i ++) {
        for (int j = 1; j < k; j ++) {
            temp = (i % (int)pow(10, j)) * (int)pow(10, k - j) + i / (int)pow(10, j);
            vec[j] = temp;
            if ( temp <= B && i < temp && (!includeVector(temp, j))) {
                total ++;
            }
        }
    }
    return total;
}



int main(int argc, const char * argv[])
{
    freopen("/Users/ccyanic/Downloads/C-small-attempt0.in.txt", "r", stdin);
    freopen("/Users/ccyanic/Downloads/C-small-attempt0.txt", "w", stdout);
    int n = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i ++) {
        int A, B;
        scanf("%d %d", &A, &B);
        printf("Case #%d: %d\n",(i + 1) , RecycledNumbers(A, B));
    }
    
    
    return 0;
}

