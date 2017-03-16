#include <iostream>

using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N, S, p;
		cin >> N >> S >> p;
		int score;

		int rs = 0;
		int su = 0;
		for (int n = 0; n < N; n++) {
			cin >> score;
			int d = score / 3;
			int r = score % 3;

			if (score == 0) {
				if (p == 0)
					rs++;
				continue;
			}
			else if (score == 1) {
				if (p <= 1)
					rs++;
				continue;
			}
			else if (score == 2) {
				if (p <= 1)
					rs++;
				else if (p == 2 && su < S) {
					rs++;
					su++;
				}
				continue;
			}

			if (d >= p) {
				rs++;
			}
			else {
				if (r == 0) {
					if (d + 1 >= p && su < S) {
						rs++;
						su++;
					}
				}
				else if (r == 2) {
					if (d + 1 >= p)
						rs++;
					else if (d + 2 >= p && su < S) {
						rs++;
						su++;
					}
				}
				else {
					if (d + 1 >= p) {
						rs++;
					}
				}
			}
		}

		// result
		cout << "Case #" << t << ": " << rs << endl;
	}
	return 0;
}
