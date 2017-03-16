#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int requirement[1000][2];
int noDone[1000][2];
int star;

int pickNext(int level)
{
    int i, j;
    int found = 0;
    int allDone = 1;
    int foundI = 0, foundJ = 0;
    int maxJr = 0, jr = 0;
    int earnStar = 0, maxEarnStar = 0;
    
    for(j = 1; j >= 0; j --)
    {
        for(i = 0; i < level; i ++)
        {
            //if(found == 0)
            {
                if(noDone[i][j] == 1 && star >= requirement[i][j])
                {
                    printf("star %d i %d j %d reqirement %d\n", star, i, j, requirement[i][j]);
                    /*
                    if(j == 1)
                    {
                        noDone[i][0] = 0;
                        noDone[i][1] = 0;
                    }
                    else
                        noDone[i][0] = 0;
                        
                    star += j + 1;*/
                    
                    
                    if(j == 1)
                    {
                        if(noDone[i][0] == 0)
                        {
                            earnStar =  1;
                        }
                        else
                        {
                            earnStar =  2;
                        }
  
                    }
                    else
                    {
                        earnStar =  1;
                    }
                    
                    if(earnStar >= maxEarnStar)
                    {

                            jr = requirement[i][1];

                        if(jr >= maxJr && j >= foundJ)
                        {
                            maxJr = jr;
                            foundI = i;
                            foundJ = j;
                            found = 1;
                            maxEarnStar = earnStar;
                        }
                    }
                }
            }
            if(noDone[i][j] == 1)
                allDone = 0;
        }
    }
    
                if(found == 1)
                {
                    
                    if(foundJ == 1)
                    {
                        if(noDone[foundI][0] == 0)
                        {
                            star +=  1;
                        }
                        else
                        {
                            star +=  2;
                        }
  
                        noDone[foundI][0] = 0;
                        noDone[foundI][1] = 0;
                    }
                    else
                    {
                        noDone[foundI][0] = 0;
                        star +=  1;
                    }
                    printf("star %d found [%d][%d]: %d\n", star, foundI, foundJ, requirement[foundI][foundJ]);
                }
    
    if(allDone == 1)
        return 2;
    else if(found == 0)
        return 1;
    else 
        return 0;
    
}

int myCount(int level)
{
    int step = 0;
    int result = 0;
    
    star = 0;
    
    while(1)
    {
        if(pickNext(level) == 0)
        {
            step ++;
        }
        else if(pickNext(level) == 1)
        {
            return -1;
        }
        else
        {
            return step;
        }
    }
    
    
    
}

int main(int argc, char *argv[])
{

    char *inFileName = "B-small-attempt2.in";
    char *outFileName = "B-small-attempt2.out";
    //char *inFileName = "B-small-attempt1.in";
    //char *outFileName = "B-small-attempt1.out";
    int group, level, i, j, result;
    FILE * pInFile, *pOutFile;
    

    if((pInFile = fopen(inFileName, "r")) == NULL)
          printf("error open file\n");

    if((pOutFile = fopen(outFileName, "w")) == NULL)
          printf("error open file\n");

    //genDataBase();
    //displayDataBase(pOutFile);

    fscanf(pInFile, "%d", &group);
    printf("group %d\n", group);
    for(i =0; i< group; i++)
    {
          memset(requirement, 0, sizeof(requirement));
          memset(noDone, 0, sizeof(noDone));
          
          fscanf(pInFile, "%d", &level);
          printf("level %d\n", level);
          for(j = 0; j < level; j ++)
          {
                fscanf(pInFile, "%d %d", &requirement[j][0], &requirement[j][1]);
                noDone[j][0] = noDone[j][1] = 1;
                printf("requirement[%d][0]:%d, requirement[%d][1]:%d\n", j, requirement[j][0], j, requirement[j][1]);
          }
          
          result = myCount(level);
          
          if(result == -1)
            fprintf(pOutFile, "Case #%d: %s\n", i+1, "Too Bad");
          else
            fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



