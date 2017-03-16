#include <cstdio>
#include <algorithm>
using namespace std;

char S[1100];
int l, ans, sum, T;

int main() {
	scanf("%d", &T);
	for (int k = 1; k <= T; k++) {
		scanf("%d", &l);
		scanf("%s", S);
		ans = 0;
		sum = 0;
		for (int i = 0; i <= l; i++) {
			ans = max(ans, i - sum);
			sum += S[i] - '0';
		}
		printf("Case #%d: %d\n", k, ans);
	}
}
