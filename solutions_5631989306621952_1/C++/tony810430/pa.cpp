#include <stdio.h>
#include <string.h>


int T;
char s[2000];


void solve(int L, int R)
{
	if (L >= R)
		return;
	int idx = -1;
	for (int i = L; i < R; i++) {
		if (idx == -1 || s[idx] <= s[i])
			idx = i;
	}

	printf("%c", s[idx]);
	solve(L, idx);
	for (int i = idx+1; i < R; i++)
		printf("%c", s[i]);
}

int main()
{
	scanf(" %d", &T);
	for (int cas = 1; cas <= T; cas++) {
		printf("Case #%d: ", cas);
		scanf(" %s", s);
		solve(0, strlen(s));
		puts("");
	}

	return 0;
}