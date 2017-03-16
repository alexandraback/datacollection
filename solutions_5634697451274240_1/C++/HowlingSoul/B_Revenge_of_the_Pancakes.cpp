#include <stdio.h>
#include <string.h>
char s[105];
int main(){
	int t, tc;
	freopen("B-large.in", "r", stdin);
	freopen("B_large.out", "w", stdout);
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++){
		int ans = 0, i;
		char nw = '+';
		scanf("%s", s+1);
		for (i = strlen(s+1); i > 0; i--){
			if (nw == '+'&&s[i] == '-'){
				nw = '-';
				ans++;
			}
			else if (nw == '-'&&s[i] == '+'){
				nw = '+';
				ans++;
			}
		}
		printf("Case #%d: %d\n", t, ans);
	}
	return 0;
}