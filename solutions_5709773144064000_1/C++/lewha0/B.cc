#include<stdio.h>

int T;
long double C, F, X;
long double V1, V2, V3;
long double Ret, Prev;

int main(void)
{
	int l0, l1;

	scanf("%d", &T);
	for(l0 = 1; l0 <= T; l0++)
	{
		scanf("%Lf %Lf %Lf", &C, &F, &X);

		Ret = X / (long double)2;
		V2 = 0;
		Prev = Ret;
		for(l1 = 1; l1 <= 1000000; l1++)
		{
			V1 = C / ((long double)2 + (long double)(l1-1)*F);
			V2 += V1;
			V3 = V2 + X / ((long double)2 + (long double)l1 * F);
			if(V3 < Ret) Ret = V3;
//			if(V3 >= Prev) break;
			Prev = V3;
		}

		printf("Case #%d: %.20Lf\n", l0, Ret);
	}
}
