#include <stdio.h>

long int alldig(int n);

int main() {
	int i, t, n;
	scanf("%d", &t);
	for(i = 1; i <= t; i++) {
		scanf("%d", &n);
		if(n == 0)
			printf("Case #%d: INSOMNIA\n", i);
		else
			printf("Case #%d: %ld\n", i, alldig(n));
	}
 	return 0;
}

long int alldig(int n) {
	int digbits = 0x3ff; //bit 1 indicates digit not yet found
	int mask;
	long int n1, n2;

	n1 = n;
	while(n1) {
		mask = ~(1 << n1 % 10);
		digbits &= mask;
		n1 /= 10;
	}
	n2 = n;
	while(digbits) { //it'll be 0 when all digits are found	
		n2 += n;
		n1 = n2;
		while(n1) {
			mask = ~(1 << n1 % 10);
			digbits &= mask;
			n1 /= 10;
		}
	}
	return n2;
}

