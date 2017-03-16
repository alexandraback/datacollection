#include <stdio.h>
char buf[2000];
int main(){
	int t, p;
	scanf("%d", &t);
	for (p=1; p<=t; p++){
		int smax;
		scanf("%d", &smax);
		scanf("%s", buf);
		int curr = 0, i, ans = 0;
		for (i=0; i<=smax; i++) {
			if (curr < i) {
				ans += i-curr;
				curr = i;
			}
			curr += buf[i]-'0';
		}
		printf("Case #%d: %d\n", p, ans);
	}
}
