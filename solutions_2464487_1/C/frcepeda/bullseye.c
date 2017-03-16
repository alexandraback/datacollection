#include <stdio.h>

int T;
unsigned long long int r, t, lo, hi, mid;

int main(void){
	int c, i;

	scanf("%d", &T);

	for (c = 1; c <= T; c++){
		scanf("%lld %lld", &r, &t);
		lo = 1, hi = 707106980;

		while (lo < hi){
			mid = lo + (hi - lo)/2;

			if ((2*r+1)*mid+2*mid*(mid-1) > t)
				hi = mid;
			else
				lo = mid + 1;
		}

		printf("Case #%d: %llu\n", c, hi - 1);
	}

	return 0;
}
