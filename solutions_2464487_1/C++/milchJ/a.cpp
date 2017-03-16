#include <cstdio>


int main() {

	int T;
	scanf("%d ", &T);
	
	for(int x=0; x<T; ++x) {
	
		long long t, r;
		scanf("%lld %lld ", &r, &t);
		//printf("%lld %lld\n", r, t);
		long long uB=1;
		long long lB=0;
		long long eval;
		long long evalp1;
		int ctr=0;
		//printf("lol\n");
		while((uB+1)*(2*uB + 1 + 2*r)<=t) {
			//printf("%lld\n", uB);
			uB =2*uB;
		}
//		printf("lo\n");
		
		while(true) {
			long long mid = lB+(uB-lB)/2;
			eval = (mid+1)*(2*mid + 1 + 2*r);
			evalp1 = (mid+2)*(2*(mid+1) + 1 + 2*r);
			if(uB-lB<=1 && eval<=t && evalp1>t)
				break;
	//		printf("test %lld %lld, %lld %lld %lld\n", uB, lB, mid, eval, evalp1);

			if(eval<=t)
				lB=mid;
			else
				uB=mid;
		}


		printf("Case #%d: %lld\n", x+1, uB);	
	}

	return 0;
}
