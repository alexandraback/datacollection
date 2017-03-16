#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void init();
void runCase();

int main()
{
	init();

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		runCase();
	}
}

// algorithms

int R, C, W;

void init() {
}

int case1()
{
	int S = C % W;
	if (S == 0) {
		return W;
	}
	else {
		return W + 1;
	}
}

void runCase()
{
	scanf("%d %d %d", &R, &C, &W);

	int div = C / W;
	int n = (R - 1) * div;
	int nn = div - 1;
	n += nn;
	C -= nn * W;
	n += case1();

	printf("%d\n", n);
}
