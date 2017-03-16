#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


int main () {
	FILE* In;
	FILE* Out;

	fopen_s(&In, "B-small-attempt2.in", "r");
	fopen_s(&Out, "B-large.out", "w");

	int nTestCases, iTestCase;
	fscanf_s(In, "%d", &nTestCases);
	for (iTestCase=0; iTestCase < nTestCases; iTestCase++) {
		int n,i;
		int a[1001],b[1001],f[1001],fa[1001];
		fscanf_s(In, "%d", &n);
		int max = 2*n;
		for (i=0;i<n;i++) {
			fscanf_s(In, "%d %d", a+i, b+i);
			f[i] = 0;
			fa[i] = 0;
		}
		for (int j=0;j<n;j++) {
			int maxA = -1;
			int maxI;
			for (i=j;i<n;i++) {
				if (b[i] > maxA) {
					maxA = b[i];
					maxI = i;
				}
			}
			b[maxI] = b[j];
			b[j] = maxA;
			maxA = a[maxI];
			a[maxI] = a[j];
			a[j] = maxA;
		}

		int tooBad = 0, finished = 0, allA = 0, sumT = 0, sumA = 0;

		while (!tooBad && !finished) {
			int changed = 1;
			int minB = 10000;
			while (changed) {
				changed = 0;
				for (i=0;i<n;i++) {
					if (b[i] <= (sumT + sumA) && f[i] == 0) {
						sumT += 2;
						f[i] = 1;
						changed = 1;
						if (fa[i] == 1) {
							sumA--;
						}
					}
					else {
						if (f[i] == 0 && b[i] < minB)
							minB = b[i];
					}
				}
			}
			if (sumT < max) {
				changed = 1;
				while (changed) {
					changed = 0;
					for (i=0;i<n;i++) {
						if (a[i] <= (sumT + sumA) && f[i] == 0 && fa[i] == 0) {
							sumA++;
							allA++;
							fa[i] = 1;
							changed = 1;
							break;
						}
					}
					if ((sumT + sumA) >= minB) {
						changed = 0;
					}
				}
				if ((sumT + sumA) < minB) {
					//too bad
					tooBad = 1;
				}

			}
			else {
				//finished
				finished = 1;
			}
		}
		//Write Out Results
		if (!tooBad)
			fprintf_s(Out, "Case #%d: %d\n", iTestCase+1, allA + n);
		else 
			fprintf_s(Out, "Case #%d: Too Bad\n", iTestCase+1);

	}

	if (In) fclose(In);
	if (Out) fclose(Out);

	return 0;
}
