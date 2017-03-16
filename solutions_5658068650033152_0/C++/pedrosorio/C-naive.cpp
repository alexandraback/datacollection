#include <iostream>
#include <vector>

using namespace std;

int flood(int board, int r, int c, int N, int M) {
	int place = 1 << (M*r + c);
	if ((board) & place) {
		return board;
	}
	board = board | place;
	if (r > 0) {
		board = flood(board, r-1, c, N, M);
	}
	if (r < N-1) {
		board = flood(board, r+1, c, N, M);
	}
	if (c > 0) {
		board = flood(board, r, c-1, N, M);
	}
	if (c < M-1) {
		board = flood(board, r, c+1, N, M);
	}
	return board;
}

int count_bits(int board) {
	int ct = 0;
	while (board > 0) {
		ct += board%2;
		board /= 2;
	}
	return ct;
}

int main() {
	int T;
	cin >> T;
	for (int cs = 1; cs <= T; cs++) {
		int N,M,K;
		cin >> N >> M >> K;
		int sz = N*M;
		int mn = K;
		int tot_boards = (1 << sz);
		for (int board = 0; board < tot_boards; board++) {
			int stones = count_bits(board);
			if (stones >= mn)
				continue;
			int flood_board = board;
			for (int i = 0; i < N; i++) {
				flood_board = flood(flood_board, i, 0, N, M);
				flood_board = flood(flood_board, i, M-1, N, M);
			}
			for (int j = 0; j < M; j++) {
				flood_board = flood(flood_board, 0, j, N, M);
				flood_board = flood(flood_board, N-1, j, N, M);
			}
			int enclosed = sz - count_bits(flood_board) + stones;
			if (enclosed >= K)
				mn = stones;
		}
		cout << "Case #" << cs << ": " << mn << endl;
	}
}