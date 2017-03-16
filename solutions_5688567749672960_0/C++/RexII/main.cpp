#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    int ans1, ans2;
    long long num, reverseNum;
    
/*---------*/  

long long big()
{
    long long temp, big;
    temp = num;
    while(temp > 0)
    {
        big = temp %10;
        temp /=10;
    }
    return big;
}


int count()
{
    
    long long result = 0;
    long long bigN, smallN;
    bigN = big();
    smallN = num %10;
    
    result = 1;
    
    while(num > 1)
    {
        if(smallN == 0)
        {
            num -= 1;
            result ++;
            bigN = big();
            smallN = num %10;
            //printf("1->%I64d (%I64d %I64d)\n", num, bigN, smallN);
        }
        else if((bigN > smallN) && (smallN == 1)) // reverse
        {
            reverseNum = 0;
            
            while(num > 0)
            {
                reverseNum *=10;
                smallN = num % 10;
                reverseNum += smallN;
                num /= 10;
            }
    
            num = reverseNum;
            bigN = big();
            smallN = num %10;
            
            result ++;
            //printf("2->%I64d (%I64d %I64d)\n", num, bigN, smallN);
        }
        else
        {
            if(smallN > 1)
            {
                result += smallN - 1;
                num -= smallN;
                num += 1;
                bigN = big();
                smallN = num %10;
                //printf("3->%I64d (%I64d %I64d)\n", num, bigN, smallN);
            }
            else
            {
                result += 1;
                num -= smallN;
                bigN = big();
                smallN = num %10;
                //printf("4->%I64d (%I64d %I64d)\n", num, bigN, smallN);
            }
        }   
    }
    return result;
}





int main(int argc, char *argv[])
{

    char *inFileName = "A.in";
    char *outFileName = "A.out";
    int i, j, k;
    int group;
/* Local Variables*/    
    //int A, N;
    long long result;
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
          fscanf(pInFile, "%I64d\n", &num);
          printf("%I64d\n", num);
          result = count();
          
          fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



