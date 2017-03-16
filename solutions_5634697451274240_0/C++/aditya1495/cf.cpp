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
	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; ++t) {
		int res = 0;
		printf("Case #%d: ", t);
		string s;
		cin >> s; s += '+';
		for (int i = 1; i < s.size(); ++i) {
			if (s[i] != s[i - 1]) {
				res += 1;
			}
		}
		printf("%d", res);
		if (t != T) puts("");
	}
	return 0;
}