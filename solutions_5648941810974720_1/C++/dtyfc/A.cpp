#include <bits/stdc++.h>
using namespace std;
int cnt[26], ans[10];
char str[2005];
char phone[2005];
int main() {
	freopen("A-large.in", "r", stdin);
	freopen("A-large.ou", "w", stdout);

	int T, cases = 0;
	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		memset(cnt, 0, sizeof(cnt));
		for(int i = 0; str[i]; i++) cnt[str[i] - 'A']++;
		memset(ans, 0, sizeof(ans));
		ans[0] = cnt['Z' - 'A'];
		ans[2] = cnt['W' - 'A'];
		ans[4] = cnt['U' - 'A'];
		ans[6] = cnt['X' - 'A'];
		ans[8] = cnt['G' - 'A'];
		ans[3] = cnt['R' - 'A'] - ans[0] - ans[4];
		ans[1] = cnt['O' - 'A'] - ans[4] - ans[2] - ans[0];
		ans[5] = cnt['F' - 'A'] - ans[4];
		ans[7] = cnt['V' - 'A'] - ans[5];
		ans[9] = cnt['I' - 'A'] - ans[5] - ans[6] - ans[8];
		int p = 0;
		for(int i = 0; i < 10; i++) {
			for(int j = 0; j < ans[i]; j++) phone[p++] = '0' + i;
		}
		phone[p] = 0;
		printf("Case #%d: %s\n", ++cases, phone);
	}
	return 0;
}
