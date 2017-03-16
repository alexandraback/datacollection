#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX_N = 100 + 10;
int lawn[MAX_N][MAX_N];

int main() {
	int T;
	int cas = 0;
	//freopen("B-small-attempt0.in", "r", stdin);
	//freopen("B-small-attempt0.txt", "w", stdout);

	//freopen("C-large-1.in", "r", stdin);
	//freopen("C-large-1.txt", "w", stdout);

	scanf("%d", &T);
	while (T--) {
		int N, M;
		scanf("%d%d", &N, &M);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				scanf("%d", &lawn[i][j]);
			}
		}
		
		bool ans = false;
		while (true) {
			int min = 1000;
			int r = 0;
			int c = 0;
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					if (lawn[i][j] > 0 && lawn[i][j] < min) {
						min = lawn[i][j];
						r = i;
						c = j;
					}
				}
			}
			if (min == 1000) {
				ans = true;
				break;
			}
			bool flag = true;
			for (int j = 0; j < M; ++j) {
				if (lawn[r][j] > lawn[r][c]) {
					flag = false;
					break;
				}
			}
			if (flag) {
				for (int j = 0; j < M; ++j) {
					lawn[r][j] = 0;
				}
			} else {
				flag = true;
				for (int i = 0; i < N; ++i) {
					if (lawn[i][c] > lawn[r][c]) {
						flag = false;
						break;
					}
				}
				if (flag) {
					for (int i = 0; i < N; ++i) {
						lawn[i][c] = 0;
					}
				}
			}
			if (!flag) {
				break;
			}
		}
		if (ans) {
			printf("Case #%d: YES\n", ++cas);
		} else {
			printf("Case #%d: NO\n", ++cas);
		}
	}
	return 0;
}
				