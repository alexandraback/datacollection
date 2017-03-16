#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
int T;
int smax;
char s[1020];
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%d%s", &smax, s);
		int ans = 0, sum = 0;
		for (int j = 0; j <= smax; j++) {
			if (s[j] != '0') if (j - sum > ans) ans = j - sum;
			sum += s[j] - '0';
		}
		printf("Case #%d: %d\n", i, ans);
	}		
	return 0;
}		
