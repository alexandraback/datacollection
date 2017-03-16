#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <set>
#include <map>
#define fi first
#define se second
using namespace std;
typedef long long LL;
typedef pair<int,int> PII;
// head
const int N = 2005;
char a[15][15] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

map<char, int> ma;
char s[N];
int ans[15];

void gao(int x, char ch) {
	int n = ma[ch];
	for (int i = 0; a[x][i]; i++) {
		ma[a[x][i]] -= n;
	}
	ans[x] += n;
}

void solve() {
	gao(0, 'Z');
	gao(2, 'W');
	gao(4, 'U');
	gao(6, 'X');
	gao(1, 'O');
	gao(7, 'S');
	gao(8, 'G');
	gao(5, 'V');
	gao(3, 'H');
	gao(9, 'I');
}

int main() {
	freopen("out.txt", "w", stdout);
	int t, n, cas = 1;
	scanf("%d", &t);
	while (t--) {
		ma.clear();
		memset(ans, 0, sizeof ans);
		scanf("%s", s);
		n = strlen(s);
		for (int i = 0; i < n; i++) {
			ma[s[i]]++;
		}
		solve();
		printf("Case #%d: ", cas++);
		for (int i = 0; i < 10; i++) {
			while (ans[i]) {
				printf("%d", i);
				ans[i]--;
			}
		}
		puts("");
	}
	return 0;
}
