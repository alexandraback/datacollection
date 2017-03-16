#include<stdio.h>
#include<stdlib.h>
#include<string.h>

double p[100005];

int main()
{
	int T;
	int i;
	double N, All;
	scanf("%d", &T);
	for ( int t = 1 ; t <= T ; t++ ) {
		scanf("%lf%lf", &N, &All);
		for ( i = 0 ; i < N ; i++ ) {
			scanf("%lf", &p[i]);
		}
		// case 1
		double P = 1.0;
		for ( i = 0 ; i < N ; i++ ) {
			P *= p[i];
		}
		double min = P*(All-N+1) + (1-P)*(All-N+1+All+1);
		P = 1.0;
		// case 2
		for ( i = 0 ; i < N ; i++ ) {
			int B = N-i;
			double cost = P*(B+B+All-N+1) + (1-P)*(B+B+All-N+1+All+1);
			if ( cost < min )
				min = cost;
			P *= p[i];
		}
		/*
		Sum /= N;
		if ( Sum < min )
			min = Sum;*/
		if ( All+1+1 < min )
			min = All+1+1;
			
		printf("Case #%d: %lf\n", t, min);	
	}
	return 0;
}
