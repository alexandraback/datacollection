#include <bits/stdc++.h>
using namespace std;

int cnt[26], ans[10];

int main() {
	int T;
	scanf("%d", &T);
	for (int tc = 1; tc <= T; tc++) {
		
		string S;
		cin >> S;
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < S.length(); i++) cnt[S[i] - 'A']++;
		ans[0] = cnt['Z' - 'A'];
		ans[2] = cnt['W' - 'A'];
		ans[4] = cnt['U' - 'A'];
		ans[6] = cnt['X' - 'A'];
		ans[8] = cnt['G' - 'A'];
		ans[1] = cnt['O' - 'A'] - ans[2] - ans[4] - ans[0];
		ans[3] = cnt['R' - 'A'] - ans[4] - ans[0];
		ans[5] = cnt['F' - 'A'] - ans[4];
		ans[7] = cnt['V' - 'A'] - ans[5];
		ans[9] = (cnt['N' - 'A'] - ans[1] - ans[7]) / 2;
		printf("Case #%d: ", tc);
		for (int i = 0; i <= 9; i++) for (int j = 0; j < ans[i]; j++) printf("%d", i);
		printf("\n");
	}
		
}
