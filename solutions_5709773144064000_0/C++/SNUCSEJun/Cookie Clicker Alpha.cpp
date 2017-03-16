#include<stdio.h>


double C, F, X;
double CPS;		//cookies per second




void getData(){
	CPS = 2.0;
	scanf_s("%lf", &C);
	scanf_s("%lf", &F);
	scanf_s("%lf", &X);
}


double solveCookie(){
	double sumOfTime = 0;

	while (X >= C){
		sumOfTime += C / CPS;
		if ((X - C) / CPS > X / (CPS + F)){
			CPS += F;
		}
		else{
			X -= C;
		}
	}
	sumOfTime += X / CPS;
	
	return sumOfTime;
}



int main(){

	int T;
	int i;
	double ans;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf_s("%d", &T);

	for (i = 1; i <= T; i++){
		getData();
		ans = solveCookie();
		printf("Case #%d: %0.7lf\n", i, ans);
	}
	return 0;
}