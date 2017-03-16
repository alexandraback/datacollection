#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream in("B-small.in");
	ofstream out("B-small.out");

	int T; in >> T;

	for (int x = 1; x <= T; x++) {
		int N, M; in >> N >> M;
		int b[N][M];
		for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) in >> b[i][j];
		int r[N]; for (int i = 0; i < N; i++) r[i] = 0;
		int c[M]; for (int i = 0; i < M; i++) c[i] = 0;
		int res = 0;
		for (int i = 0; i < N; i++) {
			int m = b[i][0];
			for (int j = 1; j < M; j++) m = max(m, b[i][j]);
			r[i] = m;
			for (int j = 1; j < M; j++)
				if (b[i][j] < m) {
					if (c[j] != 0 && c[j] != b[i][j]) {
						res = -1; break;
					}
					c[j] = b[i][j];
				}
			if (res != 0) break;
		}
		if (res != 0) {
			out << "Case #" << x << ": NO" << endl;
			continue;
		}
		for (int j = 0; j < M; j++) {
			int m = b[0][j];
			for (int i = 0; i < N; i++) m = max(b[i][j], m);
			if (c[j] != 0 && c[j] != m) {
				res = -1; break;
			}
			c[j] = m;
			for (int i = 0; i < N; i++)
				if (b[i][j] < m) {
					if (r[i] != b[i][j]) {
						res = -1; break;
					}
				}
			if (res != 0) break;
		}
		if (res != 0) {
			out << "Case #" << x << ": NO" << endl;
			continue;
		} else {
			out << "Case #" << x << ": YES" << endl;
			continue;
		}
	}
	return 0;
}
