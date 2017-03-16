#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

#define FOR(it, c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define SZ(c) ((int)(c).size())

int cs;
int A, n, a[1005];
void solve() {
	scanf("%d%d", &A, &n);
	for(int i=0;i<n;i++) scanf("%d", &a[i]);
	sort(a, a+n);
	int best = n, cur = 0;
	for(int i=0;i<n;i++) {
		if(A==1) break;
		while(A <= a[i]) cur++, A += A-1;
		A += a[i];
		best = min(best, n-1-i+cur);
	}
	printf("Case #%d: %d\n", cs, best);
	fprintf(stderr, "Case #%d: %d\n", cs, best);
}
int main(void) {
	int T;
	scanf("%d", &T);
	for(cs=1;cs<=T;cs++) solve();
	return 0;
}
