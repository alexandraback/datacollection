#include <stdio.h>
#include <float.h>

int t;
int n;
int points[202];
int X;
double requiredScore;
double requiredAudience[202];
double extra;

int main(){
	scanf("%d", &t);
	for(int cases = 1; cases <= t; cases++){
		
		scanf("%d", &n);
		
		X = 0;
		
		for(int i = 1; i <= n; i++){
			scanf("%d", &points[i]);
			X += points[i];
		}
		
		printf("Case #%d: ", cases);
		

		requiredScore = (X * 2)/ n;
		
		extra = 0;
		int n1 = 0;
		
		for(int i = 1; i <= n; i++){
			requiredAudience[i] = ((requiredScore - points[i]) * 100 )/ X;
			if(requiredAudience[i] < 0){
				extra += requiredAudience[i];
				n1++;
			}
		}
		
		for(int i = 1; i <= n; i++){
			if(requiredAudience[i] < 0){
				requiredAudience[i] = 0;
			}
			else{
				requiredAudience[i] += extra / (n - n1);
			}
		}
		

		printf("%.6lf", requiredAudience[1]);

		
		for(int i = 2; i <= n; i++){
			printf(" %.6lf", requiredAudience[i]);
		}
		
		printf("\n");
		
		
	}
	return 0;
}

