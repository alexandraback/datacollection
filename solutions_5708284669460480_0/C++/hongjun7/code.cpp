#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int K, L, S, M;
char A[10], B[10], C[10];
double res, r;
void go(int x) {
	if (x == S + 1) {
		int cnt = 0;
		for (int i = L; i <= S; i++) {
			int p = 1, ok = 1;
			for (int j = i - L + 1; j <= i; j++, p++) if (B[p] != C[j]) { ok = 0; break; }
			if (ok) cnt++;
		}
		if (cnt > M) M = cnt;
		return;
	}
	for (int i = 1; i <= K; i++) {
		C[x] = A[i];
		go(x + 1);
	}
}
void go2(int x) {
	if (x == S + 1) {
		int cnt = 0;
		for (int i = L; i <= S; i++) {
			int p = 1, ok = 1;
			for (int j = i - L + 1; j <= i; j++, p++) if (B[p] != C[j]) { ok = 0; break; }
			if (ok) cnt++;
		}
		res += (double)(M - cnt);
		return;
	}
	for (int i = 1; i <= K; i++) {
		C[x] = A[i];
		go2(x + 1);
	}
}
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int T, runs = 1;
	for (scanf("%d", &T); T--;) {
		scanf("%d%d%d", &K, &L, &S);
		scanf("%s%s", A + 1, B + 1);
		M = 0;
		res = 0;
		go(1);
		go2(1);
		for (int i = 1; i <= S; i++) res /= (double)(K);
		printf("Case #%d: %.7lf\n", runs++, res);
	}
}