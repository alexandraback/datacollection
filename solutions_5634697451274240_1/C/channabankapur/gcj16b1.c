#include <stdio.h>
#include <string.h>

long int flips(char *s, int n);

int main() {
	int i, t, n;
	char s[201];
	scanf("%d", &t);
	for(i = 1; i <= t; i++) {
		scanf("%s", s);
		n = strlen(s);
		printf("Case #%d: %ld\n", i, flips(s, n));
	}
 	return 0;
}

long int flips(char *s, int n) {
	while(n > 0 && s[n-1] == '+') 
		n--;
	if(n == 0) return 0;

	while(n > 0 && s[n-1] == '-') 
		n--;
	if(n == 0) return 1;

	return 2 + flips(s, n);
}

