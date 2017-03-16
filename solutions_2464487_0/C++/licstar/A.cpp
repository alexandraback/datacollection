#include <stdio.h>

int main(){
	int T;
	scanf("%d", &T);
	for(int TT=1;TT<=T;TT++){
		long long r, t;
		scanf("%lld%lld", &r, &t);
		int tr = r;
		double sum = 0;
		int ret = 0;
		for(int i = 1; ; i++){
			double tmp = (tr+1)*(tr+1) - tr*tr;
			if(tmp+sum > t){
				break;
			}
			sum += tmp;
			tr += 2;
			ret = i;
		}
		//int ret = 
		printf("Case #%d: %d\n", TT, ret);
	}
}