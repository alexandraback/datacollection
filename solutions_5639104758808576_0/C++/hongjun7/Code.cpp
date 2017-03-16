#include <cstdio>
int S[1005];
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int run = 1; run <= T; run++) {
		int Smax;
		scanf("%d", &Smax);
		for (int i = 0; i <= Smax; i++) scanf("%1d", S + i);
		int standing = 0;
		int res = 0;
		for (int i = 0; i <= Smax; i++) {
			if (standing >= i) standing += S[i];
			else {
				res += i - standing;
				standing = i + S[i];
			}
		}
		printf("Case #%d: %d\n", run, res);
	}
	fcloseall();
	return 0;
}