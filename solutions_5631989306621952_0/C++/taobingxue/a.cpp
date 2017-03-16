#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Times;
char s[1005], ans[1005];
bool f[1005];

int main() {
	freopen("a.in", "r", stdin);
	freopen("a.out", "w", stdout);

	scanf("%d", &Times);
	gets(s);
	for (int times = 1; times <= Times; ++times) {
		printf("Case #%d: ", times);
		gets(s);
		if (s[0] == '\0') {
			printf("\n");
			continue;
		}
		
		int l = strlen(s);
		int ph = 0, pe = l - 1;
		char mm = s[0];
		f[0] = true;
		for (int i = 1; i < l; ++i) {
			if (s[i] < mm) {
				f[i] = false;
				continue;
			} else f[i] = true;
			if (s[i] > mm) {
				mm = s[i];
			}
		}
		
		for (int i = l-1; i >= 0; i--) {
			if (!f[i]) ans[pe--] = s[i];
			else ans[ph++] = s[i];
		}
		for (int i = 0; i < l; ++i)
			printf("%c", ans[i]);
		printf("\n");
	}
	
	return 0;
}
