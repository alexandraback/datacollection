#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <cstring>

int main() {
	unsigned long long t;
	scanf("%llu", &t);
	for(unsigned long long i = 0; i < t; i++) {
		char s[1000000];
		scanf(" %s", s);
		unsigned long long n;
		scanf("%llu", &n);
		unsigned long long l = strlen(s);
		unsigned long long spolgloski = 0;
		unsigned long long res = 0;
		unsigned long long p1 = 0, p2 = 0;
		bool b = false;
		for(unsigned long long j = 0; j < l; j++) {
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
		printf("Case #%llu: %llu\n", i + 1, res);
	}
	return 0;
}
