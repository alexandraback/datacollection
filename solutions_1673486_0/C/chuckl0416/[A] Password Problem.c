#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <string.h>

int main(){
	FILE *fin, *fout;
	fin = freopen("A-small-attempt0.in", "r", stdin);
	fout = freopen("A-small-attempt0.out", "w", stdout);
	
	int Testcases, TCCount;
	scanf("%d", &Testcases);
	int a, b, i;
	double A, B;
	double Probability[100000];
	double Min, Temp;
	double RightProb[100000];
	
	for (TCCount=1; TCCount<=Testcases; TCCount++){
		printf("Case #%d: ", TCCount);
		scanf("%lf%lf", &A, &B);
		a=A, b=B;
		for (i=0; i<a; i++) scanf("%lf", &Probability[i]);
		RightProb[0] = Probability[0];
		for (i=1; i<a; i++) RightProb[i] = RightProb[i-1]*Probability[i];
		Min = B+2;
		
		for (i=A; i>=0; i--){
			Temp = (B-A+2*i+1) + (1-RightProb[a-i-1])*(B+1);
			
			if (Temp<Min) Min=Temp;
		}
		
		printf("%lf", Min);
		
		
		
		
		putchar(10);
	}
	
	fclose(fin);
	fclose(fout);
	//system("Pause");
	return 0;
}
