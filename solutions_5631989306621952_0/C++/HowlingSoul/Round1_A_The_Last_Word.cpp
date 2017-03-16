#include <stdio.h>
#include <string.h>
char s[1005], a[1005], b[1005], cc[1005];
int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A_small.out", "w", stdout);
	int t, tc;
	scanf("%d", &tc);
	for (t = 1; t <= tc; t++){
		memset(a, 0, sizeof(a));
		memset(b, 0, sizeof(b));
		int i, j, ina=0, inb=0;
		char mx = 0;
		scanf("%s", s);
		for (i = 0; i < strlen(s); i++){
			if (mx <= s[i]){
				b[inb++] = s[i];
				mx = s[i];
			}
			else a[ina++] = s[i];
		}
		printf("Case #%d: ", t);
		for (i = inb - 1; i >= 0; i--) printf("%c", b[i]);
		printf("%s\n", a);
	}
	return 0;
}