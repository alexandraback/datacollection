#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool handle_case() {
	int N, M;

	cin >> N >> M;

	int lawn[100][100];

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			cin >> lawn[x][y];
		}
	}

	vector<int> row_maximum(N, 0);
	vector<int> column_maximum(M, 0);

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			row_maximum[y] = max(row_maximum[y], lawn[x][y]);
			column_maximum[x] = max(column_maximum[x], lawn[x][y]);
		}
	}

	for (int y = 0; y < N; ++y) {
		for (int x = 0; x < M; ++x) {
			if (lawn[x][y] < row_maximum[y] &&
			    lawn[x][y] < column_maximum[x]) {
				return false;
			}
		}
	}

	return true;
}

int main(void) {

	int T;

	cin >> T;

	for (int i = 0; i < T; ++i) {
		cout << "Case #" << i+1 << ": " << (handle_case() ? "YES" : "NO") << endl;
	}

	return 0;
}
