#include <bits/stdc++.h>
using namespace std;

int cnt[30];
int ans[10];

int o(char c) {
	return c-'A';
}

int main()
{
	int ntc;
	scanf("%d", &ntc);
	for (int itc = 1; itc <= ntc; ++itc) {
		string s;
		cin >> s;
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		for (int i = 0; i < (int)s.size(); ++i) {
			cnt[o(s[i])]++;
		}

		ans[0] = cnt[o('Z')];
		ans[2] = cnt[o('W')];
		ans[4] = cnt[o('U')];
		ans[6] = cnt[o('X')];
		ans[8] = cnt[o('G')];
		ans[7] = cnt[o('S')]-ans[6];
		ans[5] = cnt[o('V')]-ans[7];
		ans[9] = cnt[o('I')]-ans[5]-ans[6]-ans[8];
		ans[1] = cnt[o('O')]-ans[0]-ans[2]-ans[4];
		ans[3] = cnt[o('R')]-ans[4]-ans[0];

		printf("Case #%d: ", itc);
		for (int i = 0; i < 10; ++i) {
			for (int j = 0; j < ans[i]; ++j) {
				printf("%d", i);
			}
		}
		puts("");
	}
}
