#include <iostream>
using namespace std;

int main() {
	int R, C, M, num, min, max;
	cin >> num;
	//num = 1;
	for (int i = 0; i < num; i++) {
		cin >> R >> C >> M;
		//R = 5; C = 5; M = 23;
		int total = R * C, free = total - M;
		bool ans = false;

		cout << "Case #" << i + 1 << ":\n";
		int** output = new int*[R];
		for (int j = 0; j < R; j++) {
			output[j] = new int[C];
		}
		for (int j = 0; j < R; j++) {
			for (int k = 0; k < C; k++) {
				output[j][k] = 1; // mine
			}
		}

		int R2 = R, C2 = C;
		if (R2 >= C2) { max = R2; min = C2; }
		else { max = C2; min = R2; }

		//int once = 0;
		while (M >= min) {
			//cout << M << ' ' << R2 << ' ' << C2 << '\n';
			M = M - min;
			//once = once % 2;
			if (min == R2) { C2--; }
			else { R2--; }
			if (R2 >= C2) { max = R2; min = C2; }
			else { max = C2; min = R2; }
		}
		//cout << M << ' ' << R2 << ' ' << C2 << ' ' << min << ' ' << max << '\n';
		if (M == 0) {
			if ((R == 1 || C == 1) || (R2 >= 2 && C2 >= 2) || (R2 == 1 && C2 == 1)) {
				for (int j = 0; j < R2; j++) {
					for (int k = 0; k < C2; k++) {
						output[j][k] = 0;
					}
				}
				output[0][0] = 2;
				ans = true;
			}
			else {
				ans = false;
			}
		}
		else if (M == min - 1) {
			for (int j = 0; j < R2; j++) {
				for (int k = 0; k < C2; k++) {
					output[j][k] = 0;
				}
			}
			output[0][0] = 2;
			if (min == R2 && C2 > R2 && min > 2) {
				int C3 = C2 - 1;
				for (int k = M; k > 0; k--) {
					output[R2 - 1][C3] = 1; C3--;
				}
				ans = true;
			}
			else if (min == C2 && R2 > C2 && min > 2) {
				int R3 = R2 - 1;
				for (int k = M; k > 0; k--) {
					output[R3][C2 - 1] = 1; R3--;
				}
				ans = true;
			}
			else if (R2 == C2) {
				if (R2 < 4) {
					ans = false;
				}
				else {
					int R3 = R2 - 1, C3 = 0, p = M / 2 - 1;
					for (int j = 1; j >= 0; j--) {
						C3 = C2 - 1;
						for (int k = p; k >= 0; k--) {
							output[R3][C3] = 1;
							C3--;
							M--;
						}
						R3--;
					}
					if (M > 0) {
						output[R2 - 1][C3] = 1;
					}
					ans = true;
				}
			}
			else {
				ans = false;
			}
		}
		else {
			for (int j = 0; j < R2; j++) {
				for (int k = 0; k < C2; k++) {
					output[j][k] = 0;
				}
			}
			output[0][0] = 2;
			int R3 = R2 - 1, C3 = 0, p = M / 2 - 1;
			for (int j = 1; j >= 0; j--) {
				C3 = C2 - 1;
				for (int k = p; k >= 0; k--) {
					output[R3][C3] = 1;
					C3--;
					M--;
				}
				R3--;
			}
			if (M > 0) {
				output[R2 - 1][C3] = 1;
			}
			ans = true;
		}

		if (!ans) {
			cout << "Impossible\n";
		}
		else {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (output[j][k] == 0) {
						cout << '.';
					}
					else if (output[j][k] == 1) {
						cout << '*';
					}
					else {
						cout << 'c';
					}
				}
				cout << "\n";
			}
		}
	}

	return 0;
}