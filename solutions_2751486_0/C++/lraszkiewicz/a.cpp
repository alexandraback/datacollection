#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

int main() {
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++) {
		char s[1000000];
		scanf(" %s", s);
		int n;
		scanf("%d", &n);
		int l = strlen(s);
		int spolgloski = 0;
		int res = 0;
		int p1 = 0, p2 = 0;
		bool b = false;
		for(int j = 0; j < l; j++) {
			if(s[j] != 'a' && s[j] != 'e' && s[j] != 'i' && s[j] != 'o' && s[j] != 'u') {
				spolgloski++;
				if(spolgloski == 1)
					p1 = j;
				if(spolgloski > n) {
					p2 = p1 + 1;
					p1++;
				}
			}
			else {
				spolgloski = 0;
				if(b) {
					p2 = p1 + 1;
					b = false;
				}
			}
			if(spolgloski >= n) {
				res += (j - n + 1 - p2) + (l - j - 1) + (j - n + 1 - p2) * (l - j - 1) + 1;
				b = true;
			}
		}
		printf("Case #%d: %d\n", i + 1, res);
	}
	return 0;
}
