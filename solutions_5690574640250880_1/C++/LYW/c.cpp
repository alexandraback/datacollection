#include <cstdio>
#include <algorithm>
using namespace std;

int R, C, N;
char board[51][51];
int mineCount[51][51];

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

void initBoard(void) {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			board[i][j] = '.';
		}
		board[i][C] = 0;
	}
	board[0][0] = 'c';
}

bool isValid(void) {
	int cnt = 0;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '*')
				cnt ++;
		}
	}
	if (cnt != N)
		return false;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			mineCount[i][j] = 0;
			for (int k = 0; k < 8; k++) {
				int wy = i + dy[k];
				int wx = j + dx[k];
				if (0 <= wy && 0 <= wx && wy < R && wx < C) {
					if (board[wy][wx] == '*')
						mineCount[i][j] ++;
				}
			}
		}
	}

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '.') {
				bool isOpen = false;
				for (int k = 0; k < 8; k++) {
					int wy = i + dy[k];
					int wx = j + dx[k];
					if (0 <= wy && 0 <= wx && wy < R && wx < C) {
						if (board[wy][wx] != '*' && mineCount[wy][wx] == 0) 
							isOpen = true;
					}
				}
				if (!isOpen)
					return false;
			}
		}
	}

	return true;
}

bool getAnsCol(int R, int C, int N) {
	// Column-First
	for (int i = C - 1; i >= 0; i--) {
		int numFill = R;
		if ((C - i) * R > N)
			numFill = N % R;

		for (int j = 0; j < numFill; j++) {
			board[R - j - 1][i] = '*';
		}

		if ((C - i) * R >= N)
			break;
	}

	if (isValid())
		return true;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '*')
				board[i][j] = '.';
		}
	}

	// Column-First
	for (int i = C - 1; i >= 0; i--) {
		int numFill = (R - 2);
		if ((C - i) * (R - 2) > N)
			numFill = N % (R - 2);

		for (int j = 0; j < numFill; j++) {
			board[R - j - 1][i] = '*';
		}

		if ((C - i) * (R - 2) >= N)
			break;
	}

	if (isValid())
		return true;

	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (board[i][j] == '*')
				board[i][j] = '.';
		}
	}

	return false;
}

bool getAnsRow(int R, int C, int N) {

	if (getAnsCol(R, C, N))
		return true;
	
	// Row-First
	for (int i = R - 1; i >= 0; i--) {
		int numFill = C;
		if ((R - i) * C > N)
			numFill = N % C;
		for (int j = 0; j < numFill; j++) {
			board[i][C - j - 1] = '*';
		}

		if ((R - i) * C >= N) {
			if (isValid())
				return true;
		} else {
			if (getAnsCol(i, C, N - (R - i) * C))
				return true;
		}

		if ((R - i) * C >= N)
			break;
	}
	
	// Row-First
	initBoard();
	for (int i = R - 1; i >= 0; i--) {
		int numFill = (C - 2);
		if ((R - i) * (C - 2) > N)
			numFill = N % (C - 2);
		for (int j = 0; j < numFill; j++) {
			board[i][C - j - 1] = '*';
		}

		if ((R - i) * (C - 2) >= N) {
			if (isValid())
				return true;
		}

		if ((R - i) * (C - 2) >= N)
			break;
	}

	return false;
}

int main(void) {
	int testNum;
	scanf("%d", &testNum);
	for (int testCase = 0; testCase < testNum; testCase++) {
		scanf("%d %d %d", &R, &C, &N);

		printf("Case #%d:\n", testCase + 1);

		initBoard();
		bool ret = getAnsRow(R, C, N);
		if (ret) {
			for (int i = 0; i < R; i++) {
				printf("%s\n", board[i]);
			}
		} else {
			printf("Impossible\n");
		}
	}
	return 0;
}
