#include <cstdio>
#include <set>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <cstring>
#include <vector>

using namespace std;

typedef long long LL;

const int MAXN = 100+5;
const int MAXC = 1e6 + 5;

int A, n;
int a[MAXN];

int memo[MAXN][MAXN];

int f(int i, int changes) {
	if(changes < 0) {
		return -2;
	}
	if(i == n) {
		return A;
	}

	int &res = memo[i][changes];
	if(res != -1) return res;

	res = f(i+1, changes-1); //remove
	for(int j = 0; j <= changes; j++) {
		if(res > MAXC) break;
		int base = f(i+1, changes-j);
		for(int k = 0; k < j; k++) {
			base += base-1;
		}
		if(base > a[i]) {
			res = max(res, base + a[i]);
		}
	}

	return min(res, MAXC);
}

int solve() {
	scanf("%d %d", &A, &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	sort(a, a+n);
	reverse(a, a+n);

	memset(memo, -1, sizeof(memo));

	for(int i = 0; i <= n; i++) {
		if(f(0, i) != -2) return i;
	}
	assert(false);
}

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 1; i <= t; i++) {
		printf("Case #%d: %d\n", i, solve());
	}
}