//
//  main.c
//  DeceitfulWar
//
//  Created by Shyamsundar Parthasarathy on 4/12/14.
//  Copyright (c) 2014 ___shyam2347___. All rights reserved.
//
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *x, const void *y)
{
    double xx = *(double*)x, yy = *(double*)y;
    if (xx < yy) return -1;
    if (xx > yy) return  1;
    return 0;
}

void compute(double *naomi, double *ken, int numValues, FILE *fpout)
{
    int index;
    int j;
    int kenWin = 0;
    int naomiWin = 0;
    int kenflag;
    double naomiMax = 0;
    double kenChosen;
    int *naomiArray = (int *) malloc(numValues * sizeof(int));
    int *kenArray = (int *) malloc(numValues * sizeof(int));
    
    memset(naomiArray, 0, numValues * sizeof(int));
    memset(kenArray, 0, numValues * sizeof(int));

    // sort input arrays
    qsort(ken, numValues, sizeof(double), cmp);
    qsort(naomi, numValues, sizeof(double), cmp);
    
    //
    // Deceitful WAR
    // Algo - Naomi picks the max value as Told
    // Ken returns least max for Told (this includes least possible from Ken).
    // If ken would win, Naomi throws least possible, else Naomi does least max
    //
    for (index = 0; index < numValues; index++)
    {
        // Get highest possible val
        for (j = numValues-1; j >= 0; j--)
        {
            if (naomiArray[j] == 1)
                continue;
            naomiMax = naomi[j];
            break;
        }
        
        // Ken trying optimal algo
        kenflag = 0;
        for (j = 0; j < numValues; j++)
        {
            if (kenArray[j] == 1)
                continue;
            if (ken[j] > naomiMax)
            {
                kenflag = 1;
                kenArray[j] = 1;
                break;
            }
        }
        if (kenflag == 0)
        {
            for (j = 0; j < numValues; j++)
            {
                if (kenArray[j] == 0)
                {
                    kenArray[j] = 1;
                    break;
                }
            }
            kenChosen = ken[j];
            
            // Naomi finding highest possible deceit value
            for (j = 0; j < numValues; j++)
            {
                if (naomiArray[j] == 1)
                    continue;
                if (naomi[j] > kenChosen)
                {
                    kenflag = 1;
                    naomiArray[j] = 1;
                    naomiWin++;
                    break;
                }
            }
        }
        else
        {
            for (j = 0; j < numValues; j++)
            {
                if (naomiArray[j] == 0)
                {
                    naomiArray[j] = 1;
                    break;
                }
            }
        }
        
    }

    memset(naomiArray, 0, numValues * sizeof(int));
    memset(kenArray, 0, numValues * sizeof(int));
    //
    // WAR
    // Naomi picks in sequential order
    // Ken would anyway optimize for advantage, so no loss in sequential pick
    // Ken tries to find least max, if not found ken gives least element
    //
    for (index = 0; index < numValues; index++)
    {
        kenflag = 0;
        // Ken finds least max in sorted array
        for (j = 0; j < numValues; j++)
        {
            if (kenArray[j] == 1)
                continue;
            if (ken[j] > naomi[index])
            {
                kenflag = 1;
                kenArray[j] = 1;
                kenWin++;
                break;
            }
        }
        // least max not found - throwing the least block
        if (kenflag == 0)
        {
            for (j = 0; j < numValues; j++)
            {
                if (kenArray[j] == 0)
                {
                    kenArray[j] = 1;
                    break;
                }
            }
        }
    }

    fprintf(fpout, "%d ", naomiWin);
    fprintf(fpout, "%d\n", numValues - kenWin);
    free(naomiArray);
    free(kenArray);
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
    int testCaseLines = 3;
    int numValues = 0;
    double *naomi = NULL;
    double *ken = NULL;
    int index = 0;
    
    
    fp = fopen("/Users/shyam2347/Desktop/D-small-attempt0.in", "r");
    if (NULL == fp)
    {
        printf("File not present\n");
        exit(1);
    }
    fpout = fopen("/Users/shyam2347/Desktop/output1.txt", "w");
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
        if (testCaseLines)
        {
            testCaseLines--;

            if (testCaseLines == 2)
            {
                numValues = (int) strtoul(line, NULL, 10);
                naomi = (double *) malloc(sizeof(double) * numValues);
                ken = (double *) malloc(sizeof(double) * numValues);
                memset(naomi, 0, sizeof(double) *numValues);
                memset(ken, 0, sizeof(double) *numValues);
            }
            else if (testCaseLines == 1)
            {
                // naomi values
                index = 0;
                str = strtok(line, " ");
                while (str)
                {
                    naomi[index++] = strtod(str, NULL);
                    str = strtok(NULL, " ");
                }
                //exit(1);
            }
            else if (testCaseLines == 0)
            {
                // ken values
                index = 0;
                str = strtok(line, " ");
                while (str)
                {
                    ken[index++] = strtod(str, NULL);
                    str = strtok(NULL, " ");
                }
                testCaseLines = 3;
                testCaseIndex++;
                
                fprintf(fpout, "Case #%d: ", testCaseIndex);
                compute(naomi, ken, numValues, fpout);
                free(naomi);
                free(ken);
            }
        }
        if (testCaseIndex == numTestCases)
        {
            break;
        }
    }
    fclose(fp);
    fclose(fpout);
    return 0;
}

