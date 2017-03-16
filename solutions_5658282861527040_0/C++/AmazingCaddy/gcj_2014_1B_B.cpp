#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
typedef long long ll;

const int maxn = 103;
const int inf = 0x3f3f3f3f;

int a, b, k;

int solve () {
	int sum = 0;
	for (int i = 0; i < a; i ++) {
		for (int j = 0; j < b; j ++) {
			if ((i & j) < k) {
				sum ++;
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[]) {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
	int cas;
	scanf ("%d", &cas);
	for (int t = 1; t <= cas; t ++) {
		scanf ("%d%d%d", &a, &b, &k);
		int ans = solve();
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}