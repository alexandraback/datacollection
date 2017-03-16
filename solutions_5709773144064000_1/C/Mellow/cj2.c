#include<stdio.h>
int main()
{
	FILE* fp = 0;
	if(0 == ( fp = freopen("cj2.in", "w" ,stdout)))
   		 printf("Cannot open file.\n");
	int T = 0;
	scanf("%d",&T);
	for(int cT = 0; cT < T; cT ++)
	{
		double C = 0.0;
		double F = 0.0;
		double X = 0.0;
		double timeTotal = 0.0;
		double nRate = 2.0;
		scanf("%lf %lf %lf", &C, &F, &X);
		while(X / nRate > (C / nRate + X / (nRate + F)))
		{
			timeTotal += C / nRate;
			nRate += F;
		}
		timeTotal += X / nRate;
		printf("Case #%d: %.7lf\n", cT + 1,timeTotal);
	}
	fclose(fp);
}
