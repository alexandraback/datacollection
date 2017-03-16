#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;
int t;
char s[100020];
int main() {
	scanf("%d", &t);
	for (int tt = 1; tt <= t; tt++) {
		scanf("%s", s);
		int l = strlen(s), c = 0;
		s[l++] = '+';
		for (int i = 1; i < l; i++) {
			if (s[i - 1] != s[i]) {
				c++;
			}
		}
		printf("Case #%d: %d\n", tt, c);
	}
	return 0;
}
