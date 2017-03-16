#include <cstdio>
#include <algorithm>

using namespace std;

int T, t;
int i;
int ct, ans;
int sm;

char str[1000 + 5];

int main() {
	scanf("%d", &T);
	for(t = 1; t <= T; ++t) {
		scanf("%d", &sm);
		scanf("%s", str);
		ct = 0;
		ans = 0;
		for(i = 0; str[i]; ++i) {
			str[i] -= '0';
			ans += max(0, i - ct);
			ct = max(ct, i) + str[i];
		}
		printf("Case #%d: %d\n", t, ans);
	}
}
