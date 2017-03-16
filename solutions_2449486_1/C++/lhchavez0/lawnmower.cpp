#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

int A[110][110];
int rows[110];
int cols[110];

int main() {
	int T, N, M;
	
	scanf("%d\n", &T);
	
	for (int nCase = 1; nCase <= T; nCase++) {
		scanf("%d %d\n", &N, &M);
		
		memset(rows, 0, sizeof(rows));
		memset(cols, 0, sizeof(cols));
		
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				scanf("%d", &A[i][j]);
				rows[i] = max(rows[i], A[i][j]);
				cols[j] = max(cols[j], A[i][j]);
			}
		}
		
		bool solved = true;
		
		for (int i = 0; solved && i < N; i++) {
			for(int j = 0; j < M; j++) {
				if (min(rows[i], cols[j]) != A[i][j]) {
					solved = false;
					break;
				}
			}
		}
		
		printf("Case #%d: %s\n", nCase, (solved ? "YES" : "NO"));
	}
}
