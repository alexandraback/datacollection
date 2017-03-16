#include<iostream>
#include<cstdio>
#include <cstring>
using namespace std;

char s[10100];
char st[100000];
bool mark[100000];

int main() {
	freopen("A.in", "r", stdin);
	freopen("A.txt", "w", stdout);

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		memset(mark, false, sizeof(mark));
		scanf("%s", &s);
		int len = strlen(s);
		int tt = -1;
		for (int i = 0; i < len; i++)
			if (tt == -1 || st[tt] <= s[i]) {
				tt++;
				st[tt] = s[i];
				mark[i] = true;
			}
		printf("Case #%d: ", t);

		for (int i = len - 1; i >= 0; i--)
			if (mark[i])
				printf("%c", s[i]);

		for (int i = 0; i < len; i++)
			if (!mark[i])
				printf("%c", s[i]);

		printf("\n");
	}
}
