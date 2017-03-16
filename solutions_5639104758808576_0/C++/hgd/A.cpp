#include <cstdio>
#include <cstdlib>
#include <cctype>

int main() {
	FILE *fp = fopen("A-small-attempt0.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T, ans, num, smax, m;
	fscanf(fp, "%d", &T);
	for (int i = 0; i < T; ++i) {
		fscanf(fp, "%d", &smax);
		ans = 0;
		num = 0;
		for (int j = 0; j <= smax; ++j) {
			while (!isdigit(m = fgetc(fp)));
			m -= '0';
			if (num < j) {
				ans += j - num;
				num = j;
			}
			num += m;
		}
		fprintf(fout, "Case #%d: %d\n", i + 1, ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}