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

int a[510];
map <ll, ll> M;

void solve() {
	cerr << "!" << endl;
	M.clear();
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}
	sort(a, a + n);
	while (1) {
		ll msk = 0;
		for (int i = 0; i < 4; ++i) {
			msk = (msk << 10) ^ rand();
		}
		ll sum = 0;
		for (int j = 0; j < 60; ++j) {
			if ((msk >> j) & 1) {
				sum += a[j];
			}
		}
		if (M.find(sum) != M.end()) {
			ll Q = M[sum];
			if (Q == msk) continue;
			ll T = 0;
			for (int j = 0; j < 60; ++j) {
				if ((msk >> j) & 1) {
					T += a[j];
					printf("%lld ", a[j]);
				}
			}
			puts("");
			for (int j = 0; j < 60; ++j) {
				if ((Q >> j) & 1) {
					T -= a[j];
					printf("%lld ", a[j]);
				}
			}
			puts("");			
			cerr << T << endl;
			return;
		}
		M[sum] = msk;
	}
}

int main() {
#ifdef _DBG1
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	scanf("%d", &n);
	srand(789214);
	for (int i = 0; i < n; ++i) {
		printf("Case #%d:\n", i + 1);
		solve();
	}
	return 0;
}