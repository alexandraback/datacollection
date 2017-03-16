#include<stdio.h>
#include<math.h>

int main(){
	int T, tc = 1;
	long long int t, r;
	scanf("%d", &T);
	while(T--){
		scanf("%lld %lld", &r, &t);
		long long int i = 0;
		long long int count = 0;
		while(t > 0){
			t -= (r+i+1)*(r+i+1) - (r+i)*(r+i);
			if(t >= 0) count++;
			i += 2;
		}
		printf("Case #%d: %lld\n", tc++, count);
	}
}
