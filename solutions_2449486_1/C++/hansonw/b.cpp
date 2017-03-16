#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		int N, M; cin >> N >> M;
		int grid[111][111];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> grid[i][j];
			}
		}

		bool ok = true;
		for (int i = 0; i < N && ok; i++) {
			for (int j = 0; j < M && ok; j++) {
				// There must be a direction i was sheared in
				bool cok = true;
				for (int k = 0; k < N && cok; k++) {
					if (grid[k][j] > grid[i][j]) {
						cok = false;
					}
				}
				if (cok) continue;
				cok = true;
				for (int k = 0; k < M && cok; k++) {
					if (grid[i][k] > grid[i][j]) {
						cok = false;
					}
				}
				ok = cok;
			}
		}

		printf("Case #%d: %s\n", tt, ok ? "YES" : "NO");
	}
}
