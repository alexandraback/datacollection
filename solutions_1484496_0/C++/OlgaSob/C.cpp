#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

#pragma comment(linker, "/STACK:16000000")

typedef long long ll;
typedef pair<int, int> pii;

const int INF = 1e9;
const double EPS = 1e-8;
const double PI = 2 * acos(0.);

int ans[2000500];
int a[100];

void solve() {
	memset(ans, 0xff, sizeof(ans));
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
	}
	for (int msk = 1; msk < (1 << n); ++msk) {
		int sum = 0;
		for (int j = 0; j < n; ++j) {
			if ((msk >> j) & 1) {
				sum += a[j];
			}
		}
		if (ans[sum] != -1) {
			for (int j = 0; j < n; ++j) {
				if ((msk >> j) & 1) {
					printf("%d ", a[j]);
				}
			}
			puts("");
			for (int j = 0; j < n; ++j) {
				if ((ans[sum] >> j) & 1) {
					printf("%d ", a[j]);
				}
			}
			puts("");
			
			return;
		}
		ans[sum] = msk;
	}
	printf("Impossible\n");
}

int main() {
#ifdef _DBG1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return 0;
}