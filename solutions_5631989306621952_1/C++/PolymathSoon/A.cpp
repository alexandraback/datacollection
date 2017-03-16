#include <cstdio>
#include <cstring>

char s[1005], ans[2005];

int solve(FILE *ofp) {
	int len = strlen(s);
	int l = len, r = len;
	ans[l] = s[0];
	for (int i = 1; i < len; ++i)
		if (s[i] >= ans[l])
			ans[--l] = s[i];
		else
			ans[++r] = s[i];
	for (int i = l; i <= r; ++i)
		fprintf(ofp, "%c", ans[i]);
	fprintf(ofp, "\n");
}

int main() {
	int T;
	FILE *ifp = fopen("A.in", "r");
	FILE *ofp = fopen("A.out", "w");
	fscanf(ifp, "%d", &T);
	for (int t = 1; t <= T; ++t) {
		fscanf(ifp, " %s", s);
		fprintf(ofp, "Case #%d: ", t);
		solve(ofp);
	}
	fclose(ifp);
	fclose(ofp);
	return 0;
}
