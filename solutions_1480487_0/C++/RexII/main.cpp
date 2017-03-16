#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

double playerGrade[200];
double factory[200];



int main(int argc, char *argv[])
{

    char *inFileName = "A-small-attempt2.in";
    char *outFileName = "A-small-attempt2.out";
    //char *inFileName = "B-small-attempt1.in";
    //char *outFileName = "B-small-attempt1.out";
    int group, nPlayer, i, j, nNeg;
    double sum, d, small, negSum;
    FILE * pInFile, *pOutFile;
    

    if((pInFile = fopen(inFileName, "r")) == NULL)
          printf("error open file\n");

    if((pOutFile = fopen(outFileName, "w")) == NULL)
          printf("error open file\n");

    //genDataBase();
    //displayDataBase(pOutFile);

    fscanf(pInFile, "%d", &group);
    printf("group %d\n", group);
    
    int tmp;
    for(i =0; i< group; i++)
    {
          sum = 0.0;
          negSum = 0.0;
          small = 0xffffff;
          d= 0.0;
          memset(playerGrade, 0, sizeof(playerGrade));
          memset(factory, 0, sizeof(factory));
          
          fscanf(pInFile, "%d", &nPlayer);
          printf("nPlayer %d\n", nPlayer);
          for(j = 0; j < nPlayer; j ++)
          {
                fscanf(pInFile, "%d", &tmp);
                playerGrade[j] = (double)tmp;
                printf("grade[%d]:%f\n", j, playerGrade[j]);
                sum  += playerGrade[j];
          }
          
          
          printf("small:%d\n", small);
          fprintf(pOutFile, "Case #%d:", i + 1);
          
           nNeg = 0;         
          for(j = 0; j < nPlayer; j ++)
          {
                factory[j] = (2*sum/nPlayer - playerGrade[j]) / sum;
                if(factory[j] < 0.0)
                {
                 nNeg ++;
                 negSum += playerGrade[j];
                 }
          }
          printf("nNeg:%d\n", nNeg);
          
          if(nNeg == 0)
          {
          for(j = 0; j < nPlayer; j ++)
          {
                fprintf(pOutFile, " %f", factory[j] * 100);
          }
          }
          else
          {
              for(j = 0; j < nPlayer; j ++)
              {
              if(factory[j] < 0.0)
              {
                fprintf(pOutFile, " 0.000000");
                printf("neg:%f ", factory[j]);
              }
              else
              {
                 factory[j] = ((2*sum-negSum)/(nPlayer-nNeg) - playerGrade[j]) / sum;
                 fprintf(pOutFile, " %f", factory[j] * 100);
                 printf("pos:%f ", factory[j]);
              }
              }
          }
          
        
         fprintf(pOutFile, "\n");
          
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



