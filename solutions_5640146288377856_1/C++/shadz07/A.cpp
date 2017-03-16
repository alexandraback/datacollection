#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <map>
#include <bitset>
#include <utility>
#include <algorithm>

#define REP(a, b) for (int a = 0; a < b; ++a)
#define FORU(a, b, c) for (int a = b; a <= c; ++a)
#define FORD(a, b, c) for (int a = b; a >= c --a)
#define fi first
#define se second
#define pb push_back
#define mp make_pair

using namespace std;

int main() {
	int r, c, w, T;

	scanf("%d", &T);

	FORU(tc, 1, T) {
		scanf("%d %d %d", &r, &c, &w);
		int ans = 0;
		int ansTemp = 0;
		int cTemp = c;

		while (cTemp > (2 * w - 1)) {
			cTemp -= w;
			++ansTemp;
		}

		++ansTemp;

		ans = ansTemp * (r - 1) + w;
		c -= w;

		while (c > 0) {
			++ans;
			c -= w;
		}

		printf("Case #%d: %d\n", tc, ans);
	}

	return 0;
}
