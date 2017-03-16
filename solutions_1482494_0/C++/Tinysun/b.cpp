
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;

//int  a[1000], b[1000];
typedef struct 
{
	int  a;
	int  b;
} rate_t;
rate_t rate[1000];

int foo(int N);

int compare (const void * a, const void * b)
{
  return ( ((rate_t*)b)->b - ((rate_t*)a)->b );
}



int main()
{
	gets(buf);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
		int N;
		scanf("%d", &N);
		for(int k=0; k<N; k++)
			scanf("%d %d", &rate[k].a, &rate[k].b);

//		for(int k=0; k<N; k++)
//			printf("%d %d\n", a[k], b[k]);

		qsort (rate, N, sizeof(rate_t), compare);

		int ans=4;
		ans = foo(N);


		printf("Case #%d: ", i);
		if ( ans < 0 )
			printf("Too Bad");
		else
			printf("%d", ans);
		printf("\n");
	}
  
	return  0;  
}


int foo(int N)
{
		int score = 0;

		int r[1000];

		// init complete
		for (int k=0; k<N; k++)
			r[k] = 0;
		int playtime = 0;
		int  lastscore;

		while(true)
		{
			// complete possible 2-star rating
			do {
				lastscore = score;
				for (int k=0; k<N; k++)
				{
					if ( r[k]<2 && rate[k].b<=score )
					{
						score += 2-r[k];
						r[k] = 2;
						playtime ++;
					}
				}

				if ( score == 2*N )
					return  playtime;
		
			} while ( score > lastscore );

			lastscore = score;
			for (int k=0; k<N; k++)
			{
				if ( r[k]==0 && rate[k].a<=score )
				{
					score ++;
					r[k] = 1;
					playtime ++;
					break;
				}
			}
			if ( lastscore == score )
				return -1;

		}

}
