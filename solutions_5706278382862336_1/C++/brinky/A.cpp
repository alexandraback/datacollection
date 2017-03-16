#include <cstdio>

using namespace std;

long long ggt(long long a, long long b){
	if(b == 0)
		return a;
	return ggt(b, a % b);
}

int main(){
	long long p, q;
	int tcs;
	scanf("%d", &tcs);
	for(int tc=1; tc<=tcs; ++tc){
		scanf("%lld/%lld", &p, &q);
		long long g = ggt(p, q);
		q /= g;
		p /= g;
		int s = 1;
		printf("Case #%d: ", tc);
		if((1l<<40) % q != 0)
			goto be;
		for(int i=0; i<40; ++i){
			s *= 2;
			if(p >= q/s){
				printf("%d\n", i+1);
				goto ende;
			}
		}
be:
		puts("impossible");
ende:
		;
	}
}
