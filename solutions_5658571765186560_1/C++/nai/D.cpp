#include <cstdio>
#include <algorithm>
#include <cassert>

using namespace std;

int in() {
	int a;
	scanf("%d", &a);
	return a;
}

void output(int t, bool success) {
	printf("Case #%d: %s\n", t+1, !success ? "RICHARD" : "GABRIEL");
}

int main() {
	int T = in();
	for (int t = 0; t < T; t++) {
		int X = in();
		int R = in();
		int C = in();
		
		bool success;
		
		if (R * C % X != 0) {
			success = false;
		}
		else if (X >= 7) {
			success = false;
		}
		else if (X <= 2) {
			success = true;
		}
		else if (X == 3) {
			success = R >= 2 && C >= 2;
		}
		else if (X == 4) {
			success = R >= 3 && C >= 3;
		}
		else if (X == 5) {
			success = R >= 3 && C >= 3;
		}
		else if (X == 6) {
			success = R >= 4 && C >= 4;
		}
		else {
			assert(0);
		}
		
		output(t, success);
	}
	return 0;
}
