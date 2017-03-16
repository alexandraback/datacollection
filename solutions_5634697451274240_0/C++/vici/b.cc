#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define Rep(i, n) for (int i = 1; i <= (n); ++i)
#define clr(x, a) memset(x, (a), sizeof x)
using namespace std;
typedef long long ll;
char s[1010];
int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("b-ans-small", "w", stdout);
	int T, ca = 1; scanf("%d", &T);
	while (T--) {
		scanf(" %s", s);
		int ans = 0;
		for (int i = strlen(s) - 1; i >= 0; --i) {
			if (s[i] == '-') {
				++ans;
				for (int j = i - 1; j >= 0; --j) {
					if (s[j] == '+') s[j] = '-';
					else s[j] = '+';
				}
			}
		}
		printf("Case #%d: %d\n", ca++, ans);
	}
	return 0;
}

