#include <bits/stdc++.h>
#define fo(i,a,b) for (int i = (a); i < (b); i++)

int n, nn;
char stack[123];
int main() {
	freopen("b.in", "r", stdin);
	freopen("b.out", "w", stdout);

	scanf("%d", &n);
	fo(i,0,n) {
		scanf("%s", stack);
		nn = strlen(stack);
		int ans = 0;
		char cur = '+';
		for (int j = nn-1; j >= 0; j--) {
			if (stack[j] != cur) {
				cur = stack[j];
				ans++;
			}
		}
		printf("Case #%d: %d\n", i+1, ans);
	}

	return 0;
}