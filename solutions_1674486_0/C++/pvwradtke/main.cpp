/* 
 * File:   main.cpp
 * Author: paulo
 *
 * Created on 5 de Maio de 2012, 12:42
 */

#include <stdio.h>
#include <math.h>

/*
 * 
 */
int main(int argc, char** argv) {

    int grades[200];
    int T;
    scanf("%d", &T);
    for(int i=0;i<T;i++)
    {
        int N;
        scanf("%d", &N);
        int total=0;
        int max=-1;
        for(int j=0;j<N;j++)
        {
            scanf("%d", &grades[j]);
            total+=grades[j];
            if(max<grades[j])
                max = grades[j];
        }
        printf("Case #%d:", i+1);
        // the normalized score
        double score = (double)total*2/(double)N;
        if(score < (double)max);
        score = (double)max;
        // Calculates Si for each contestant
        for(int j=0;j<N;j++)
        {
            double s = (score-grades[j])/(double)total;
            if(s>=0)
                printf(" %lf", s*100);
            else
                printf(" A.AAAAAA");
        }
        printf("\n");
    }
    
    return 0;
}

