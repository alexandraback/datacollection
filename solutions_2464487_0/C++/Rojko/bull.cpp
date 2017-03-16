//#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
	long long T;
	scanf("%lld", &T);
	for (long long j = 0; j<T; ++j) {
		long long r,t;
		scanf("%lld %lld", &r, &t);
		long long hm = 0, poc = 1, pc = 0;
		while(hm < t) {
			long long x;
			x = 2*r+2*poc-1;
			hm+=x;
			if (hm <= t) { poc+=2; ++pc; }
		}	
		printf("Case #%lld: %lld\n", j+1, pc);
	}
	return 0;
}
