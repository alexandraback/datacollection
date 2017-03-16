#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	int t;
	int i, j;
	int N;
	int heights[2510];
	int h;

	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	cin >> T;
	for (t = 1; t <= T; ++t) {
		cin >> N;
		memset(heights, 0, sizeof(heights));
		for (i = 0; i < 2*N-1; ++i) {
			for (j = 0; j < N; ++j) {
				cin >> h;
				heights[h]++;
			}
		}

		// build grid
		cout << "Case #" << t << ": ";
		for (i = 1; i <= 2500; ++i) {
			if (heights[i] % 2 != 0)
				cout << i << " ";
		}
		cout << endl;
	}
	return 0;
}