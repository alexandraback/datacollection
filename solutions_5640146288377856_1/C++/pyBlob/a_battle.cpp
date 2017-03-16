#include <cstdio>
#include <vector>
#include <cassert>

using namespace std;



void run() {
	int R, C, W;
	scanf("%d %d %d", &R, &C, &W);

	assert(W <= C);

	int steps = 0;
	steps += (R-1) * (C/W);
	steps += C/W-1;
	if ((C%W) == 0) {
		steps += W;
	} else {
		steps += W+1;
	}
	printf("%d\n", steps);
}

int main() {
	int T;
	scanf("%d", &T);

	for (int TC=1 ; TC<=T ; TC++) {
		printf("Case #%d: ", TC);

		run();
	}
}