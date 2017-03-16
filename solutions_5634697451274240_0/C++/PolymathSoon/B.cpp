#include <cstdio>
#include <cstring>

int work(char *s) {
	int ans = 0;
	for (int i = strlen(s) - 1; i > 0; --i)
		ans += (s[i] != s[i - 1]);
	return ans + (s[strlen(s) - 1] == '-');
}

int main() {
	int T;
	char S[105];
	FILE *ifp = fopen("B.in", "r");
	FILE *ofp = fopen("B.out", "w");
	fscanf(ifp, "%d", &T);
	for (int t = 1; t <= T; ++t) {
		fscanf(ifp, " %s", S);
		fprintf(ofp, "Case #%d: %d\n", t, work(S));
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
