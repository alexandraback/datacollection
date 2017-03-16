#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

double calcp(int A,int B,double p)
{
	return p*(double)(B - A + 1) + (1 - p)*(double)(2*B - A + 2);
}

int main() 
{ 

#ifdef FILEIO
	freopen("in.txt","r",stdin); 
	freopen("out.txt","w",stdout); 
#endif

	int T;
	int A,B;
	int i,j;
	int caseNumber = 1;
	double t;
	double min;
	double temp[100000] = {0};

	scanf("%d",&T);

	while(T-- > 0) 
	{
		scanf("%d %d",&A,&B);
		scanf("%lf",&temp[0]);
		for(i = 1;i<A;i++)
		{
			scanf("%lf",&t);
			temp[i] = temp[i - 1]*t;
		}
		min = B + 2;
		double total = 0;
		for(i = 0;i < A;i++)
		{
			//total = calcp(A - i,B,temp[A - i]);
			total = temp[A - i - 1]*(double)(B - A + 1 + 2*i)
				+ (1 - temp[A - i - 1])*(double)(B - (A - i) + 1 + (B + 1) + i);
			if(min>total)
				min = total;
		}

		if(min>A+B+1)
		{
			min=A+B+1;
		}

		printf("Case #%d: %.6lf\n",caseNumber++,min);
	}


#ifdef FILEIO
	fclose(stdin);
	fclose(stdout);
#endif  

	return 0; 
}
