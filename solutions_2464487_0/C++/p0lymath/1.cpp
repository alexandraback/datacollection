#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

long long int min(long long int a, long long int b) {
	if(a<0) return b;
	return a<b?a:b;
}

int main() {

	int i,T;
	long long int r, t, a,b,m,v;

	scanf("%d", &T);
	for(i=1;i<=T;i++) {

		scanf("%lld%lld", &r, &t);
		
		a=1;
		b=min(1+t/(2*r-3), 1+sqrt(t/2));
		m=(a+b)/2;

		while(a<b) {
			v = m*(2*r-3)+2*m*(m+1);
			if(v==t) break;
			else if(v<t) a=m+1;
			else b=m-1;
			m=(a+b)/2;
		}
		v = m*(2*r-3)+2*m*(m+1);


		while(v>t) {
			m--;
			v=m*(2*r-3)+2*m*(m+1);
		}

		while(v<t) {
			m++;
			v=m*(2*r-3)+2*m*(m+1);
			if(v>t) m--;
		}

		printf("Case #%d: %lld\n", i, m);
	}
	return 0;
}

