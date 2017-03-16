#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
char str[2011];	int chk[27],cnt[10];
int main(){
	int T;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);
	scanf("%d", &T);
	for (int i1 = 1; i1 <= T; i1++){
		scanf("%s", str);
		int len = strlen(str);
		for (int i = 0; i < len; i++){ chk[str[i] - 'A']++; }
		cnt[0] = chk['Z'-'A'];
		chk['Z' - 'A'] -= cnt[0]; chk['O' - 'A'] -= cnt[0]; 
		chk['E' - 'A'] -= cnt[0]; chk['R' - 'A'] -= cnt[0];
		cnt[6] = chk['X' - 'A'];
		chk['S' - 'A'] -= cnt[6]; chk['I' - 'A'] -= cnt[6];
		chk['X' - 'A'] -= cnt[6];
		cnt[7] = chk['S' - 'A'];
		chk['S' - 'A'] -= cnt[7]; chk['E' - 'A'] -= (2*cnt[7]); 
		chk['N' - 'A'] -= cnt[7]; chk['V' - 'A'] -= cnt[7];
		cnt[4] = chk['U' - 'A'];
		chk['F' - 'A'] -= cnt[4]; chk['O' - 'A'] -= cnt[4];
		chk['U' - 'A'] -= cnt[4]; chk['R' - 'A'] -= cnt[4];
		cnt[2] = chk['W' - 'A'];
		chk['T' - 'A'] -= cnt[2]; chk['W' - 'A'] -= cnt[2];
		chk['O' - 'A'] -= cnt[2];
		cnt[5] = chk['V' - 'A'];
		chk['F' - 'A'] -= cnt[5]; chk['I' - 'A'] -= cnt[5];
		chk['V' - 'A'] -= cnt[5]; chk['E' - 'A'] -= cnt[5];
		cnt[8] = chk['G' - 'A'];
		chk['E' - 'A'] -= cnt[8]; chk['I' - 'A'] -= cnt[8];
		chk['G' - 'A'] -= cnt[8]; chk['H' - 'A'] -= cnt[8]; chk['T' - 'A'] -= cnt[8];
		cnt[3] = chk['H' - 'A'];
		chk['T' - 'A'] -= cnt[3]; chk['H' - 'A'] -= cnt[3]; chk['R' - 'A'] -= cnt[3];
		chk['E' - 'A'] -= (2 * cnt[3]);
		cnt[1] = chk['O' - 'A'];
		chk['O' - 'A'] -= cnt[1]; chk['N' - 'A'] -= cnt[1]; chk['E' - 'A'] -= cnt[1];
		cnt[9] = chk['I' - 'A'];
		for (int i = 0; i < 26; i++) chk[i] = 0;
		printf("Case #%d: ", i1);
		for (int i = 0; i <= 9; i++){
			for (int j = 1; j <= cnt[i]; j++){
				printf("%d", i);
			}
			cnt[i] = 0;
		}
		printf("\n");
	}
	return 0;
}