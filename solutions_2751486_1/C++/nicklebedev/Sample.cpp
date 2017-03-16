#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

int n, tests, k;
char str[2000000];

bool isConsonant(char c) {
	if (c == 'a' ||
		c == 'e' ||
		c == 'o' ||
		c == 'i' ||
		c == 'u') {
		return false;
	}

	return true;
}

int main() {
	freopen("A-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &tests);

	for (int t = 1; t <= tests; t++) {
		scanf("%s", str);
		scanf("%d", &k);

		ll ans = 0;
		int len = strlen(str);
		int lastValid = -1;
		int curr = 0;
		for (int i = 0; i < len; i++) {
			if (isConsonant(str[i])) {
				curr++;
			}
			else {
				curr = 0;
			}

			if (curr >= k) {
				ans = ans + (i - k + 2);
				lastValid = i - k + 2;
			}
			else {
				if (lastValid != -1) {
					ans = ans + lastValid;
				}
			}
		}

		printf("Case #%d: %I64d\n", t, ans); 
	}
	
	return 0;
}
