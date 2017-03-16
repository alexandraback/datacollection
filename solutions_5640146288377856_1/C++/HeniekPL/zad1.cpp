#include <cstdio>
#include <cstdlib>

using namespace std;

const int T_MAX = 55;
const int C_MAX = 10;

void print_result(int result, int t) {
	printf("Case #%d: %d\n", t, result);
}

int main() {
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int R, C, W;
		scanf("%d %d %d", &R, &C, &W);
		int result = (R - 1) * (C / W);
		if (C % W == 0) {
			result = result + (C / W) + W - 1;
		} else {
			result = result + (C / W) + W;
		}
		print_result(result, t);
	}
	return 0;
}
