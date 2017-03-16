
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;


int main()
{
	gets(buf);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
		int  N, S, p;
		scanf("%d %d %d", &N, &S, &p);

		int  NumP = 0;
		int  NumP1 = 0;

		for(int j=1; j<=N; j++)
		{
			int  t;
			scanf("%d", &t);

			int best_result_candi = t/3 + (t%3 != 0 ? 1: 0);
			if ( best_result_candi >= p )
				NumP ++;
			if ( best_result_candi == p-1 && t>1 && t%3 != 1 )
				NumP1 ++;
		}

		printf("Case #%d: ", i);

		printf("%d", NumP + min(NumP1, S));
		printf("\n");
	}
  
	return  0;  
}
