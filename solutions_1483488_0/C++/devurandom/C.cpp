#include <stdio.h>


int main() {
	int T;
	scanf("%d", &T);
	for(int nc=1; nc<=T; nc++) {
		int A, B;
		scanf("%d %d", &A, &B);
		
		int cnt = 0;
		
		int digits = 1, hpo=1;
		while(A >= 10*hpo-1) {
			hpo*= 10;
			digits++;
		}

		for(int n=A; n<=B; n++) {
			int m = n;
			do{
				//m = rotate(m);
				int ld = m%10;
				m = m/10;
				m += hpo*ld;
				if(n < m and m <= B) cnt++;
			} while(m!=n);
		}
		
		printf("Case #%d: %d\n", nc, cnt);
	}
}
