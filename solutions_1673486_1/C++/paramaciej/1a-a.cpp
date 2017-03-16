#include <cstdio>
double p[100005];
int a, b;
int main()
{
	int T;
	scanf("%d", &T);
	for(int t = 1; t <= T; t++)
	{
		scanf("%d %d", &a, &b);
		long double perfekt = 1;
		for(int i = 0; i < a; i++)
		{
			scanf("%lf", &p[i]);
			perfekt *= p[i];
		}
		long double OCZEK[3];
		OCZEK[0] = perfekt*(b-a+1) + (1-perfekt)*(b-a+b+2);
		OCZEK[1] = 1000000000;
		OCZEK[2] = 2+b;
		perfekt = 1;
		for(int i = 0; i < a; i++)
		{
			perfekt *= p[i];
			long double biez = perfekt*(a+b-2*i-1) + (1-perfekt)*(a+b-2*i+b);
			OCZEK[1] = OCZEK[1]<biez? OCZEK[1] : biez;
		}
		OCZEK[0] = OCZEK[0]<OCZEK[1]? OCZEK[0] : OCZEK[1];
		OCZEK[0] = OCZEK[0]<OCZEK[2]? OCZEK[0] : OCZEK[2];
		printf("Case #%d: %llf\n", t, OCZEK[0]);

	}
}
