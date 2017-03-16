#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 105;
const char *id = "+-";

int main() {
	int T;
	scanf("%d", &T);
	for (int C = 1; C <= T; C++) {
		int n, f[2][N];
		char s[N];
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; i++) {
			for (int k = 0; k < 2; k++) {
				int t = s[i] != id[k];
				f[k][i] = t;
				if (i > 0) f[k][i] += f[k^t][i-1];
			}
			for (int k = 0; k < 2; k++)
				f[k][i] = min(f[k][i], 1+f[k^1][i]);
		}
		printf("Case #%d: %d\n", C, f[0][n-1]);
	}
	return 0;
}
