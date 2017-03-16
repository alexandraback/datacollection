#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;



/* Global Variables*/    
    unsigned __int64 par[9];
	unsigned __int64 curr[9];
    int result = 0;
    int F[1010], sel[1010], N;
	FILE * pInFile, *pOutFile;
/*---------*/  




int findAns()
{
    int i = 0, j, k, tmp = 0, end, self=0;


	for(i = 1; i <= N; i ++)
	{
		memset(sel, 0, sizeof(sel));
		j = i;
		tmp = 0;
		self = 0;
		while(1)
		{
			printf("%d", j);
			sel[j]=1;
			end = j;
			tmp ++;
			printf("(%d)->", tmp);
			if(sel[F[j]] == 1)
			{
				if(F[j]== i)
				{
					printf("A");
					break;
				}
				else if(F[F[j]] == j)
				{
					printf("B");
					self = 1;
					break;
				}
				else
				{
					printf("C");
					tmp = -1;
					break;
				}
			}
			j = F[j];
		}
		
		int found;
		if(self == 1)
		{
			while(1)
			{
				found =0;
				for(j = 1; j < N; j ++)
				{
					if(F[j]== end && !sel[j])
					{
						tmp ++;
						printf("add %d", j);
						end = j;
						found = 1;
						break;
					}
				}
				if(found == 0)
					break;
			}
		}
		printf("\n");
		
		if(tmp >= result)
			result = tmp;
	}
	
    
    return result;
}


int main(int argc, char *argv[])
{

    char *inFileName =  "C-small-attempt2.in";
    char *outFileName = "C-small-attempt2.out";
    int i, j, k;
    int group;
    int ans1, ans2;
/* Local Variables*/    
    //int A, N;
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
    	fscanf(pInFile, "%d", &N);
    	memset(F, 0, sizeof(F));
    
    	for(j = 0; j < N; j ++)
    	{
    		fscanf(pInFile, "%d\n", &F[j+1]);
			printf(" %d", F[j+1]);
		}
    	printf("\n");
    	
		result = 0;
		findAns();
		
		
        fprintf(pOutFile, "Case #%d: %d\n", i+1, result);
    }
        
    fclose(pInFile);
    fclose(pOutFile);
    
    system("PAUSE");
    return EXIT_SUCCESS;
}



