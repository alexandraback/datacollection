#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <string.h>

#include <queue>
#include <stack>
#include <set>
#include <map>
#include <assert.h>

using namespace std;

uint64_t requires(uint64_t r, uint64_t n) {
    return ((2*r+1) + (2*r+1+4*(n-1))) / 2 * n;
}

uint64_t solve(uint64_t r, uint64_t t) {
	uint64_t i = 0, j = (sqrt( ((double)r) * ((double)r) + (double)t) - (double)r) + 1;
	while( i < j - 1 ) {
		uint64_t m = (i + j) / 2;
		uint64_t req = requires(r, m);
		//printf("%llu %llu %llu %llu\n", i, j, m, req);
		if (req == t) {
			//printf("%llu %llu\n", requires(r, m), requires(r, m+1));
			return m;
		} else if (req < t) {
			if (requires(r, m+1) > t) {
				//printf("%llu %llu\n", requires(r, m), requires(r, m+1));
				return m;
			}
			i = m;
		} else {
			j= m;
		}
	}
	//printf("%llu %llu\n", requires(r, i), requires(r, i+1));
	return i;
}
int main(int argc, char* argv[]) {
	int T;
	setbuf(stdout, NULL);
	
	scanf("%d\n", &T);
	
	for(int t=0; t<T; t++) {
		uint64_t r,t1, v;
		scanf("%llu %llu", &r, &t1);
		
		v = solve(r, t1);
		assert(requires(r, v) <= t1);
		if ((requires(r, v+1) <= t1)) {
			for(;requires(r, v) <= t1; v++);
			v--;
		}
		printf("Case #%d: %llu\n", t+1, v);

	}
	//fclose(f);
	return 0;
}
