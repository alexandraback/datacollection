#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
using namespace std;

int main() {
	FILE *fp = fopen("B-large.in", "r");
	FILE *fout = fopen("out.txt", "w");
	int T;
	fscanf(fp, "%d", &T);
	for (int iii = 0; iii < T; ++iii) {
		char tmp1[100], tmp2[100];
		long long curmin1 = 0, curmin2 = 0, curmax1 = 0, curmax2 = 0, curbest1 = 0, curbest2 = 0;
		fscanf(fp, "%s %s", tmp1, tmp2);
		int n = strlen(tmp1);
		long long x = 1;
		for (int i = n - 1; i >= 0; --i) {
			if (tmp1[i] != '?' && tmp2[i] != '?') {
				if (tmp1[i] > tmp2[i]) {
					curbest1 = (tmp1[i] - '0') * x + curmin1;
					curbest2 = (tmp2[i] - '0') * x + curmax2;
				}
				else if (tmp1[i] < tmp2[i]) {
					curbest1 = (tmp1[i] - '0') * x + curmax1;
					curbest2 = (tmp2[i] - '0') * x + curmin2;
				}
				else {
					curbest1 = (tmp1[i] - '0') * x + curbest1;
					curbest2 = (tmp2[i] - '0') * x + curbest2;
				}
				curmin1 += (tmp1[i] - '0') * x;
				curmax1 += (tmp1[i] - '0') * x;
				curmin2 += (tmp2[i] - '0') * x;
				curmax2 += (tmp2[i] - '0') * x;
			}
			else if (tmp1[i] != '?' && tmp2[i] == '?') {
				long long t1 = (tmp1[i] - '0') * x + curbest1;
				long long t2 = (tmp1[i] - '0') * x + curbest2;
				if (tmp1[i] != '0') {
					curbest1 = (tmp1[i] - '0') * x + curmin1;
					curbest2 = (tmp1[i] - '0' - 1) * x + curmax2;
				}
				if (tmp1[i] == '0' || tmp1[i] != '0' && llabs(t1 - t2) < llabs(curbest1 - curbest2)) {
					curbest1 = t1;
					curbest2 = t2;
				}
				if (tmp1[i] != '9') {
					t1 = (tmp1[i] - '0') * x + curmax1;
					t2 = (tmp1[i] - '0' + 1) * x + curmin2;
					if (llabs(t1 - t2) < llabs(curbest1 - curbest2)) {
						curbest1 = t1;
						curbest2 = t2;
					}
				}
				curmin1 += (tmp1[i] - '0') * x;
				curmax1 += (tmp1[i] - '0') * x;
				curmax2 += 9 * x;
			}
			else if (tmp1[i] == '?' && tmp2[i] != '?') {
				long long t1 = (tmp2[i] - '0') * x + curbest1;
				long long t2 = (tmp2[i] - '0') * x + curbest2;
				if (tmp2[i] != '0') {
					curbest1 = (tmp2[i] - '0' - 1) * x + curmax1;
					curbest2 = (tmp2[i] - '0') * x + curmin2;
				}
				if (tmp2[i] == '0' || tmp2[i] != '0' && llabs(t1 - t2) < llabs(curbest1 - curbest2)) {
					curbest1 = t1;
					curbest2 = t2;
				}
				if (tmp2[i] != '9') {
					t1 = (tmp2[i] - '0' + 1) * x + curmin1;
					t2 = (tmp2[i] - '0') * x + curmax2;
					if (llabs(t1 - t2) < llabs(curbest1 - curbest2)) {
						curbest1 = t1;
						curbest2 = t2;
					}
				}
				curmax1 += 9 * x;
				curmin2 += (tmp2[i] - '0') * x;
				curmax2 += (tmp2[i] - '0') * x;
			}
			else {
				long long t1 = curmax1;
				long long t2 = x + curmin2;
				if (llabs(t1 - t2) < llabs(curbest1 - curbest2)) {
					curbest1 = t1;
					curbest2 = t2;
				}
				t1 = x + curmin1;
				t2 = curmax2;
				if (llabs(t1 - t2) < llabs(curbest1 - curbest2)) {
					curbest1 = t1;
					curbest2 = t2;
				}
				curmax1 += 9 * x;
				curmax2 += 9 * x;
			}
			x *= 10;
		}
		vector<int> ans1(n, 0), ans2(n, 0);
		for (int i = n - 1; i >= 0; --i) {
			ans1[i] = curbest1 % 10;
			ans2[i] = curbest2 % 10;
			curbest1 /= 10;
			curbest2 /= 10;
		}
		fprintf(fout, "Case #%d: ", iii + 1);
		for (int i = 0; i < n; ++i) fprintf(fout, "%d", ans1[i]);
		fprintf(fout, " ");
		for (int i = 0; i < n; ++i) fprintf(fout, "%d", ans2[i]);
		fprintf(fout, "\n");
	}
	fclose(fp);
	fclose(fout);
	return 0;
}