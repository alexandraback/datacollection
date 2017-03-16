/*
six (x) two (w) zero(z) four(u) eight(g)

seven(s)

five(v)

one(o)

nine(n)

three(t)

*/

#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>

using namespace std;

string out = "6204875193";
string tar = "XWZUGSVONT";
string sub[] = { "SIX", "TWO", "ZERO", "FOUR", "EIGHT", "SEVEN", "FIVE", "ONE", "NINE", "THREE" };
int dv[] = { 1, 1, 1, 1, 1, 1, 1, 1, 2, 1 };

char str[2003];

int main() {

	freopen("A-small-attempt0.in", "r", stdin);
	freopen("A-small-attempt0.out", "w", stdout);

	int t;
	scanf("%d", &t);

	for (int tc = 1; tc <= t; tc++) {

		scanf("%s", str);

		int s = strlen(str);
		int c['Z' + 3] = { 0 };

		for (int i = 0; i < s; i++)c[str[i]]++;

		string ans;

		for (int i = 0; i < out.size(); i++) {
			if (c[tar[i]] / dv[i]) {
				int m = c[tar[i]] / dv[i];
				for (int j = 1; j <= m; j++)ans += out[i];
				for (int j = 0; j < sub[i].size(); j++) {
					c[sub[i][j]] -= m;
				}
			}
		}

		sort(ans.begin(), ans.end());

		printf("Case #%d: %s\n", tc, ans.c_str());

	}

}