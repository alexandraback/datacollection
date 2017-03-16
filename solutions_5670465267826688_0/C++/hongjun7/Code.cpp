#include <cstdio>
#include <vector>
using namespace std;
int X, L, C[10005];
char S[10005];
int A[4][4] = { { 1, 2, 3, 4 }, { 2, -1, 4, -3 }, { 3, -4, -1, 2 }, { 4, 3, -2, -1 } };
inline int f(char X) {
	if (X == 'i') return 2;
	if (X == 'j') return 3;
	return 4;
}
pair <int, int> Left[10005], Right[10005];
int main() {
	int T;
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	scanf("%d", &T);
	for (int run = 1; run <= T; run++) {
		scanf("%d%d", &X, &L);
		scanf("%s", S + 1);
		for (int i = X + 1; i <= L*X; i++) S[i] = S[i - X];
		for (int i = 1; i <= L*X; i++) C[i] = f(S[i]);
		int x = 1, y = 1;
		for (int i = 1; i <= L*X; i++) {
			x = A[x - 1][C[i] - 1];
			if (x < 0) y *= -1, x = -x;
			Left[i] = { x, y };
		}
		x = 1, y = 1;
		for (int i = L*X; i >= 1; i--) {
			x = A[C[i] - 1][x - 1];
			if (x < 0) y *= -1, x = -x;
			Right[i] = { x, y };
		}
		int ok = 0;
		for (int i = 1; i <= L*X; i++) {
			if (Left[i] != make_pair(2, 1)) continue;
			x = 1, y = 1;
			for (int j = i + 1; j < L*X; j++) {
				x = A[x - 1][C[j] - 1];
				if (x < 0) y *= -1, x = -x;
				if (x == 3 && y == 1 && Right[j + 1] == make_pair(4, 1)) {
					ok = 1;
					break;
				}
			}
		}
		printf("Case #%d: %s\n", run, ok ? "YES" : "NO");
	}
	fcloseall();
	return 0;
}