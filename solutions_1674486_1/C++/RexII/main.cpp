#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;



/* Global Variables*/    
    int nHir[1000];
    int hir[1000][1000];
    int walk[1000];
/*---------*/  

int walkThrough(int start)
{
    int i;
    walk[start] ++;
    
    if(walk[start] >= 2)
        return 0;
    
    if(nHir[start] == 0)
        return 0;
    else
    {
        for(i = 0; i < nHir[start]; i ++)
        {
            walkThrough(hir[start][i]);
        }
    }
}

int genResult(int nClass)
{
    int i, j, sum;
    for(i = 0; i < nClass; i ++)
    {
        memset(walk, 0, sizeof(walk));
        walkThrough(i);
        /*
        printf("walk:");
        for(j = 0; j < nClass; j ++)
            printf("%d ", walk[j]);
        printf("\n");*/
        for(j = 0; j < nClass; j ++)
        {
          
            if(walk[j] >= 2)
                return 1;
        }
    }
    
    return 0;
}


int powCal(int x, int n)
{
    int i = 0, result = 1;
    for(i = 0; i < n; i ++)
    {
        result *= x;
    }
    
    return result;
}

int main(int argc, char *argv[])
{

    char *inFileName = "A-large.in";
    char *outFileName = "A-large.out";
    int i, j, k;
    int group;
    int num1, num2;
/* Local Variables*/    
    int nClass, result;
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
          memset(nHir, 0, sizeof(nHir));
          memset(hir, 0, sizeof(hir));
          memset(walk, 0, sizeof(walk));
          
          fscanf(pInFile, "%d", &nClass);
          printf("nClass %d\n", nClass);

          for(j = 0; j < nClass; j ++)
          {
                fscanf(pInFile, "%d", &nHir[j]);
                //printf("nHir[%d] %d \n", j, nHir[j]);
                for(k = 0; k < nHir[j]; k ++)
                {
                    fscanf(pInFile, "%d", &hir[j][k]);
                    hir[j][k] = hir[j][k] - 1;
                    //printf("hir[%d][%d] %d\n", j, k, hir[j][k]);
                }
          }
          
          result = genResult(nClass);
          
          if(result == 0)
            fprintf(pOutFile, "Case #%d: No\n", i+1);
          else
            fprintf(pOutFile, "Case #%d: Yes\n", i+1);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



