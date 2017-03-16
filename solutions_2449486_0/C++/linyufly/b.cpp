#include <cstdio>
#include <algorithm>

using namespace std;

const int maxl = 200;

int board[maxl * maxl], list[maxl * maxl];
bool used[maxl * maxl];
int N, M;

bool Compare(int a, int b) {
	return board[a] < board[b];
}

bool Outside(int r, int c) {
	return r < 0 || c < 0 || r >= N || c >= M;
}

void Solve() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N * M; i++) {
		scanf("%d", &board[i]);
		used[i] = false;
		list[i] = i;
	}
	sort(list, list + N * M, Compare);
	for (int i = 0; i < N * M; i++) {
		int posi = list[i];
		if (used[posi]) continue;
		int r = posi / M;
		int c = posi % M;
		// Check row
		bool flag = true;
		for (int j = 0; j < M; j++) {
			int newPosi = r * M + j;
			if (used[newPosi]) continue;
			if (board[newPosi] != board[posi]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int j = 0; j < M; j++)
				used[r * M + j] = true;
			continue;
		}
		// Check col
		flag = true;
		for (int j = 0; j < N; j++) {
			int newPosi = j * M + c;
			if (used[newPosi]) continue;
			if (board[newPosi] != board[posi]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			for (int j = 0; j < N; j++)
				used[j * M + c] = true;
			continue;
		}
		printf("NO\n");
		return;
	}
	printf("YES\n");
}

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		Solve();
	}
	return 0;
}
