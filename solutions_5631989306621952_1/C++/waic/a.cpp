#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1010;
char s[MAXN];
bool vis[MAXN];
int main() {
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++) {
		scanf("%s", s);
		printf("Case #%d: ", tt);
		memset(vis, 0, sizeof(vis));
		int len = strlen(s);
		char Max = s[0];
		for (int i = 0; i < len; i++) 
			if (s[i] >= Max) {
				vis[i] = true;
				Max = s[i];
			}
		for (int i = len - 1; i >= 0; i--) 
			if (vis[i]) putchar(s[i]);
		for (int i = 0; i < len; i++) 
			if (!vis[i]) putchar(s[i]);
		puts("");
	}
	return 0;
}

