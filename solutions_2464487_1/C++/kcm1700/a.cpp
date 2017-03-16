#include <stdio.h>
#include <math.h>

typedef unsigned long long ull;

int main()
{
	int T;
	scanf("%d",&T);
	for(int testcase = 1; testcase <= T; testcase++){
		ull r,t;
		scanf("%lld%lld",&r,&t);
		ull l = 1, h = t/(2*r+1);
		ull ans = 1;
		while(l <= h) {
			ull m = (l+h)/2;
			double est = 2.0*r*m + m + 2.0*m*(m-1);
			if (est*0.9 > t) {
				h = m-1;
				continue;
			} else {
				ull exact = 2*r*m + m + 2*m*(m-1);
				if (exact > t) {
					h = m-1;
					continue;
				} else {
					l = m+1;
					ans = m;
				}
			}
		}
		printf("Case #%d: %llu\n", testcase, ans);
	}
	return 0;
}
