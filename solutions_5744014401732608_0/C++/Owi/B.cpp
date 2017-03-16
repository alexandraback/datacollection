#include <iostream>
#include <stdio.h>
#include <memory.h>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

typedef vector<vector<int> > Mat;

Mat multi(Mat &a, Mat &b) {
	int n = a.size();
	Mat c(n, vector<int>(n, 0));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
	return c;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	cin >> T;
	for (int caseID = 1; caseID <= T; ++caseID) {
		int B, M;
		cin >> B >> M;
		int n = B * (B - 1) / 2;
		Mat res;
		bool yes = false;
		for (int q = 0; q < (1 << n); ++q) {
			Mat x(B, vector<int>(B, 0));
			for (int i = 0, p = 0; i < B - 1; ++i) {
				for (int j = i + 1; j < B; ++j) {
					if ((q >> p) & 1) x[i][j] = 1;
					++p;
				}
			}
			Mat a = x;
			int sum = a[0][B - 1];
			for (int i = 2; i <= B; ++i) {
				a = multi(a, x);
				sum += a[0][B - 1];
			}
			if (sum == M) {
				res = x;
				yes = true;
				break;
			}
		}
		printf("Case #%d: ", caseID);
		if (yes) {
			printf("POSSIBLE\n");
			for (int i = 0; i < B; ++i) {
				for (int j = 0; j < B; ++j) {
					printf("%d", res[i][j]);
				}
				puts("");
			}
		}
		else {
			printf("IMPOSSIBLE\n");
		}
	}
}