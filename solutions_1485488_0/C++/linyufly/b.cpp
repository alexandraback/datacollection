#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const double inf = 1e100;
const double eps = 1e-8;
const int maxl = 200;

const int dire[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int Sign(double a) {
	return a < -eps ? -1 : a > eps;
}

struct Position {
	int row, col;

	Position() {
	}

	Position(int row, int col) : row(row), col(col) {
	}
};

multimap<double, Position> record;
int F[maxl][maxl], C[maxl][maxl];
bool used[maxl][maxl];
double minpath[maxl][maxl];
int N, M, H;

bool Outside(int r, int c) {
	return r < 0 || c < 0 || r >= N || c >= M;
}

void Solve(int number) {
	scanf("%d %d %d", &H, &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &C[i][j]);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &F[i][j]);
	//if (number + 1 == 10) {
	//	printf("%d %d %d\n", H, N, M);
	//	printf("\n");
	//	for (int i = 0; i < N; i++) {
	//		for (int j = 0; j < M; j++)
	//			printf("\t%d", C[i][j]);
	//		printf("\n");
	//	}
	//	printf("\n");
	//	for (int i = 0; i < N; i++) {
	//		for (int j = 0; j < M; j++)
	//			printf("\t%d", F[i][j]);
	//		printf("\n");
	//	}
	//}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			minpath[i][j] = inf;
			used[i][j] = false;
		}
	minpath[0][0] = 0;
	record.clear();
	record.insert(pair<double, Position>(0, Position(0, 0)));
	while (record.size() > 0) {
		Position posi = record.begin()->second;
		record.erase(record.begin());
		int currR = posi.row;
		int currC = posi.col;
		double currT = minpath[currR][currC];
		double currH = H - 10 * currT;
		if (used[currR][currC]) continue;
		used[currR][currC] = true;
		if (currR == N - 1 && currC == M - 1) break;
		for (int k = 0; k < 4; k++) {
			int nextR = currR + dire[k][0];
			int nextC = currC + dire[k][1];
			if (Outside(nextR, nextC)) continue;
			if (used[nextR][nextC]) continue;
			double wait = 0;
			if (Sign(F[nextR][nextC] + 50 - C[nextR][nextC]) > 0) continue;
			if (Sign(F[currR][currC] + 50 - C[nextR][nextC]) > 0) continue;
			if (Sign(F[nextR][nextC] + 50 - C[currR][currC]) > 0) continue;
			if (Sign(currH + 50 - C[nextR][nextC]) > 0)
				wait = (currH + 50 - C[nextR][nextC]) / 10;
			double cost;
			if (!Sign(currT + wait)) cost = 0;
			else
				if (Sign(currH - 10 * wait - F[currR][currC] - 20) >= 0) cost = wait + 1;
				else cost = wait + 10;
			if (minpath[nextR][nextC] < currT + cost) continue;
			minpath[nextR][nextC] = currT + cost;
			record.insert(pair<double, Position>(minpath[nextR][nextC], Position(nextR, nextC)));
		}
	}
	//printf("\n");
	//if (number + 1 == 10) {
	//	for (int i = 0; i < N; i++) {
	//		for (int j = 0; j < M; j++)
	//			printf(" %d", used[i][j]);
	//		printf("\n");
	//	}
	//}
	printf("%.10lf\n", minpath[N - 1][M - 1]);
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		printf("Case #%d: ", i + 1);
		Solve(i);
	}
	return 0;
}