#include <cstdio>
#include <algorithm>
#include <string>
using namespace std;

int mult(int a, int b) {
	if (a < 0)
		return -mult(-a, b);
	if (b < 0)
		return -mult(a, -b);

	if (a == 1)
		return b;
	if (b == 1)
		return a;
	if (a == b)
		return -1;
	
	if (a == 2) {
		if (b == 3)
			return 4;
		if (b == 4)
			return -3;
	}
	if (a == 3) {
		if (b == 2)
			return -4;
		if (b == 4)
			return 2;
	}
	if (a == 4) {
		if (b == 2)
			return 3;
		if (b == 3)
			return -2;
	}
	for (;;) {}
}


int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; ++testcase) {
		int L;
		long long X;
		char inp[10011];
		int inp_int[10001];
		scanf("%d %lld", &L, &X);
		scanf("%s", inp);
		for (int i = 0; i < L; ++i) {
			if (inp[i] == 'i')
				inp_int[i] = 2;
			else if (inp[i] == 'j')
				inp_int[i] = 3;
			else if (inp[i] == 'k')
				inp_int[i] = 4;
		}

		int count = 1;
		int total_count = 1;
		for (int i = 0; i < L; ++i)
			count = mult(count, inp_int[i]);
		for (int i = 0; i < X % 8; ++i)
			total_count = mult(total_count, count);

		int left_i = -1;
		int right_k = -1;
		count = 1;
		for (int i = 0; i < L * min(X, 8LL); ++i) {
			count = mult(count, inp_int[i % L]);
			if (count == 2) {
				left_i = i;
				break;
			}
		}
		count = 1;
		for (int i = 0; i < L * min(X, 8LL); ++i) {
			count = mult(inp_int[L - (i % L) - 1], count);
			if (count == 4) {
				right_k = i;
				break;
			}
		}

		if (total_count == -1 && left_i != -1 && right_k != -1 && left_i + 1 + right_k + 1 < (long long)L * X)
			printf("Case #%d: YES\n", testcase);
		else 
			printf("Case #%d: NO\n", testcase);
	}
	return 0;
}

