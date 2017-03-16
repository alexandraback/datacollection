#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    int minLen;
    char str[1000000];
/*---------*/  


int genResult(void)
{
    int i, j;
    int len, val, result;
    
    len = strlen(str);
    
    for(i = 0; i < len; i ++)
    {
        switch(str[i])
        {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                str[i] = 0;
                break;
            default:
                str[i] = 1;
        }
    }
    
    result = 0;
    for(i = 0; i<= len - minLen; i ++)
    {
        val = 0;
        for(j = i; j < len; j ++)
        {
            if(str[j] == 0)
                val = 0;
            else
                val += str[j];
            if(val == minLen)
            {
                result += (len-j);
                //printf("%d %d\n", i, j);
                break;
            }
        }
    }
    
    return result;
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
          
          fscanf(pInFile, "%s %d", str, &minLen);
          //printf("str %s val %d\n", str, minLen);
          

          result = genResult();
          
          fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



