#include <cstdio>
#include <algorithm>

using namespace std;

int T;
long long a[105];
int A[105];
long long b[105];
int B[105];
int N;
int M;

long long lcs(int x, int y) {
	if(x >= N || y >= M) return 0;
	if(A[x] == B[y]) {
		if(a[x] > b[y]) {
			a[x] -= b[y];
			long long r = b[y] + lcs(x, y + 1);
			a[x] += b[y];
			return r;
		}else if(a[x] < b[y]) {
			b[y] -= a[x];
			long long r = a[x] + lcs(x + 1, y);
			b[y] += a[x];
			return r;
		}else {
			return a[x] + lcs(x + 1, y + 1);
		}
	}
	else return max<long long>(lcs(x + 1, y), lcs(x, y + 1));
}

int main(void) {
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
		scanf("%d%d", &N, &M);
		for(int i = 0; i < N; i++) scanf("%I64d%d", &a[i], &A[i]);
		for(int i = 0; i < M; i++) scanf("%I64d%d", &b[i], &B[i]);
		printf("Case #%d: %I64d\n", t, lcs(0, 0));
	}
	return 0;
}
