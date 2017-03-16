#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <numeric>

using namespace std;

int X, Y;
void read() {
	scanf("%d %d", &X, &Y);
}

void process() {
	if (X < 0) {
		int k = -X;
		for (int i = 0; i < k; i++) {
			printf("EW");
		}
	} else {
		for (int i = 0; i < X; i++) {
			printf("WE");
		}
	}
	if (Y < 0) {
		int k = -Y;
		for (int i = 0; i < k; i++) {
			printf("NS");
		}
	} else {
		for (int i = 0; i < Y; i++) {
			printf("SN");
		}
	}
	printf("\n");
}

int main() {
	int cases;
	scanf("%d", &cases);
	for (int i = 1; i <= cases; i++) {
		read();
		printf("Case #%d: ", i);
		process();
	}
	return 0;
}