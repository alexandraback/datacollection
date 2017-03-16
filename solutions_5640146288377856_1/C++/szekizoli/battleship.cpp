#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void init() {

}

unsigned R, C, W;


unsigned solve() {
	int rows = (R - 1)*(C / W);
	if (C == W) {
		return rows + W;
	}

	if (C <= 2 * W) {
		return rows + W + 1;
	}

	int counter = 0;
	while (C > 2 * W) {
		++counter;
		C -= W;
	}

	return rows + counter + W + 1;
}

void solvecase() {
	cin >> R >> C >> W;
	cout << solve() << endl;
}

int N;
int main() {
	init();
	cin >> N;
	for (int t = 1; t <= N; ++t) {
		cout << "Case #" << t << ": ";
		solvecase();
	}

	return 0;
}