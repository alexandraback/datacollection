//============================================================================
// Name        : 2016_gcj_1b_a.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define RUN

char dig[10][30] = {
		"ZERO",
		"ONE",
		"TWO",
		"THREE",
		"FOUR",
		"FIVE",
		"SIX",
		"SEVEN",
		"EIGHT",
		"NINE"
};
char ls[15] = "ZGXSVUIHWN";
int ld[15] = {0, 8, 6, 7, 5, 4, 9, 3, 2, 1};
int cnt[300], ans[10];
char s[10000];

void solve() {
	int cur;
	for (int i = 0; i < 10; i++) {
		cur = ans[ld[i]] = cnt[(int)ls[i]];
		for (int j = 0; dig[ld[i]][j]; j++)
			cnt[(int)dig[ld[i]][j]] -= cur;
	}
	return;
}

int main() {

#ifdef RUN
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	for (int cas = 1; cas <= t; cas++) {
		scanf("%s", s);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; s[i]; i++)
			cnt[(int)s[i]] += 1;
		memset(ans, 0, sizeof(ans));
		printf("Case #%d: ", cas);
		solve();
		for (int i = 0; i < 10; i++)
			for (int j = 0; j < ans[i]; j++)
				printf("%d", i);
		printf("\n");
	}
	return 0;
}
