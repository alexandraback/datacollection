#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    double A, B, K;
/*---------*/  


int genResult(void)
{
    int i, j, match = 0;
    
    for(i = 0; i < A; i ++)
    {
        for(j = 0; j < B; j ++)
        {
            //printf("%d i %d j %d result %d\n", (i & j) < K, i, j, (i & j));
            if((i & j) < K)
                match ++;
        }
    }
    
    return match;
}


int main(int argc, char *argv[])
{

    char *inFileName = "B-small-attempt0.in";
    char *outFileName = "B-small-attempt0.out";
    int i, j, k;
    int group;
    int num1, num2;
/* Local Variables*/    
    //int A, N;
    int result;
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
         
          fscanf(pInFile, "%lf %lf %lf", &A, &B, &K);
          //printf("str %s val %d\n", str, minLen);
          printf("%lf %lf %lf\n", A, B, K);

          result = genResult();
          
          fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



