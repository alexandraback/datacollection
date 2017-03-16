/*
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
}*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning(disable:4996)
char str1[19], str2[19],ans1[19],ans2[19];  int len;
int main(){
	int T;
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d", &T);
	for (int i1 = 1; i1 <= T; i1++){
		int flag = 0;
		scanf("%s %s", str1,str2);
		len = strlen(str1);
		for (int i = 0; i < len; i++){
			if (flag == 0){
				if (str1[i] == '?' && str2[i] == '?'){
					ans1[i] = '0'; ans2[i] = '0';
				}
				else if (str1[i] == '?'){
					ans1[i] = str2[i]; ans2[i] = str2[i];
				}
				else if (str2[i] == '?'){
					ans1[i] = str1[i]; ans2[i] = str1[i];
				}
				else{
					if (str1[i] > str2[i]) flag = 1;
					else if(str1[i] < str2[i]) flag = 2;
					else flag = 0;
					ans1[i] = str1[i];
					ans2[i] = str2[i];
				}
			}
			else{
				if (flag == 1){
					if (str1[i] == '?' && str2[i] == '?'){
						ans1[i] = '0'; ans2[i] = '9';
					}
					else if (str1[i] == '?'){
						ans1[i] = '0'; ans2[i] = str2[i];
					}
					else if (str2[i] == '?'){
						ans2[i] = '9'; ans1[i] = str1[i];
					}
					else{
						ans1[i] = str1[i]; ans2[i] = str2[i];
					}
				}
				else if (flag == 2){
					if (str1[i] == '?' && str2[i] == '?'){
						ans1[i] = '9'; ans2[i] = '0';
					}
					else if (str1[i] == '?'){
						ans1[i] = '9'; ans2[i] = str2[i];
					}
					else if (str2[i] == '?'){
						ans2[i] = '0'; ans1[i] = str1[i];
					}
					else{
						ans1[i] = str1[i]; ans2[i] = str2[i];
					}
				}
			}
		}
		__int64 aa = _atoi64(ans1);
		__int64 bb = _atoi64(ans2);
		__int64 cha = (aa - bb) < 0 ? (bb - aa) : (aa - bb);
		__int64 temp = 0,cc = 0;
		for (int i = len - 1; i >= 0; i--){
			if (ans1[i] == '0' && ans2[i] == '0' && str1[i] == '?' && str2[i] == '?'){
				if (flag == 2){
					ans1[i] = '1';
					cc = _atoi64(ans1);
					temp = (cc - bb) < 0 ? (bb - cc) : (cc - bb);
					if (temp < cha){
						cha = temp;
						aa = cc;
					}
					else ans1[i] = '0';
				}
				else{
					ans2[i] = '1';
					cc = _atoi64(ans2);
					temp = (cc - aa) < 0 ? (aa - cc) : (cc - aa);
					if (temp < cha){
						cha = temp;
						bb = cc;
					}
					else ans2[i] = '0';
				}
				break;
			}
		}
		printf("Case #%d: ", i1);
		printf("%s %s\n", ans1, ans2);
		for (int i = 0; i < len; i++){
			str1[i] = str2[i] = ans1[i] = ans2[i] = 0;
		}
	}
	return 0;

}