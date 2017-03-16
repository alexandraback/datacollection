#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    unsigned __int64 par[9];
	unsigned __int64 curr[9];
    int len, num;
    char iStr[2000], oStr[2000], tmpStr[2000];
    int height[2600];
	FILE * pInFile, *pOutFile;
/*---------*/  




int findAns()
{
    int i = 0, j, k, isPrim = 0, result = 0, val;
    int size = strlen(iStr);
    char tmp;
    printf("size %d\n", size);
    
    memset(oStr, 0, sizeof(oStr));
    
	oStr[0]=iStr[0];
	
	for(i = 1; i < size; i ++)
	{
		tmp = iStr[i];
		memset(tmpStr, 0, sizeof(tmpStr));
		if(iStr[i] >= oStr[0])
		{
			tmpStr[0] = tmp;
			strcat(tmpStr, oStr);
			strcpy(oStr, tmpStr);
		}
		else
		{
			tmpStr[0] = tmp;
			strcat(oStr, tmpStr);
		}
	}
	
    
    return result;
}


int main(int argc, char *argv[])
{

    char *inFileName =  "B-small-attempt0.in";
    char *outFileName = "B-small-attempt0.out";
    int i, j, k;
    int group, N, num;
    int ans1, ans2;
/* Local Variables*/    
    //int A, N;
    int result;
/*---------*/    

    

    if((pInFile = fopen(inFileName, "r")) == NULL)
          printf("error open file\n");

    if((pOutFile = fopen(outFileName, "w")) == NULL)
          printf("error open file\n");


    fscanf(pInFile, "%d", &group);
    printf("group %d\n", group);
    for(i =0; i< group; i++)
    {
    	unsigned __int64 gen;
    	
    	memset(height, 0, sizeof(height));
    	
    	fscanf(pInFile, "%d", &N);
    	printf("N %d\n", N);
    
    //printf("%d %I64u %d %I64u %I64u\n", wP1, rP1, wP2, rP2, gened);
    
    	for(j = 0; j<2*N-1; j++)
    	{
    		for(k = 0; k < N; k ++)
			{
				fscanf(pInFile, "%d", &num);
				height[num]++;
				//printf(" %d", num);
			}	
		}
    
    	//printf(" \n");
		//findAns();

for(j = 0; j < 2600; j++)
        {
        	if(height[j]!=0)
        	{
        		printf("%d:%d\n", j, height[j]);
			}
			
		}
		
		
        fprintf(pOutFile, "Case #%d:", i+1);
        printf("Case #%d:", i+1);
        
        for(j = 0; j < 2600; j++)
        {
  
			
        	if(height[j]%2 == 1)
        	{
        		fprintf(pOutFile, " %d", j);
        		printf(" %d", j);
        	}
		}
		
		fprintf(pOutFile, "\n");
        printf("\n");
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



