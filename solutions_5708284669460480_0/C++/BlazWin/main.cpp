#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

#define ll long long

char keys[10];
char out[10];
char res[10];
int n, m, k, mmax, nw, ko;

void doit(int i) {
	if (i == k) {
		ko++;
		// for (int j = 0; j < k; j++) {
		// 	printf("%c", res[j]);
		// }
		// printf("\n");
		int curm = 0;
		for (int j = 0; j < k - m + 1; j++) {
			bool ye = true;
			for (int jj = j; jj < j + m; jj++) {
				if (res[jj] != out[jj - j]) {
					ye = false;
					break;
				}
			}
			if (ye) {
				curm++;
				nw++;
			}
		}
		mmax = max(mmax, curm);
		return;
	}
	for (int ii = 0; ii < n; ii++) {
		res[i] = keys[ii];
		doit(i + 1);
		res[i] = ' ';
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for (int jk = 0; jk < t; jk++) {
		scanf("%d%d%d\n", &n, &m, &k);
		mmax = 0, nw = 0, ko = 0;
		gets(keys);
		gets(out);
		doit(0);
		// cout << mmax << " " << nw << " " << ko << endl;
		printf("Case #%d: %.8lf\n", jk + 1, mmax - nw * 1.0 / ko);
	}

	return 0;
}
