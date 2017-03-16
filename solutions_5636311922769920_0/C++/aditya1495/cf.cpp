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

int main() {
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T, K, C;
	LL S;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		printf("Case #%d: ", t);
		cin >> K >> C >> S;
		int req = K / 2 + (K & 1);
		if (S == K) {
			for (int i = 1; i <= K; ++i) {
				printf("%d", i);
				if (i < K) printf(" ");
			}
			if (t != T) puts("");
			continue;
		}
		if (C == 1 || S < req) {
			printf("IMPOSSIBLE");
		} else {
			LL ds = 1;
			for (int i = 0; i + 1 < C; ++i) {
				ds *= K;
			}
			for (int i = 1; i <= req; ++i) {
				cout << (ds * (i - 1) + min(2 * i, K));
				if (i < req) printf(" ");
			}
		}
		if (t != T) puts("");
	}
	return 0;
}