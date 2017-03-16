#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<queue>
using namespace std;

#define N 105
int test, caseNum;
int n, m, k;
int a33[10] = {-1, 1,2,3,4,4,5,6,7,8};
int a34[13] = {-1, 1,2,3,4,4,5,6,6,7,8,9,10};
int a35[16] = {-1, 1,2,3,4,4,5,6,6,7,8, 8,9,10,11,12};
int a[19] = {-1, 1,2,3,4,4,5,6,6,7,8, 8,9,10,10,11,12,13,14};
int c[17] = {-1, 1,2,3,4,4,5,6,6,7,7, 8,8,9,10,11,12};
int b[21] = {-1, 1,2,3,4,4,5,6,6,7,7, 8,8,9,9,10,10,11,12,13,14};
int main()
{
	FILE *in = fopen("C-small-attempt1.in", "r");
	//FILE *in = fopen("input.txt", "r");
	FILE *out = fopen("output.txt", "w");

	caseNum = 1;
	fscanf(in, "%d", &test);
	while(caseNum <= test)
	{
		fscanf(in, "%d %d %d", &n, &m, &k);
		int t;
		if (n > m) {
			t = n;
			n = m;
			m = t;
		}

		if (n <= 2)
			fprintf(out, "Case #%d: %d\n", caseNum++, k);
		else if (n == 3) {
			if (m == 3) fprintf(out, "Case #%d: %d\n", caseNum++, a33[k]);
			else if (m == 4) fprintf(out, "Case #%d: %d\n", caseNum++, a34[k]);
			else if (m == 5) fprintf(out, "Case #%d: %d\n", caseNum++, a35[k]);
			else fprintf(out, "Case #%d: %d\n", caseNum++, a[k]);
		}
		else {
			if (m == 4) fprintf(out, "Case #%d: %d\n", caseNum++, c[k]);
			else fprintf(out, "Case #%d: %d\n", caseNum++, b[k]);
		}
	}

	fcloseall();
	return 0;
}
