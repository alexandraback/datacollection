#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#define MAX 100000
#define EPS 1e-7

int main () {
	FILE* In;
	FILE* Out;

	fopen_s(&In, "A-large.in", "r");
	fopen_s(&Out, "A-large.out", "w");

	int nTestCases, iTestCase;
	fscanf_s(In, "%d", &nTestCases);
	for (iTestCase=0; iTestCase < nTestCases; iTestCase++) {
		double p, pt = 1.,bestP, bestPT;
		int a,b,i;
		fscanf_s(In, "%d %d", &a,&b);
		bestP = b+2;
		for (i=0;i<a;i++) {
			fscanf_s(In, "%lf", &p);
			if (p < EPS) {
				break;
			}
			int j = a-2*(i+1);
			pt = pt*p;
			bestPT = pt * (b+j+1) + (1-pt)*(2*b+j+2);
			if (bestPT < bestP)
				bestP = bestPT;
		}
		//Write Out Results
		fprintf_s(Out, "Case #%d: %lf\n", iTestCase+1, bestP);
	}

	if (In) fclose(In);
	if (Out) fclose(Out);

	return 0;
}
