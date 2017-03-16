
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;

// int _tmain(int argc, _TCHAR* argv[])


int main()
{
	gets(buf);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
		int N;
		int s[200];
		int s_flag[200];
		double m[200];

		scanf("%d", &N);
		for(int k=0; k<N; k++)
			scanf("%d", &s[k]);

		int X = 0;
		for(int k=0; k<N; k++)
		{
			X += s[k];
			s_flag[k] = 0;
		}

		int  X1 = 2*X;
		int  N1 = N;

		int Pass = 0;
		do
		{
			double thr = (double)X1/N1;
			Pass = 0;
			for(int k=0; k<N; k++)
			{
				if ( s_flag[k] == 0 && (double)s[k] > thr )
				{
					s_flag[k] = 1;
					X1 -= s[k];
					Pass++;
				}
			}
			N1 -= Pass;
		} while (Pass != 0);	


		for(int k=0; k<N; k++)
		{
			if ( s_flag[k] == 1)
				m[k] = 0.0;
			else
			{
				m[k] = (double)100.0 * (double(X1)/N1 - s[k])/double(X);

			}
		}

		printf("Case #%d:", i);
		for(int k=0; k<N; k++)
			printf(" %.6f", m[k]);
		printf("\n");
	}
  
	return  0;  
}
