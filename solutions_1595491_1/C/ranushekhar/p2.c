#include <stdio.h>

main()
{
	int TC, TC1;
	int N, S, p;
	int ans, curname, k;

	scanf("%d",&TC);
	TC1 = TC;

	while(TC--) {
		scanf("%d", &N);
		scanf("%d", &S);
		scanf("%d", &p);

		ans = 0;
		while(N--){
			scanf("%d", &curname);
			k = curname / 3;
			switch(curname%3) {
				case 0:
					if (k >= p){
						ans++;
					} else {
						if (k && S) {
							if(k+1 >= p) {
								ans++;
								S--;
							}
						}
					}
					break;
				case 1:
					if ((k >= p) || (k+1 >= p)){
						ans++;
					}
					break;
				case 2:
					if ((k >= p) || (k+1 >= p)) {
						ans++;
					} else {
						if (S) {
							if ((k+2 >= p)) {
								ans++;
								S--;
							}
						}
					}
					break;
			}
		}


		printf("Case #%d: %d\n", TC1-TC,ans);
	}
}
