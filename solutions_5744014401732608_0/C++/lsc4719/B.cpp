#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_B = 11;

int B;
int M;
int matrix[MAX_B][MAX_B];
bool visited[MAX_B];

void mkMatrix(int bitmask) {
	memset(matrix, 0, sizeof(matrix));

	int currentBitPos = 0;

	for (int i = 0; i < B; i++) {
		for (int j = i + 1; j < B; j++) {
			matrix[i][j] = ((bitmask & (1 << currentBitPos)) > 0);
			currentBitPos++;
		}
	}
}

int dfs(int currentPos) {
	if (currentPos == B - 1) return 1;

	visited[currentPos] = 1;

	//go
	int ret = 0;
	for (int nextPos = 0; nextPos < B; nextPos++) {
		if (!visited[nextPos] && matrix[currentPos][nextPos]) {
			ret += dfs(nextPos);
		}
	}

	visited[currentPos] = 0;

	return ret;
}

void printfMatrix() {
	for (int i = 0; i < B; i++) {
		for (int j = 0; j < B; j++) {
			printf("%d", matrix[i][j]);
		}
		puts("");
	}
}

void solve(int tc) {
	cin >> B >> M;

	int bitmaskSize = B * (B-1) / 2;

	for (int i = 0; i < (1 << bitmaskSize); i++) {
		mkMatrix(i);

		memset(visited, 0, sizeof(visited));
		int cntRoutes = dfs(0);

		if (cntRoutes == M) {
			printf("Case #%d: POSSIBLE\n", tc);
			printfMatrix();
			return;
		}
	}

	printf("Case #%d: IMPOSSIBLE\n", tc);
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 1; i <= tc; i++) solve(i);
	return 0;
}