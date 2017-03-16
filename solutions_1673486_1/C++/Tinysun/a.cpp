
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define  max(x, y)  ((x)>(y)?(x):(y))
#define  min(x, y)  ((x)<(y)?(x):(y))
#define  abs(x)   ((x)<0?-(x):(x))

char buf[1024];

typedef  long long  int64;

// int _tmain(int argc, _TCHAR* argv[])

float p[100001];

int main()
{
	gets(buf);
	int ncase = atoi(buf);
//	printf("%d\n", ncase);
  
	for(int i=1; i<=ncase; i++)
	{
		int A, B;
		scanf("%d %d", &A, &B);
		for(int k=0; k<A; k++)
			scanf("%f", &p[k]);

		double expect = B+2.0;

		double B1 = B+1;
		for(int k=A; k>=0; k--)
		{
			double t = 2*B - A + 2 + 2*k - B1;
			expect = min(expect, t);
			if ( k > 0 )
				B1 = B1*p[A-k];
		}
		double ans = expect;

		printf("Case #%d: ", i);
		printf("%f ", ans);
		printf("\n");
	}
  
	return  0;  
}
