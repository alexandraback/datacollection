#include <iostream>
using namespace std;

const int N = 2e3 + 10;

char s[N];

int main() {
	freopen("in4.in", "r", stdin);
	freopen("out", "w", stdout);

	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s);
		int len = strlen(s);
		int cnt[26];
		fill(cnt, cnt+26,0);
		for(int j = 0; j < len; j++) {
			cnt[s[j]-'A']++;
		}
		int freq[10];
		fill(freq, freq+10,0);
		freq[0] = cnt['Z'-'A'];
		freq[2] = cnt['W'-'A'];
		freq[4] = cnt['U'-'A'];
		freq[6] = cnt['X'-'A'];
		freq[8] = cnt['G'-'A'];
		freq[7] = cnt['S'-'A'] - freq[6];
		freq[5] = cnt['V'-'A'] - freq[7];
		freq[3] = cnt['H'-'A'] - freq[8];
		freq[1] = cnt['O'-'A'] - freq[0] - freq[2] - freq[4];
		freq[9] = (cnt['N'-'A'] - freq[1] - freq[7])/2;
		printf("Case #%d: ", i);
		for(int j = 0; j <= 9; j++) {
			for(int k = 0; k < freq[j]; k++)
				printf("%d",j);
		}
		printf("\n");
	}
}