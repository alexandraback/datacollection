#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <math.h>
using namespace std;

int i, j, k, kejsis, kejs, n;
double A[100000], ret, sum, p;
int a, b;

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d%d", &a, &b);
		for (i = 0; i < a; i++) scanf("%lf", &A[i]);

		// if I keep typing
		p = 1;
		for (i = 0; i < a; i++) p *= A[i]; // all must be good
		ret = p * (b-a+1);
		ret += (1-p) * (b-a+1 + b+1);

		for (j = 1; j < a; j++) {
			// if I press backspace j times
			for (i = 0, p = 1; i < a - j; i++) p *= A[i]; // all must be good
			sum = p * (j + b-a+j+1);
			sum += (1-p) * (1 + b-a+1+1 + b+1);
//			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
		}
		sum = j + b+1;
//		fprintf(stderr, "---%lf\n", sum);
		if (ret > sum) ret = sum;
		// if I press enter
		sum = 1 + b+1;
//		fprintf(stderr, "---%lf\n", sum);
		if (ret > sum) ret = sum;

		printf("%.10lf\n", ret);
	}
	return 0;
}
