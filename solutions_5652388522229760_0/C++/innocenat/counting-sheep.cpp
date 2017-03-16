#include <stdio.h>

inline void tally_number(int* ar, int n) {
	while (n > 0) {
		ar[n%10]++;
		n/=10;
	}
}

inline int count_tally(int* ar) {
	int c=0;
	for (int i = 0; i < 10; i++) if (ar[i]) c++;
	return c==10;
}

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		int ar[10];
		for (int j = 0; j < 10; j++) ar[j] = 0;
		int n;
		int k = 0;
		scanf("%d",&n);
		if (n <= 0) {
			printf("Case #%d: INSOMNIA\n",i+1);
		} else {
			while (!count_tally(ar)) {
				tally_number(ar,n*(k+1));
				k++;
			}
			printf("Case #%d: %d\n",i+1,n*k);
		}
	}
	return 0;
}

