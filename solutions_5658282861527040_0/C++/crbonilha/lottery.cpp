#include <stdio.h>

int main() {
	int t, a, b, k;
	
	scanf("%d", &t);
	for(int test=1; test<=t; test++) {
		scanf("%d %d %d", &a, &b, &k);
		
		int cont = 0;
		for(int i=0; i<a; i++) {
			for(int j=0; j<b; j++) if((i&j) < k) {
				cont++;
			}
		}
		
		printf("Case #%d: %d\n", test, cont);
	}
}
