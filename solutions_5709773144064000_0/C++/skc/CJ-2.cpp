#include "stdio.h"

#if 1

//#define IN_FILE	"IO/CJ-2.in"

#define P 		printf

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
		double c,f,x;

		double cnt=0, s=2;

		fscanf(fin,"%lf %lf %lf", &c, &f, &x);

		double t2 = x/s;

		while(1)
		{
			double t1 = c/s;

			if(t2<=t1)
			{
				cnt += t2;
				break;
			}
			cnt += t1;

			t1 = (x-c)/s;
			t2 = x/(s+f);

			if(t1 <= t2)
			{
				cnt += t1;
				break;
			}

			s += f;
		}

		P("Case #%d: %lf\n",t,cnt);
	}

#ifdef IN_FILE
	fclose(fin);
#endif

	return 0;
}

#endif
