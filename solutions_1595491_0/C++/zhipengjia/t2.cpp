
#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i ++) {
		int N, S, p, t[100];
		scanf("%d%d%d", &N, &S, &p);
		for (int j = 0; j < N; j ++) scanf("%d", &t[j]);
		if (p == 0) {
			printf("Case #%d: %d\n", i + 1, N);
			continue;
		}
		int ans = 0, cnt = 0;
		for (int j = 0; j < N; j ++) {
			if (t[j] == 0) continue;
			int least;
			if (t[j] % 3 == 0) least = t[j] / 3; else least = t[j] / 3 + 1;
			if (least >= p) ans ++;
			if (least == p - 1 && t[j] % 3 != 1) cnt ++;
		}
		ans += min(cnt, S);
		printf("Case #%d: %d\n", i + 1, ans);
	}
	
	return 0;
}