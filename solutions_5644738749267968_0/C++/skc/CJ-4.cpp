#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#if 1

//#define IN_FILE	"IO/CJ-4.in"

#define P 		printf

double N[1001], K[1001], K2[1001];

int mycmp(const void* p1, const void* p2)
{
	double d = *(double*)p1 - *(double*)p2;
	if(d > 0)
		return 1;
	if(d < 0)
		return -1;
	return 0;
}

int main(void)
{
	int t,tst;

	FILE* fin = stdin;
#ifdef IN_FILE
	fin = fopen(IN_FILE,"r");
	if(fin == NULL)
	{
		printf("Cannot Open file %s\n", IN_FILE);
		return 0;
	}
#endif

	fscanf(fin, "%d", &tst);
	for(t=1 ; t<=tst ; ++t)
	{
		int i,j,c,g,b;

		fscanf(fin, "%d", &c);

		for(i=0 ; i<c ; ++i)
			fscanf(fin,"%lf", &N[i]);
		for(i=0 ; i<c ; ++i)
			fscanf(fin,"%lf", &K[i]);

		qsort(N,c,sizeof(N[0]),mycmp);
		qsort(K,c,sizeof(K[0]),mycmp);

		memcpy(K2,K,sizeof(K[0])*c);

		for(i=0,j=0 ; i<c ; ++i)
		{
			double n = N[i];
			for( ; j<c ; ++j)
				if(K[j]>n)
					break;
			if(j>=c)
				break;
			K[j] = 0;
		}
		g = c-i;


		for(i=0,j=0,b=0 ; i<c ; ++i)
		{
			if(N[i] < K2[j])
				b++;
			else
				j++;
		}

		P("Case #%d: %d %d\n",t,c-b,g);
	}

#ifdef IN_FILE
	fclose(fin);
#endif

	return 0;
}

#endif
