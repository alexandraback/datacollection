#include <cstdio>

using namespace std;

const int MAXN = (int) 1e3;

char S[MAXN + 10];

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	int T, kase = 0;
	scanf("%d", &T);
	while (T--) {
		int Smax;
		scanf("%d", &Smax);
		scanf("%s", S);
		int ans = 0;
		int cnt = S[0] - '0';
		for (int i = 1; i <= Smax; i++)
			if (S[i] - '0') {
				if (cnt < i) {
					ans += i - cnt;
					cnt += i - cnt;
				}
				cnt += S[i] - '0';
			}
		printf("Case #%d: %d\n", ++kase, ans);
	}
	return 0;
}