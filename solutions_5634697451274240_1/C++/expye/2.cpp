#include <cstdio>
#include <cstring>
using namespace std;
int T;
int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		printf("Case #%d: ", i);
		char s[102];
		scanf("%s", s);
		int l = strlen(s);
		int ans = 1;
		for (int i = 1; i < l; i++) {
			if (s[i] != s[i - 1]) ans++;
		}
		if (s[l - 1] == '+') ans--;
		printf("%d\n", ans);
	}
	return 0;
}