#include <cstdio>
#include <cstdlib>
#include <vector>

long long int max(long long int a, long long int b) {
	return (a > b ? a : b);
}

long long int solve(long long int w, long long int c) {
	long long int ret;
	ret = 0;
	if (w == c)
		return w;
	if (c > 2*w-1) {
		return max(1+solve(w, c-w), solve(w, 2*w-1));
	}
	return w+1;
}

int main() {
	long long int i,j,k;
	long long int t,r,c,w,ret;


	scanf("%lld\n", &t);

	for (i = 1; i <= t ; i++) {
		//each case here
		ret = 0;
		scanf("%lld %lld %lld\n", &r, &c, &w);
		ret = r*solve(w,c);
		printf("Case #%lld: %lld\n", i, ret);
	}
	return 0;
}

