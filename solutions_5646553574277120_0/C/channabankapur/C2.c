#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long t, tcount = 1, i,j,k;
long C,D,V,ans,di,val; //
long den[10000];//all denominations
//int a[100*100];
//int dp[100*100][10]; //replace 10 with V=10^9

void insert(int newd) {
	i=D+ans-1;
	while((i>=0) && (den[i] > newd)) {
		den[i+1] = den[i];
		i--;
	}
	den[i+1] = newd;
}

int main()
{
    scanf("%ld", &t);
    while(t--) {
        scanf("%ld", &C);
        scanf("%ld", &D);
        scanf("%ld", &V);

		scanf("%ld", &den[0]);
		ans = 0;
		if(den[0] != 1) {
			den[1] = den[0];
			den[0] = 1;
			ans++;
		}
		for(i=1; i < D; i++) {
			scanf("%ld", &den[i+ans]);
		}

		val = C;
		di = 1;

		while(val < V) {
			if( (di >= D+ans) || (den[di] > val+1) ) {
				insert(val+1);			
				ans++;
			}
			val += den[di] * C;
			di++;
		}

        printf("Case #%ld: %ld\n", tcount++, ans);
    }
    return 0;
}

