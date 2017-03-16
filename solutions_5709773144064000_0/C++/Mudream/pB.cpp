#include<stdio.h>
#include<stdlib.h>
int main()
{
	int T; scanf("%d\n",&T);
	for(int lT = 1;lT <= T;lT++)
	{
		double C,F,X;
		int lx;
		scanf("%lf %lf %lf",&C,&F,&X);
		double sum = 0; double an;
		double tmpan = X/(double)2;
		for(int lx = 0;lx <= 500000;lx++)
		{
			double n = (double)lx;
			sum += C/((double)2 + F*n);
			an = sum + X/((double)2 + F*(n+1));
			if(X/((double)2+F*(n+1)) + C/((double)2+F*(n)) > X/((double)2+F*(n))) break;
			tmpan = an;
		}
		printf("Case #%d: %.7f\n",lT,tmpan);
	}
	return 0;
}
