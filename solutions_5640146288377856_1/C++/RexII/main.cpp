#include <cstdlib>
#include <iostream>
#include <stdio.h>

using namespace std;

char map[] = {'y', 'n', 'f', 'i', 'c', 'w', 'l', 'b', 'k',
    'u', 'o', 'm', 'x', 's', 'e', 'v', 'z', 'p', 'd', 'r', 'j', 'g',
    't', 'h', 'a', 'q'};

int T, R, C, W;
int result;

int main(int argc, char *argv[])
{
    FILE * pInFile, *pOutFile;
    char *inFileName = "A-large.in";
    char *outFileName = "A-large.out";
    int i, j, k, mul, remain;
    
    
    if((pInFile = fopen(inFileName, "r")) == NULL)
          printf("error open file\n");
    
    if((pOutFile = fopen(outFileName, "w")) == NULL)
          printf("error open file\n");

    fscanf(pInFile, "%d", &T);
    printf("T %d\n", T);

    for(i =0; i< T; i++)
    {
        fscanf(pInFile, "%d %d %d\n", &R, &C, &W);
        printf("%d %d %d\n", R, C, W);
        
        mul = C/W;
        remain = C%W;
        result = (mul-1) + W;
        if(remain>0)
            result +=1;
            
        result += mul * (R-1);
        printf("%d %d %d\n", mul, remain, result);

        fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
        printf("Case #%d: %d\n", i+1, result);
    }
  
    
    fclose(pInFile);
    fclose(pOutFile);
    system("PAUSE");
    return EXIT_SUCCESS;
}
