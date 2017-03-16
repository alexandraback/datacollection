#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main () {
	FILE* In;
	FILE* Out;

	fopen_s(&In, "B-large.in", "r");
	fopen_s(&Out, "B-large.out", "w");

	int nTestCases, iTestCase;
	fscanf_s(In, "%d", &nTestCases);
	for (iTestCase=0; iTestCase < nTestCases; iTestCase++) {
		int s1=0,s2=0,s3=0,i,sum,n,s,min;
		fscanf_s(In, "%d %d %d", &n, &s, &min);
		for (i=0;i<n;i++) {
			fscanf_s(In, "%d", &sum);
			if ( sum >= (3*min-4) )
				s1++;
			if ( sum >= (3*min-2) )
				s2++;
		}
		//Write Out Results
		fprintf_s(Out, "Case #%d: ", iTestCase+1);
		if (min == 1) {
			fprintf_s(Out, "%d\n", s2);
		} else {
			if ( s1 <= s2 + s )
				fprintf_s(Out, "%d", s1);
			else 
				fprintf_s(Out, "%d", s2 + s);
			fprintf_s(Out, "\n");
		}
	}

	if (In) fclose(In);
	if (Out) fclose(Out);

	return 0;
}
