#include <iostream>
#include <functional>
#include <algorithm>

using namespace std;

int R, N, M, K, p[16];

int main(int argc, char *argv[])
{
	int T;
	cin >> T;

	cout << "Case #1:" << endl;

	cin >> R >> N >> M >> K;
	for (int r = 0; r < R; r++) {
		int a2 = 0, a3 = 0, a5 = 0;
		bool has2 = false;
		for (int i = 0; i < K; i++) {
			cin >> p[i];
			int c = 0;
			for (int x = p[i]; ; x /= 2, c++) if (x % 2) break;
			a2 = max(a2, c);
			if (c % 2) has2 = true;
			c = 0;
			for (int x = p[i]; ; x /= 3, c++) if (x % 3) break;
			a3 = max(a3, c);
			c = 0;
			for (int x = p[i]; ; x /= 5, c++) if (x % 5) break;
			a5 = max(a5, c);
		}
		if (a2 + a3 + a5 <= N) {
			int c = N;
			for (int i = 0; i < a2; i++, c--) cout << 2;
			for (int i = 0; i < a3; i++, c--) cout << 3;
			for (int i = 0; i < a5; i++, c--) cout << 5;
			for (int i = 0; i < c; i++) cout << 2;
		} else if (!has2 && a2 % 2 == 0 && (a3 + a5 + a2 / 2 <= N)) {	// has 4, but no 2
			int c = N;
			for (int i = 0; i < a2 / 2; i++, c--) cout << 4;
			for (int i = 0; i < a3; i++, c--) cout << 3;
			for (int i = 0; i < a5; i++, c--) cout << 5;
			for (int i = 0; i < c; i++) cout << 3;
		} else if (a2 >= 2 && (a3 + a5 + a2 - 1 <= N)) {	// one 4
			int c = N - 1;
			cout << 4;
			for (int i = 0; i < a2 - 2; i++, c--) cout << 2;
			for (int i = 0; i < a3; i++, c--) cout << 3;
			for (int i = 0; i < a5; i++, c--) cout << 5;
			for (int i = 0; i < c; i++) cout << 2;
		} else if (a2 >= 4 && (a3 + a5 + a2 - 2 <= N)) {	// two 4s
			int c = N - 2;
			cout << 44;
			for (int i = 0; i < a2 - 4; i++, c--) cout << 2;
			for (int i = 0; i < a3; i++, c--) cout << 3;
			for (int i = 0; i < a5; i++, c--) cout << 5;
			for (int i = 0; i < c; i++) cout << 2;
		} else if (a2 >= 6 && (a3 + a5 + a2 - 3 <= N)) {	// three 4s
			int c = N - 3;
			cout << 444;
			for (int i = 0; i < a2 - 6; i++, c--) cout << 2;
			for (int i = 0; i < a3; i++, c--) cout << 3;
			for (int i = 0; i < a5; i++, c--) cout << 5;
			for (int i = 0; i < c; i++) cout << 2;
		} else {
			for (int i = 0; i < N; i++) cout << 2;
		}
		cout << endl;
	}

	return 0;
}
