#include <iostream>
#include <cstdio>
using namespace std;

int a[100][100];
int rmax[100];
int cmax[100];

int main() {
	int T, N, M, hmax;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &M);
		for (int r = 0; r < N; r++) {
			hmax = -1;
			for (int c = 0; c < M; c++) {
				scanf("%d", &a[r][c]);
				if (hmax < a[r][c]) hmax = a[r][c];
			}
			rmax[r] = hmax;
		}

		for (int c = 0; c < M; c++) {
			hmax = -1;
			for (int r = 0; r < N; r++) {
				if (hmax < a[r][c]) hmax = a[r][c];
			}
			cmax[c] = hmax;
		}

		bool ans = true;
		for (int r = 0; r < N && ans; r++) {
			for (int c = 0; c < M && ans; c++) {
				if (a[r][c] < rmax[r] && a[r][c] < cmax[c]) {
					ans = false;
					break;
				}
			}
		}

		cout << "Case #" << t <<": " << (ans ? "YES" : "NO") << endl;
	}
}