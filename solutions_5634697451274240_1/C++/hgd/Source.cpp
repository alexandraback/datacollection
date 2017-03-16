#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;

int main() {
	FILE *fp = fopen("B-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		char tmp[256];
		fscanf(fp, "%s", tmp);
		int ans = 0, k;
		for (k = 1; tmp[k] != '\0'; ++k) {
			if (tmp[k] != tmp[k - 1]) ++ans;
		}
		if (tmp[k - 1] == '-') ++ans;
		fprintf(fout, "Case #%d: %d\n", iii + 1, ans);
	}
	fclose(fp);
	fclose(fout);
	return 0;
}