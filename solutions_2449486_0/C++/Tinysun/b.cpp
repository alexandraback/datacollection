
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64_t;

int lawn[101][101];
int max_r[101];
int max_c[101];
int  N, M;

bool CheckPossible()
{
    for(int r=0; r<N; r++)
        for(int c=0; c<M; c++)
            if (lawn[r][c] != max_r[r] && lawn[r][c] != max_c[c])
                return false;
    return  true;
}

int main()
{
    fgets(buf, 1024, stdin);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
        // input data
        scanf("%d %d", &N, &M);
 
		for(int r=0; r<N; r++)
            for(int c=0; c<M; c++)
                scanf("%d", &lawn[r][c]);
        
        // verify input
#if 0
		for(int r=0; r<N; r++)
        {
            for(int c=0; c<M; c++)
                printf("%d", lawn[r][c]);
            printf("\n");
        }
#endif
        
        // go
        const char *res = "";

        // save max_r, max_c
        for(int r=0; r<N; r++)
        {
            max_r[r] = 0;
            for(int c=0; c<M; c++)
                max_r[r] = max(max_r[r], lawn[r][c]);
        }

        for(int c=0; c<M; c++)
        {
            max_c[c] = 0;
            for(int r=0; r<N; r++)
                max_c[c] = max(max_c[c], lawn[r][c]);
        }
       
        
        if (CheckPossible())
            res = "YES";
        else
            res = "NO";
        
		printf("Case #%d: %s", i, res);

		printf("\n");
	}
  
	return  0;  
}
