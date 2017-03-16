#include <cstdio>
using namespace std;

int main(void) {
	int testnum;
	scanf("%d", &testnum);
	for (int testcase = 1; testcase <= testnum; testcase++) {
		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);

		int num_verify_row = (R - 1) * (C / W);
		int num_verify_col = 0;

		num_verify_col = (C - 1) / W + W;

		printf("Case #%d: %d\n", testcase, num_verify_row + num_verify_col);
	}
	return 0;
}
