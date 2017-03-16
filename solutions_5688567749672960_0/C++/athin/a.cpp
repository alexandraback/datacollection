#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

long long tes,i,t,n,x,ans;
long long mem[1000007];

long long reverse(long long x) {
	long long y = 0;
	
	while (x != 0) {
		y = 10 * y + x % 10;
		x = x / 10;
	}
	
	return y;
}

int main() {
	mem[1] = 1;
	for (i=2 ; i<=1000000 ; i++) {
		mem[i] = 1 + mem[i-1];
		if (reverse(i) < i && i % 10 != 0) mem[i] = min(mem[i],1 + mem[reverse(i)]);
	}
	
	scanf("%lld",&tes);
	for (t=1 ; t<=tes ; t++) {
		ans = 1;
		scanf("%lld",&n);
		printf("Case #%lld: %lld\n",t,mem[n]);
	}
}