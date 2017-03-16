//
//  main.c
//  CookieClicker
//
//  Created by Shyamsundar Parthasarathy on 4/12/14.
//  Copyright (c) 2014 ___shyam2347___. All rights reserved.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_SPEED 2

typedef union input
{
    struct data
    {
        double C;
        double F;
        double X;
    }s;
    double arr[3];
}INPUT;

void compute (double C, double F, double X, FILE *fpout)
{
    double cookieSpeed = DEFAULT_SPEED;
    double newTime = 0.0;
    double oldTime = 0.0;
    double cumTime = 0.0;

    oldTime = X/cookieSpeed;
    while (1)
    {
        cumTime += C/cookieSpeed;
        cookieSpeed += F;
        newTime = X/cookieSpeed + cumTime;
        if (newTime >= oldTime)
        {
            break;
        }
        else
        {
            oldTime = newTime;
        }
    }
    fprintf(fpout, "%.7lf\n", oldTime);
}

int main(int argc, const char * argv[])
{
    // Standard variables
    FILE *fp;
    FILE *fpout;
    ssize_t read;
    char *line  = NULL;
    size_t len  = 0;
    
    // Problem variables
    char *str;
    int lineNum = 0;
    int numTestCases = 0;
    int testCaseIndex = 0;
    int index;
    INPUT in;
    
    fp = fopen("/Users/shyam2347/Desktop/B-small-attempt0.in", "r");
    if (NULL == fp)
    {
        printf("File not present\n");
        exit(1);
    }
    fpout = fopen("/Users/shyam2347/Desktop/output.txt", "w");
    if (NULL == fpout)
    {
        printf("File not present\n");
        exit(1);
    }
    while ((read = getline(&line, &len, fp)) != -1)
    {
        if (lineNum++ == 0)
        {
            numTestCases = (int) strtoul(line, NULL, 10);
            continue;
        }
        testCaseIndex++;
        index = 0;
        memset(&in, 0, sizeof(INPUT));

        str = strtok(line, " ");
        while (str)
        {
            in.arr[index++] = strtod(str, NULL);
            str = strtok(NULL, " ");
        }
        fprintf(fpout, "Case #%d: ", testCaseIndex);
        compute(in.s.C, in.s.F, in.s.X, fpout);
        if (testCaseIndex == numTestCases)
        {
            break;
        }
    }
    fclose(fp);
    fclose(fpout);
    return 0;

}

