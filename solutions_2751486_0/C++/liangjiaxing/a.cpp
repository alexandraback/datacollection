#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

char s[1000100];
int b[140];

int main() {
	int T;
	freopen("A-small-attempt0 (6).in", "r", stdin);
	freopen("w.txt", "w", stdout); 
	string vow = "aeiou";
	for (int i = 0; i < vow.size(); i++) {
		b[vow[i]] = 1;
	}
	scanf("%d", &T);
	for (int re = 1; re <= T; re++) {
		int k;
		scanf("%s%d", s, &k);
		int n = strlen(s);
		long long ans = 0;
		int cnt = 0, last = -1;
		for (int i = 0; i < n; i++) {
			if (b[s[i]] == 0) {
				cnt++;
				if (cnt >= k) {
					// ans += i - k + 2;
					last = i - k + 1;
				}
			} else {
				cnt = 0;
			}
			if (last != -1) {
				ans += last + 1;
			}
			// printf("ans[%d] = %lld\n", i, ans);
		}
		printf("Case #%d: %lld\n", re, ans);
	}
}
