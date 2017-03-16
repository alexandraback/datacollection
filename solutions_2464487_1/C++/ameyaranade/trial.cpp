#include<cstdio>
#include<math.h>
using namespace std;

#define LINT unsigned long long int

#define MAX 1000000000

LINT solve(LINT r, LINT t) {
	LINT fr = (2*r+1);
	if (r > MAX) {
		//better use brute.
		LINT i = 1;
		while((i*fr + 2*i*(i-1)) <= t) {
			i++;
		}
		return i-1;
	}
	// solve for max n. s.t n*fr + 2n(n-1) < t
	return (LINT) ((sqrt((long double) ((fr-2)*(fr-2) + 8*t)) + 2 - fr) / 4);
}


int main() {
	freopen("a.in", "r", stdin);
    freopen("op.out", "w", stdout);
	int T, count=1;
	LINT r,t;
	scanf("%d", &T);
	while(T--) {
		scanf("%llu %llu", &r, &t);
		printf("Case #%d: %llu\n", count++, solve(r,t));
	}
	return 0;
}