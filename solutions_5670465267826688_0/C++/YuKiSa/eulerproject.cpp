#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

// 1=1, i=2, j=3, k=4
int calc[5][5] = { 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 0, 2, -1, 4, -3, 0, 3, -4, -1, 2, 0, 4, 3, -2, -1 };

int f(int a, int b) {
	int signa=1, signb=1;
	if (a < 0) signa = -1;
	if (b < 0) signb = -1;
	return signa*signb*calc[a / signa][b / signb];
}

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output2.txt", "w", stdout);

	int t; scanf("%d", &t);
	for (int k = 0; k < t; k++) {
		long long int x, l;
		char s[10005];
		scanf("%lld %lld\n", &x, &l);
		scanf("%s", s);
		int now = 1;
		int ifound = 0, jfound = 0;
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < x; j++) {
				int next = s[j]-'i'+2;
				now = f(now, next);
				if (ifound == 1 && now == 4) jfound = 1;
				if (now == 2) ifound = 1;
			}
		}
		printf("Case #%d: ", k + 1);
		if (now == -1 && ifound == 1 && jfound == 1) printf("YES\n");
		else printf("NO\n");
	}

	return 0;
}