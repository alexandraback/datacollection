#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>

using namespace std;

#define MAXNODE 1155077
#define INF 0x3f3f3f3f

int child[MAXNODE][26];
int dp[55][MAXNODE];
bool end[MAXNODE];
char s[100];

int best;
int root = 0;
int totNode = 0;

void insert(char *s, int p) {
	for(int i = 0; s[i]; ++i) {
		int sub = s[i] - 'a';
		if(child[p][sub] == 0)
			child[p][sub] = ++totNode;
		p = child[p][sub];
	}
	end[p] = true;
}

void go(int len, int pos, int step) {
	if(step == 0) {
		dp[len][pos] = min(dp[len][pos], best);
		return;
	}
	int next = s[len + 1] - 'a';
	if(child[pos][next] != 0)
		go(len + 1, child[pos][next], step - 1);
	if(end[pos])
		go(len, 0, step);
}

int main() {
	freopen("Dictionary.txt", "r", stdin);
	while(scanf("%s", s) != EOF && s[0] != '2') {
		insert(s, root);
	}
//	freopen("input.txt", "r", stdin);
	int T;
//	scanf("%d", &T);
//	cout << T << endl;
	T = 20;
	freopen("out.out", "w", stdout);
	for(int cas = 1; cas <= T; ++cas) {
		scanf("%s", s + 1);
		memset(dp, INF, sizeof(dp));
		int l = strlen(s + 1);
		dp[0][0] = 0;
		for(int i = 0; i < l; ++i)
			for(int j = 0; j < MAXNODE; ++j) if(dp[i][j] != INF) {
				best = dp[i][j];
				go(i, j, 1);
				best = dp[i][j] + 1;
				for(int k = 0; k < 26; ++k) {
					if(child[j][k] != 0)
						go(i + 1, child[j][k], min(4, l - i - 1));
					if(end[j] && child[0][k] != 0)
						go(i + 1, child[0][k], min(4, l - i - 1));
				}
			}
		int res = INF;
		for(int i = 0; i < MAXNODE; ++i)
			if(end[i]) res = min(res, dp[l][i]);
		printf("Case #%d: %d\n", cas, res);
	}
	return 0;
}
