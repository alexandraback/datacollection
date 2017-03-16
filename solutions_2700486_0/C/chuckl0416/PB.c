#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int TestCases, TCCount;
long long int N, X, Y, x, y;
long long int Level;
double Ans[1200][1200];

double Solve(long long int x, long long int y){
	long long int X=x, Y=y;
	if (X<0) X=-X;
	if (Y<0) Y=-Y;
	Level = (X+Y)/2;
	
	N -= (Level*(2*Level-1));
	if (N<=Y) return 0;
	if (N>=(4*Level+1)) return 1;
	
	if (N>=(2*Level)){
		long long int T = N-2*Level;
		N -= (2*T);
		Y -= T;
	}
	return Ans[N+1][Y+1];
}

int main(){
	freopen("B-small-attempt2.in", "r", stdin);
	freopen("B-small-attempt2.out", "w", stdout);
	
	memset(Ans, 0, sizeof(Ans));
	for (y=0; y<=1000; y++){
		Ans[y][0] = 1;
	}
	
	for (y=2; y<=1000; y++) for (x=1; x<y; x++){
		Ans[y][x] = (Ans[y-1][x-1]+Ans[y-1][x])/2;
	}
	
	scanf("%d", &TestCases);
	for (TCCount=1; TCCount<=TestCases; TCCount++){
		scanf("%lld%lld%lld", &N, &X, &Y);
		printf("Case #%d: %lf\n", TCCount, Solve(X, Y));
		
	}
	
	
	return 0;
}

