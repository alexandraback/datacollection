
#include<stdlib.h>
#include<stdio.h>
using namespace std;

int main(){
	int T, sol;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t){
		double C, F, X, R(2.0), time(0.0);
		scanf("%lf %lf %lf", &C, &F, &X);
		while (C / R + X / (R + F) < X / R){
			time += C / R;
			R += F;
		}
		time += X / R;
		printf("Case #%d: %.7lf\n", t, time);
	}
	return 0;
}
