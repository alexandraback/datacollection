/*
 * Minesweeper Master  Google code jam
 *
 *  Created on: 2014Äê4ÔÂ12ÈÕ
 *      Author: Bevoid
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

int R,C,M;
int trainsFlag = 0;

int matrix[100][100];
void print() {
	if (trainsFlag == 1) {
		for (int i = 0; i < C; i++) {
			for (int j = 0; j < R; j++) {
				//printf("%d",matrix[i][j]);
				if (matrix[j][i] == 0) {
					printf(".");
				} else if (matrix[j][i] == 1) {
					printf("*");
				} else {
					printf("c");
				}
			}
			printf("\n");
		}
	} else {
		for (int i = 0; i < R; i++) {
			for (int j = 0; j < C; j++) {
				if (matrix[i][j] == 0) {
					printf(".");
				} else if (matrix[i][j] == 1) {
					printf("*");
				} else {
					printf("c");
				}
			}
			printf("\n");
		}		
	}
}

void fanxiang() {
	memset(matrix, 0, sizeof(matrix));

	int tmp = R;
	R = C;
	C = tmp;
	trainsFlag = 1;

	int remain = M;

	if (R <= 1) {
		if (M == 0) {
			matrix[R-1][C-1] = -1;
			print();
			return;
		}
		for (int i = 0; i < M; i++) {
			matrix[0][i] = 1;
		}
		matrix[R-1][C-1] = -1;
		print();
		return;
	}

	int now = 0;
	while (remain >= C && now < R - 2) {
		for (int i = 0; i < C; i++) {
			matrix[now][i] = 1; // À×
		}
		now++;
		remain-=C;
	}

	if (remain == 0) {
		matrix[R-1][C-1] = -1;
		print();
		return;
	}

	if (now != R - 2) {
		if (C - remain >= 2) {
			for (int i = 0; i < remain; i++) {
				matrix[now][i] = 1;
			}
			matrix[R-1][C-1] = -1;
			print();
			return;
		} else {
			if (remain <= 2) {
				printf("Impossible\n");
				return;
			}

			if (now + 1 != R - 2) {
				for (int i = 0; i < remain - 1; i++) {
					matrix[now][i] = 1;
				}
				now++;
				matrix[now][0] = 1;
				matrix[R-1][C-1] = -1;
				print();
				return;
			}

			for (int i = 0; i < remain - 2; i++) {
				matrix[now][i] = 1;
			}
			remain = 2;
			now++;

		}
	}

	int startTmp = 0;
	while (remain >= 2 && startTmp < C - 2) {
		matrix[now][startTmp] = 1;
		matrix[now + 1][startTmp] = 1;
		remain-=2;
		startTmp++;
	}

	if (startTmp < C - 2) {
		if (remain == 1) {
			if (startTmp + 1 < C - 3 && R >= 3 && C >= 3) {
				matrix[R-3][C-3] = 0; matrix[R-3][C-2] = 0;matrix[R-3][C-1] = 0;
				matrix[R-1][startTmp] = 1; matrix[R-1][startTmp+1] = 1;
				matrix[R-2][startTmp] = 1; matrix[R-2][startTmp+1] = 1;
				matrix[R-1][C-1] = -1;
				print();
			} else {
				printf("Impossible\n");
			}
		} else {
			matrix[R-1][C-1] = -1;
			print();
		}
	} else {
		if (remain == 3) {
			matrix[R-1][C-1] = -1;
			matrix[R-2][C-1] = 1;
			matrix[R-1][C-2] = 1;
			matrix[R-2][C-2] = 1;
			print();
		} else if (remain == 0) {
			matrix[R-1][C-1] = -1;
			print();
		} else {
			printf("Impossible\n");
		}
	}


}
int main() {
	freopen("D:/Downloads/C-small-attempt6.in", "r", stdin);
	freopen("d:/out6.out", "w", stdout);
	int T;
	while (scanf("%d", &T) != EOF) {
		int cases = 0;
		while (cases++ < T) {
			
			scanf("%d%d%d", &R, &C, &M);
			trainsFlag = 0;

			printf("Case #%d:\n", cases);

			int remain = M;
			memset(matrix, 0, sizeof(matrix));

			if (R <= 1) {
				if (M == 0) {
					matrix[R-1][C-1] = -1;
					print();
					continue;
				}
				for (int i = 0; i < M; i++) {
					matrix[0][i] = 1;
				}
				matrix[R-1][C-1] = -1;
				print();
				continue;
			}

			int now = 0;
			while (remain >= C && now < R - 2) {
				for (int i = 0; i < C; i++) {
					matrix[now][i] = 1; // À×
				}
				now++;
				remain-=C;
			}

			if (remain == 0) {
				matrix[R-1][C-1] = -1;
				print();
				continue;
			}

			if (now != R - 2) {
				if (C - remain >= 2) {
					for (int i = 0; i < remain; i++) {
						matrix[now][i] = 1;
					}
					matrix[R-1][C-1] = -1;
					print();
					continue;
				} else {
					if (remain <= 2) {
						fanxiang();
						continue;
					}

					if (now + 1 != R - 2) {
						for (int i = 0; i < remain - 1; i++) {
							matrix[now][i] = 1;
						}
						now++;
						matrix[now][0] = 1;
						matrix[R-1][C-1] = -1;
						print();
						continue;
					}

					for (int i = 0; i < remain - 2; i++) {
						matrix[now][i] = 1;
					}
					remain = 2;
					now++;

				}
			}

			int startTmp = 0;
			while (remain >= 2 && startTmp < C - 2) {
				matrix[now][startTmp] = 1;
				matrix[now + 1][startTmp] = 1;
				remain-=2;
				startTmp++;
			}

			if (startTmp < C - 2) {
				if (remain == 1) {
					if (startTmp + 1 < C - 3 && R >= 3 && C >= 3) {
						matrix[R-3][C-3] = 0; matrix[R-3][C-2] = 0;matrix[R-3][C-1] = 0;
						matrix[R-1][startTmp] = 1; matrix[R-1][startTmp+1] = 1;
						matrix[R-2][startTmp] = 1; matrix[R-2][startTmp+1] = 1;
						matrix[R-1][C-1] = -1;
						print();
					} else {
						fanxiang();
					}
				} else {
					matrix[R-1][C-1] = -1;
					print();
				}
			} else {
				if (remain == 3) {
					matrix[R-1][C-1] = -1;
					matrix[R-2][C-1] = 1;
					matrix[R-1][C-2] = 1;
					matrix[R-2][C-2] = 1;
					print();
				} else if (remain == 0) {
					matrix[R-1][C-1] = -1;
					print();
				} else {
					fanxiang();
				}
			}

		}
	}
	return 0;
}
