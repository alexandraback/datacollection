/* 
 * File:   main_problem_c.c
 * Author: paulo
 *
 * Created on 13 de Abril de 2013, 01:12
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tag_Data
{
    unsigned long long number;
    unsigned long long sqr;
}Data;

int ispalyndrome(char *text)
{
    int count, size, limit;
    size = strlen(text);
    limit = size/2;
    for(count=0;count<limit;count++)
    {
        if(text[count] != text[size-1-count])
            return 0;
    }
    return -1;
}

/*
 * 
 */
int main(int argc, char** argv) {

    Data pnumbers[500];
    int total = 0;
    unsigned long long count, result, lower, upper;
    char text1[101], text2[100];
    int cases, start, end, pos;
    for(count=1;count<20000003;count++)
    {
        result = count*count;
        sprintf(text1, "%llu", count);
        sprintf(text2, "%llu", result);
        if(ispalyndrome(text1))
            if(ispalyndrome(text2))
            {
                pnumbers[total].number = result;
                pnumbers[total].sqr = count;
                total++;
                /*printf("Found %d fair palyndromes\n", total);*/
            }
    }
    /*printf("\n");
    for(count=0;count<total;count++)
        printf("Fair = %llu (sqrt=%llu)\n", pnumbers[count].number, pnumbers[count].sqr);*/
    scanf("%d", &cases);
    for(count=0;count<cases;count++)
    {
        scanf("%llu %llu", &lower, &upper);
        for(pos=0;pos<total;pos++)
            if(pnumbers[pos].number >= lower)
            {
                start=pos;
                break;
            }
        for(pos=start;pos<total;pos++)
            if(pnumbers[pos].number > upper)
            {
                end=pos-1;
                break;
            }
        printf("Case #%d: %d\n", count+1, end-start+1);
    }
    
    
    return (EXIT_SUCCESS);
}

