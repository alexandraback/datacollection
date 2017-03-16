#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    int x, y;
    char str[2000000];
/*---------*/  


int genResult(void)
{
    int i;
    memset(str, 0, sizeof(str));
    if(x < 0)
    {
        for(i = 0; i > x; i --)
        {
            strcat(str, "EW");
        }
    }
    else
    {
        for(i = 0; i < x; i ++)
        {
            strcat(str, "WE");
        }
    }
    
    if(y < 0)
    {
        for(i = 0; i > y; i --)
        {
            strcat(str, "NS");
        }
    }
    else
    {
        for(i = 0; i < y; i ++)
        {
            strcat(str, "SN");
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
          memset(str, 0, sizeof(str));
          
          fscanf(pInFile, "%d %d", &x, &y);
          //printf("str %s val %d\n", str, minLen);
          printf("%d %d %d\n", i, x, y);

          genResult();
          
          fprintf(pOutFile, "Case #%d: %s\n", i+1, str);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



