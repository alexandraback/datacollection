#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;




/* Global Variables*/    
    unsigned __int64 nP1[100];
    int tP1[100];
    unsigned __int64 nP2[100];
    int tP2[100];
    int totalP1;
    int totalP2;
    unsigned __int64 maxGenToy;
/*---------*/  

int genToy(int wP1, unsigned __int64 rP1, int wP2, unsigned __int64 rP2, unsigned __int64 gened)
{
    unsigned __int64 gen;
    
    //printf("%d %d %d %d %d\n", wP1, rP1, wP2, rP2, gened);
    
    if((wP1 == (totalP1 - 1) && rP1 == 0) || (wP2 == (totalP2 - 1) &&  rP2 == 0))
    {
        if(gened > maxGenToy)
            maxGenToy = gened;
            
        return 0;
    }
    
    if(tP1[wP1] == tP2[wP2])
    {
        if(rP1 > rP2)
        {
            gen = rP2;
            if(wP2 + 1 < totalP2)
                genToy(wP1, rP1 - gen, wP2 + 1, nP2[wP2+1], gened + gen);
            else
                genToy(wP1, rP1 - gen, wP2, 0, gened + gen);
        }
        else
        {
            gen = rP1;
            
            if(wP1 + 1 < totalP1)
                genToy(wP1+1, nP1[wP1+1], wP2, rP2 - gen, gened + gen);
            else
                genToy(wP1, 0, wP2, rP2 - gen, gened + gen);
        }

    }
    else 
    {
        if(wP1 + 1 < totalP1)
            genToy(wP1+1, nP1[wP1+1], wP2, rP2, gened);
            
        if(wP2 + 1 < totalP2)
            genToy(wP1, rP1, wP2+1, nP2[wP2+1], gened);
    }
    
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

    char *inFileName = "C-small-attempt1.in";
    char *outFileName = "C-small-attempt1.out";
    int i, j;
    int group;
    int num1, num2;
/* Local Variables*/    
    int val, result;
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
          memset(nP1, 0, sizeof(nP1));
          memset(tP1, 0, sizeof(tP1));
          memset(nP2, 0, sizeof(nP2));
          memset(tP2, 0, sizeof(tP2));
          totalP1 = 0;
          totalP2 = 0;
          maxGenToy = 0;
          
          fscanf(pInFile, "%d", &totalP1);
          fscanf(pInFile, "%d", &totalP2);
          printf("totalP1 %d totalP2 %d\n", totalP1, totalP2);

          for(j = 0; j < totalP1; j ++)
          {
                fscanf(pInFile, "%I64u", &nP1[j]);
                fscanf(pInFile, "%d", &tP1[j]);
                printf("P1 %I64u %d %d %d\n", nP1[j], tP1[j], num2);

          }
          
          for(j = 0; j < totalP2; j ++)
          {
                fscanf(pInFile, "%I64u", &nP2[j]);
                fscanf(pInFile, "%d", &tP2[j]);
                //printf("P2 %d %d\n", nP2[j], tP2[j]);
          }
          
          genToy(0, nP1[0], 0, nP2[0], 0);
          
          fprintf(pOutFile, "Case #%d: %I64u\n", i+1, maxGenToy);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



