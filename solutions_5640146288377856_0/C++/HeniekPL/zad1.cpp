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
		if (C % W == 0) {
			print_result((C / W) + W - 1, t);
		} else {
			print_result((C / W) + W, t);
		}
	}
	return 0;
}
