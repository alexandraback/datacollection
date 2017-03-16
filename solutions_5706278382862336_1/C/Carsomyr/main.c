//
//  main.c
//  cj_partelf
//
//  Created by Hoyoon on 2014. 5. 11
//  Copyright (c) 2014년 SNU. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

void calculate(FILE *fp, int caseno)
{
    long i, firstone = -1, temp, num[2];
    fscanf(fp, "%ld/%ld", &num[0], &num[1]);
    for(i = 0; i < 40; i++) {
        num[0] = num[0] * 2;
        temp = 0;
        if(num[0] - num[1] >= 0) {
            num[0] = num[0] - num[1];
            temp = 1;
            if(firstone == -1)  firstone = i;
        }
        if(num[0] == 0) {
            printf("Case #%d: %ld\n", caseno+1, firstone+1);
            return;
        }
    }
    printf("Case #%d: impossible\n", caseno+1);
}

int main(int argc, const char * argv[])
{
    
    // insert code here...
    FILE *fp;
    int ctest = 0;
    fp = fopen("input", "r");
    if(!fp || fscanf(fp, "%d", &ctest) == EOF) {
        printf("wrong input file \n");
        exit(-1);
    }
    for(int i = 0; i < ctest; i++) {
        calculate(fp, i);
    }
}

