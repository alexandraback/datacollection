#include"stdio.h"
#include"stdlib.h"
#include"math.h"
#include"algorithm"
using namespace std;
int t, T;
char s[1005];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.txt", "w", stdout);
	scanf("%d", &T);
	while (t < T) {
		int ans = 0, n, sum = 0;
		scanf("%d%s", &n, s);
		for (int i = 0; i <= n; i++) {
			if (sum < i) {
				ans += (i - sum);
				sum = i;
			}
			sum += (s[i] - '0');
		}
		printf("Case #%d: %d\n", ++t, ans);
	}
}
