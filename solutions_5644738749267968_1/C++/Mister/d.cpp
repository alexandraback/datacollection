#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <cassert>
#include <climits>
using namespace std;
double A[1005], B[1005];
int main() {
	int T;
	scanf("%d", &T);
	for (int cn = 1; cn <= T; ++cn) {
		int N, ans1 = 0, ans2 = 0;
		scanf("%d", &N);
		for (int i = 1; i <= N; ++i) scanf("%lf", &A[i]);
		for (int i = 1; i <= N; ++i) scanf("%lf", &B[i]);
		sort(A + 1, A + N + 1);
		sort(B + 1, B + N + 1);
		for (int w = 1; w <= N; ++w) {
			int cnt = 0;
			for (int i = 1; i <= w; ++i) {
				if (A[N - i + 1] >= B[w - i + 1]) ++cnt;
			}
			if (cnt == w) ans1 = max(ans1, w);
		}
		for (int i = 1; i <= N; ++i) {
			bool found = false;
			for (int j = 1; j <= N; ++j)
				if (B[j] > A[i]) {
					B[j] = -1;
					found = true;
					break;
				}
			if (!found) ++ans2;
		}
		printf("Case #%d: %d %d\n", cn, ans1, ans2);
	}
}

