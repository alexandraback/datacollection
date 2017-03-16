#include <bits/stdc++.h>

using namespace std;

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef long long LL;
typedef vector<VI> VVI;

#define all(x) (x).begin(), (x).end()

const LL inf = numeric_limits<LL>::min() / 2;
const int maxn = 1000005;
const int mod = 1e9 + 7;
const int END = 1023;

int GetMask(int x) {
	if (!x) return 1;
	int res = 0;
	while (x > 0) {
		int v = x % 10; x /= 10;
		res |= (1 << v);
	}
	return res;
}

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T, N;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		int mask = 0;
		scanf("%d", &N);
		if (!N) {
			puts("INSOMNIA");
		} else {
			int res = 0;
			for (int i = 1; mask != END; ++i) {
				res += N;
				mask |= GetMask(res);
			}
			printf("%d", res);
			if (t != T) puts("");
		}
	}
	return 0;
}