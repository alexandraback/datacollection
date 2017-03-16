#include <stdio.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
using namespace std;

int i, j, k, kejsis, kejs, n;
double A[3], ret, sum, p;
int a, b;
int ga, gb, gc;

int main() {
	scanf("%d", &kejsis);
	for (int kejs = 1; kejs <= kejsis; ++kejs) {
		printf("Case #%d: ", kejs);
		scanf("%d%d", &a, &b);
		for (i = 0; i < a; i++) scanf("%lf", &A[i]);

		if (a == 1) {
			// if I keep typing
			ret = A[0] * (b-a+1) + (1 - A[0]) * (b-a+1 + b+1);
			// if I press backspace once
			sum = (1+b+1);
 			if (ret > sum) ret = sum;
		}
		if (a == 2) {
			// if I keep typing
			ret = 0;
			for (ga = 0; ga <= 1; ga++) {
				for (gb = 0; gb <= 1; gb++) {
					if (ga) p = A[0]; else p = 1 - A[0];
					if (gb) p *= A[1]; else p *= 1 - A[1];
					if (ga && gb) {
						ret += p * (b-a+1);
					} else {
						ret += p * (b-a+1 + b+1);
					}
				}
			}
			// if I press backspace once
			sum = 0;
			for (ga = 0; ga <= 1; ga++) {
				for (gb = 0; gb <= 1; gb++) {
					if (ga) p = A[0]; else p = 1 - A[0];
					if (gb) p *= A[1]; else p *= 1 - A[1];
					if (ga) {
						sum += p * (1 + b-a+1+1);
					} else {
						sum += p * (1 + b-a+1+1 + b+1);
					}
				}
			}
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
			// if I press backspace twice
			sum = 2 + b+1;
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
			// if I press enter
			sum = 1 + b+1;
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
		}
		if (a == 3) {
			// if I keep typing
			ret = 0;
			for (ga = 0; ga <= 1; ga++) {
			for (gb = 0; gb <= 1; gb++) {
			for (gc = 0; gc <= 1; gc++) {
				if (ga) p = A[0]; else p = 1 - A[0];
				if (gb) p *= A[1]; else p *= 1 - A[1];
				if (gc) p *= A[2]; else p *= 1 - A[2];
				if (ga && gb && gc) {
					ret += p * (b-a+1);
				} else {
					ret += p * (b-a+1 + b+1);
				}
			}}}
			// if I press backspace once
			sum = 0;
			for (ga = 0; ga <= 1; ga++) {
			for (gb = 0; gb <= 1; gb++) {
			for (gc = 0; gc <= 1; gc++) {
				if (ga) p = A[0]; else p = 1 - A[0];
				if (gb) p *= A[1]; else p *= 1 - A[1];
				if (gc) p *= A[2]; else p *= 1 - A[2];
				if (ga && gb) {
					sum += p * (1 + b-a+1+1);
				} else {
					sum += p * (1 + b-a+1+1 + b+1);
				}
			}}}
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
			// if I press backspace twice
			sum = 0;
			for (ga = 0; ga <= 1; ga++) {
			for (gb = 0; gb <= 1; gb++) {
			for (gc = 0; gc <= 1; gc++) {
				if (ga) p = A[0]; else p = 1 - A[0];
				if (gb) p *= A[1]; else p *= 1 - A[1];
				if (gc) p *= A[2]; else p *= 1 - A[2];
				if (ga) {
					sum += p * (2 + b-a+2+1);
				} else {
					sum += p * (2 + b-a+2+1 + b+1);
				}
			}}}
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
			// if I press backspace three times
			sum = 3 + b+1;
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
			// if I press enter
			sum = 1 + b+1;
			fprintf(stderr, "---%lf\n", sum);
			if (ret > sum) ret = sum;
		}

		printf("%.10lf\n", ret);
	}
	return 0;
}
