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

    char *inFileName =  "A-large.in";
    char *outFileName = "A-large.out";
    int i, j, k;
    int group;
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
    
    //printf("%d %I64u %d %I64u %I64u\n", wP1, rP1, wP2, rP2, gened);
		fscanf(pInFile, "%s\n", &iStr);
		printf("i:%s\n", iStr);

		findAns();
		
		printf("o:%s\n", oStr);
		
        fprintf(pOutFile, "Case #%d: %s\n", i+1, oStr);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



