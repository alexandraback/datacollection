#include <bits/stdc++.h>

using namespace std;

const int maxn = 1024;

int N;
int A[maxn];

int main() {
	int T;
	scanf("%d", &T);
	for (int _ = 1;_ <= T;_ ++) {
		printf("Case #%d: ", _);
		scanf("%d", &N);
		for (int i = 0;i < N;i++) {
			scanf("%d", A + i);
		}
		int ans = 1024;
		for (int c = 1;c <= 1024;c++) {
			int pans = c;
			for (int i = 0;i < N;i++) {
				pans += (A[i] - 1) / c;
			}
			ans = min(ans, pans);
		}
		printf("%d\n", ans);
	}
	return 0;
}
