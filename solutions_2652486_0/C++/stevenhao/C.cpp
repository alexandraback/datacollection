#include <cstdio>

using namespace std;

const int choices = 4;
const int SIZE = 64;
const int MAXK = 10;
const int MAXV = 1000;

double ar[SIZE];
int grid[SIZE][3];

int T;
int R, N, M, K;

int nums[MAXK];
int ways[SIZE][MAXV];

int main() {
	N = 3;
	M = 5;
	for(int i = 0; i < SIZE; ++i) {
		int x = i;
		for(int j = 0; j < N; ++j) {
			grid[i][j] = 2 + (x % choices);
			x /= choices;
		}
		for(int j = 0; j < (1 << N); ++j) {
			int prod = 1;
			for(int k = 0; k < N; ++k) {
				if ((j >> k) & 1) prod *= grid[i][k];
			}
			++ways[i][prod];
		}
	}

	scanf("%d", &T);

	for(int t = 1; t <= T; ++t) {
		scanf("%d %d %d %d", &R, &N, &M, &K);
		for(int i = 0; i < R; ++i) {
			for(int i = 0; i < SIZE; ++i) {
				ar[i] = 1;
			}

			for(int i = 0; i < K; ++i) {
				scanf("%d", nums + i);
			}

			for(int i = 0; i < K; ++i) {
				for(int j = 0; j < SIZE; ++j) {
					ar[j] *= ways[j][nums[i]];
				}
			}

			int best = 0;
			for(int i = 0; i < SIZE; ++i) {
				if (ar[i] > ar[best]) best = i;
			}

			for(int i = 0; i < N; ++i) {
				printf("%d", grid[best][i]);
			}
			printf("\n");
		}
	}

	return 0;
}
