#include <stdio.h>

main()
{
	int TC, TC1;
	int ans, A, B;
	int n , m, numd, inx, div, inc, p,q,inp,t;
	int mt[7];
	int pow[7] = { 10, 100, 1000, 10000, 100000, 1000000, 10000000};
	scanf("%d", &TC);

	TC1 =  TC;

	while(TC--) {
		scanf("%d",&A);
		scanf("%d",&B);
		ans = 0;
		div = 10;
		numd = 1;
		while(A/div) {
			div = div*10;
			numd++;
		}
		
		for (inc = A; inc < B; inc++) {
			n = inc;
			mt[1] = 0;
			mt[2] = 0;
			mt[0] = 0;
			mt[3] = 0;
			mt[4] = 0;
			mt[5] = 0;
			mt[6] = 0;

			for (inx = 1; inx < numd; inx++) {
				m = (pow[(numd-inx)-1]*(n%pow[inx-1])) + (n/pow[inx-1]);
				if (n < m && m <= B && (m != mt[0] && m!=mt[1] && m!=mt[2] && m!=mt[3] && m!=mt[4] && m!=mt[5])) {
					mt[inx-1] = m;
					ans++;
				}
			}
		}

		printf("Case #%d: %d\n",TC1-TC,ans);
	}
}
