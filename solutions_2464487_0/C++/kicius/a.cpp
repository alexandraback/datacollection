#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


int main() {
	int T;
	scanf("%d", &T);
	for (int t=1; t<=T; t++) {
		long long int r0, f;
		scanf("%lld %lld", &r0, &f);
		
		long long int n0=0ll, n1=1000000000;
		n1=min(n1, (f/(r0))+1);
		while (n0<n1) {
			long long int s=(n1+n0)/2;
			if ((2*r0*s + 2*s*s - s) <= f ) n0=s+1;
			else n1=s;
		}
		printf("Case #%d: %lld\n", t, n1-1);
	}
	return 0;
}

