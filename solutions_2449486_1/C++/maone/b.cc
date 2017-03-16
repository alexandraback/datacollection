// Lawnmower

#include <iostream>
#include <vector>
using namespace std;

int n, m;
int h[128][128];

void print(int mat[][128]) {
	return;

	cout << n << ' ' << m << endl;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << mat[i][j] << ' ';
		}
		cout << endl;
	}
}

bool run() {
	int left[128][128], right[128][128], top[128][128], bottom[128][128];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j == 0) left[i][j] = h[i][j];
			else left[i][j] = max(left[i][j - 1], h[i][j]);
		}

		for (int j = m - 1; j >= 0; --j) {
			if (j == m - 1) right[i][j] = h[i][j];
			else right[i][j] = max(right[i][j + 1], h[i][j]);
		}
	}

	for (int j = 0; j < m; ++j) {
		for (int i = 0; i < n; ++i) {
			if (i == 0) top[i][j] = h[i][j];
			else top[i][j] = max(top[i - 1][j], h[i][j]);
		}

		for (int i = n - 1; i >= 0; --i) {
			if (i == n - 1) bottom[i][j] = h[i][j];
			else bottom[i][j] = max(bottom[i + 1][j], h[i][j]);
		}
	}

	print(h);
	print(left);
	print(right);
	print(bottom);
	print(top);

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if ((top[i][j] > h[i][j] || bottom[i][j] > h[i][j])
				&& (left[i][j] > h[i][j] || right[i][j] > h[i][j])) {
				return false;
			}
		}
	}

	return true;
}

int main(int argc, const char* argv[]) {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		cin >> n >> m;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cin >> h[i][j];
			}
		}
		cout << "Case #" << t << ": " << (run() ? "YES" : "NO") << endl;
	}

	return 0;
}
