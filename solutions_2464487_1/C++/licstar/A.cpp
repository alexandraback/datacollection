#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	for(int TT=1;TT<=T;TT++){
		long long r, t;
		scanf("%lld%lld", &r, &t);

		long long low = 0;
		long long high = 1807106780;
		long long ok = 0;
		while(low < high){
			long long n = (low+high)/2;

			if(2.*n*r <= t && 2*n*r + (n-1)*n*2 + n <= t){
				ok = low;
				low = n+1;
			}else{
				high = n-1;
			}
		}
		while(2*ok*r + (ok-1)*ok*2 + ok <= t){
			ok++;
		}
		
		printf("Case #%d: %lld\n", TT, ok-1);
	}
}

