#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    long long D[10], N, H[10], M[10], people, curPeople;
/*---------*/  

/*
int sep(int low, int high)
{
    int i;
    int minutes = 0;
    
    for(i = low; i <= high; i ++)
    {
        if((i & 1) != 0)
        {
            pieNum[i/2 + 1] += pieNum[i];
            pieNum[i/2] += pieNum[i];
            minutes += pieNum[i];
            pieNum[i] = 0;
        }
        else
        {
            pieNum[i/2] += pieNum[i]*2;
            minutes += pieNum[i];            
            pieNum[i] = 0;
        }
    }
    printf("minutes %d\n", minutes);
    
    return minutes;
} 


int count()
{
    int i, j;
    int sum;
    int result = 0;
        
    for(i = maxPie; i >= 0; i --)
    {
        if(pieNum[i] == 0)
            continue;
            
        sum = 0;
        printf("i %d ceil+1 %f\n", i, ceil(((double)i)/2.0)+1);
        for(j = ceil(((double)i)/2.0)+1; j <= i; j++)
        {
            sum += pieNum[j];
        }
        
        if((int)(i/2) > sum)
        {
            result += sep(ceil(((double)i)/2.0)+1, i);
        }
        else
            return result + i;
    }
    
    return result;
}
*/



int main(int argc, char *argv[])
{

    char *inFileName = "C.in";
    char *outFileName = "C.out";
    long long i, j;
    int k;
    int group;
    int ans1, ans2;
/* Local Variables*/    
    //int A, N;
    int result;
    long long tmp;
/*---------*/    
    FILE * pInFile, *pOutFile;
    

    if((pInFile = fopen(inFileName, "r")) == NULL)
          printf("error open file\n");

    if((pOutFile = fopen(outFileName, "w")) == NULL)
          printf("error open file\n");

    

    fscanf(pInFile, "%d", &group);
    printf("group %d\n", group);
    for(i =0; i< group; i++)
    {
        people = 0;
        fscanf(pInFile, "%I64d\n", &N);
        printf("N: %I64d\n", N);
        for(j = 0; j < N; j ++)
        {
            fscanf(pInFile, "%I64d %I64d %I64d\n", &(D[people]), &curPeople, &(M[people]));
            people ++;
            if(curPeople == 2)
            {
                D[people] = D[people-1];
                M[people] = M[people-1]+1;
            }
        }
        //printf("%s\n", str);
        
        if(people < 2)
            fprintf(pOutFile, "Case #%d: 0\n", i+1);
        else
        {
            if(D[0] < D[1])
            {
                tmp = D[0];
                D[0] = D[1];
                D[1] = tmp;
                tmp = M[0];
                M[0] = M[1];
                M[1] = tmp;
            }
            if(M[0] > M[1])
            {
                if((360-D[0])*M[0] >= (720-D[1])*M[1])
                {
                    fprintf(pOutFile, "Case #%d: 1\n", i+1);
                    printf("case 1 (%I64d,%I64d),(%I64d,%I64d),(%I64d,%I64d)\n", D[0], M[0], D[1], M[1],
                    (360-D[0])*M[0] ,(720-D[1])*M[1]);
                }
                else
                {
                    fprintf(pOutFile, "Case #%d: 0\n", i+1);
                    printf("case 2 (%I64d,%I64d),(%I64d,%I64d),(%I64d,%I64d)\n", D[0], M[0], D[1], M[1],
                    (360-D[0])*M[0] ,(720-D[1])*M[1]);
                }
            }
            else
            {
                if((360-D[1])*M[1] >=(720-D[0])*M[0])
                {
                    fprintf(pOutFile, "Case #%d: 1\n", i+1);
                    printf("case 3 (%I64d,%I64d),(%I64d,%I64d),(%I64d,%I64d)\n", D[0], M[0], D[1], M[1],
                    (360-D[1])*M[1],(720-D[0])*M[0]);
                }
                else
                {
                    fprintf(pOutFile, "Case #%d: 0\n", i+1);
                    printf("case 4 (%I64d,%I64d),(%I64d,%I64d),(%I64d,%I64d)\n", D[0], M[0], D[1], M[1],
                    (360-D[1])*M[1],(720-D[0])*M[0]);
                }
            }
        }
    
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



