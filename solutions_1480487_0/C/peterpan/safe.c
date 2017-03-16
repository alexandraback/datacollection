#include <stdio.h>
#include <stdlib.h>

#define require(X,Y) { if(!(X)) { fprintf(stderr,"%s\n",Y); exit(-1); } }
#define max(X,Y) ((X)>(Y)?(X):(Y))
#define min(X,Y) ((X)<(Y)?(X):(Y))

int intCompare(const void * a, const void * b)
{
	int aa,bb;

	aa = *((int *) a);
	bb = *((int *) b);
	if(aa<bb)
		return -1;
	else if(aa==bb)
		return 0;
	else
		return 1;
}

int main()
{
	int i,j,tcase,T,N,s[200],ss[200];
	double X,Y,l,step;

	scanf("%d",&T);
	for(tcase=1;tcase<=T;tcase++)
	{
		scanf("%d",&N);
		X=0;
		for(i=0;i<N;i++)
		{
			scanf("%d",s+i);
			ss[i]=s[i];
			X+=s[i];
		}
		qsort(s,N,sizeof(int),intCompare);
		Y=1;
		for(j=0;j<N-1;j++)
		{
			step=s[j+1]-s[j];
			if(step*(j+1) < Y*X)
				Y -= step*(j+1)/X;
			else
			{
				l = s[j] + X*Y/(j+1);
				break;
			}
		}
		if(j==N-1)
			l = s[j] + X*Y/(j+1);

		printf("Case #%d:",tcase);
		for(i=0;i<N;i++)
			printf(" %.6f",ss[i]>l?0:(100.0*(l-ss[i])/X));
		printf("\n");

	}


	return 0;
}
