#include <iostream>
#include <cstdio>
using namespace std;

int f[200], g[200], T;
char s[200];

int main() {
	scanf("%d", &T);
	for (int TT = 1; TT <= T; TT++) {
		scanf("%s", s);
		int n = strlen(s);
		f[0] = (s[0] == '+')? 0:1;
		g[0] = (s[0] == '-')? 0:1;
		for (int i = 1; i < n; i++) {
			f[i] = (s[i] == '+')? f[i - 1] : (g[i - 1] + 1);
			g[i] = (s[i] == '-')? g[i - 1] : (f[i - 1] + 1);
		}
		printf("Case #%d: %d\n", TT, f[n - 1]);
	}

	return 0;
}