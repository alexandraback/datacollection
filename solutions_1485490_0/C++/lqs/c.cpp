#include <stdio.h>
#include <memory.h>
#include <set>

using namespace std;

#define FOR(i, n) for (int i = 0; i < n; i++)
#define MIN(x, y) ((x) < (y) ? (x) : (y))


long long a[100], b[100];
int A[100], B[100];
int N, M;
long long ans = 0;
long long dfs(int p, int q) {
	long long ret = 0;
	if (p < N && q < M) {
		if (A[p] == B[q]) {
			if (a[p] > b[q]) {
				long long x = b[q];
				a[p] -= x;
				b[q] = 0;
				long long cur = x + dfs(p, q + 1);
				a[p] += x;
				b[q] = x;
				if (cur > ret)
					ret = cur;
			}
			else {
				long long x = a[p];
				a[p] = 0;
				b[q] -= x;
				long long cur = x + dfs(p + 1, q);
				a[p] = x;
				b[q] += x;
				if (cur > ret)
					ret = cur;
			}
		}
		else {
			long long cur;
			cur = dfs(p + 1, q); if (cur > ret) ret = cur;
			cur = dfs(p, q + 1); if (cur > ret) ret = cur;
		}
	}
	//printf("dfs(%d, %d) = %lld\n", p, q, ret);
	return ret;
	
}

int main() {
	int T;
	scanf("%d", &T);
	FOR(ca, T) {

		scanf("%d%d", &N, &M);
		
		
		FOR(i, N)
			scanf("%lld%d", &a[i], &A[i]);
		FOR(i, M)
			scanf("%lld%d", &b[i], &B[i]);
		
		ans = dfs(0, 0);
		printf("Case #%d: %lld\n", ca+1, ans);
		
	}
	
	
}
