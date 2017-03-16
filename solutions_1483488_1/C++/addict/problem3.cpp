#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main () {
	FILE* In;
	FILE* Out;

	fopen_s(&In, "C-large.in", "r");
	fopen_s(&Out, "C-large.out", "w");

	int nTestCases, iTestCase;
	int first[20], second[20], res[20];
	fscanf_s(In, "%d", &nTestCases);
	for (iTestCase=0; iTestCase < nTestCases; iTestCase++) {
		int a,b,ans = 0,i,m,n,k;
		fscanf_s(In, "%d %d", &a, &b);
		for (i=a;i<=b;i++) {
			int step=10, j=1;
			while (step<=i) {
				first[j] = i / step;
				second[j] = i % step;
				step *= 10;
				j++;
			}
			step /= 10;
			for (n=1;n<j;n++) {
				res[n] = second[n] * step + first[n];
				if (res[n] != i && res[n] >= a && res[n] <= b) {
					int have = 0;
					for (k=1;k<n;k++) {
						if (res[n] == res[k]) {
							have = 1;
							break;
						}
					}
					if (!have)
						ans++;
				}
				step /= 10;
			}
		}

		//Write Out Results
		fprintf_s(Out, "Case #%d: %d\n", iTestCase+1, ans/2);

	}

	if (In) fclose(In);
	if (Out) fclose(Out);

	return 0;
}
