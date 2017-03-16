#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char s[1010];
int T, n, ans;

int main()
{
	scanf("%d", &T);
	for (int nCase = 1; nCase <= T; ++nCase) {
		scanf("%d%s", &n, s);
		ans = 0;
		int sum = 0;
		for (int i = 0; i <= n; ++i) {
			ans = max(ans, i - sum);
			sum += s[i] - '0';
		}
		printf("Case #%d: %d\n", nCase, ans);
	}
	return 0;
}
