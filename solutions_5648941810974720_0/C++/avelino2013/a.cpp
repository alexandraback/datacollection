#include <bits/stdc++.h>
using namespace std;

int main() {
	int t, T=1, n, cnt[33], ans[11];
	char s[2222];
	scanf("%d", &t);
	while(t--) {
		scanf("%s", s);
		n=strlen(s);
		memset(cnt, 0, sizeof(cnt));
		memset(ans, 0, sizeof(ans));
		for(int i=0; i<n; i++) cnt[s[i]-'A']++;
		//0
		while(cnt['Z'-'A']) {
			cnt['Z'-'A']--;
			cnt['E'-'A']--;
			cnt['R'-'A']--;
			cnt['O'-'A']--;
			ans[0]++;
		}
		//2
		while(cnt['W'-'A']) {
			cnt['T'-'A']--;
			cnt['W'-'A']--;
			cnt['O'-'A']--;
			ans[2]++;
		}
		//4
		while(cnt['U'-'A']) {
			cnt['F'-'A']--;
			cnt['O'-'A']--;
			cnt['U'-'A']--;
			cnt['R'-'A']--;
			ans[4]++;
		}
		//6
		while(cnt['X'-'A']) {
			cnt['S'-'A']--;
			cnt['I'-'A']--;
			cnt['X'-'A']--;
			ans[6]++;
		}
		//3
		while(cnt['R'-'A']) {
			cnt['T'-'A']--;
			cnt['H'-'A']--;
			cnt['R'-'A']--;
			cnt['E'-'A']--;
			cnt['E'-'A']--;
			ans[3]++;
		}
		//8
		while(cnt['T'-'A']) {
			cnt['E'-'A']--;
			cnt['I'-'A']--;
			cnt['G'-'A']--;
			cnt['H'-'A']--;
			cnt['T'-'A']--;
			ans[8]++;
		}
		//1
		while(cnt['O'-'A']) {
			cnt['O'-'A']--;
			cnt['N'-'A']--;
			cnt['E'-'A']--;
			ans[1]++;
		}
		//5
		while(cnt['F'-'A']) {
			cnt['F'-'A']--;
			cnt['I'-'A']--;
			cnt['V'-'A']--;
			cnt['E'-'A']--;
			ans[5]++;
		}
		//7
		while(cnt['S'-'A']) {
			cnt['S'-'A']--;
			cnt['E'-'A']--;
			cnt['V'-'A']--;
			cnt['E'-'A']--;
			cnt['N'-'A']--;
			ans[7]++;
		}
		//9
		while(cnt['N'-'A']) {
			cnt['N'-'A']--;
			cnt['I'-'A']--;
			cnt['N'-'A']--;
			cnt['E'-'A']--;
			ans[9]++;
		}

		printf("Case #%d: ", T++);
		for(int i=0; i<10; i++) while(ans[i]) {
			printf("%d", i);
			ans[i]--;
		}
		printf("\n");
	}
	return 0;
}
