#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int R, C, W;

int main() {
	int T, tc=1, res;
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d %d", &R, &C, &W);
		res = (R-1) * (C/W);
		res += (C + W - 1) / W  + W - 1;
		printf("Case #%d: %d\n", tc++, res);
	}
	return 0;
}