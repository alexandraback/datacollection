#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>

using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int maxn = 1000100;
int a[maxn];

void solve() {
	int cur;
	int n;
	scanf("%d %d", &cur, &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d", a + i);
	}
	if(cur == 1) {
		printf("%d\n", n);
		return;
	}
	sort(a, a + n);
	int ans = n;
	for(int i = 0; i < n; ++i) {
		int r = 0;
		int sum = cur;
		for(int j = 0; j <= i; j++) {
			while(sum <= a[j]) {
				sum += sum - 1;
				++r;
			}
			sum += a[j];
		}
		ans = min(ans, n - 1 - i + r);
	}
	printf("%d\n", ans);
}

int main(int argc, char **argv) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);
	int tt;
	scanf("%d", &tt);
	for(int t = 0; t < tt; ++t) {
		printf("Case #%d: ", t + 1);
		solve();
	}
	return 0;
}
