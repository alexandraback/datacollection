#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

long long r, t;

void input() {
	scanf("%lld%lld", &r, &t);
	//printf("%lld %lld\n", a, b);

	//long long x = 707106780;
	//printf("%lld\n", 2*x*x + x);
}

void solve1() {
	long long xx;
	for(long long i = 1;;i ++) {
		long long res = 2*i*i + (2*r-1)*i;
		if(res <= t) xx = i;
		else break;
	}

	printf("%lld\n", xx);
}

void solve() {
	long long high = 1;
	while(1) {
		long long tmp = 2*high;
		if(tmp*tmp > 0&&tmp*tmp <= t/2) high = tmp;
		else break;
	}

	high *= 2;
	long long low = high/2;

	while(low < high-1) {
		long long mid = (low+high)/2;
		if(mid*mid > 0&&mid*mid <= t/2) low = mid;
		else high = mid;
	}

	high = low;

	if(t/(2*r-1) < high) high = t/(2*r-1);

	++ high;

	//printf("%lld\n", high);

	low = 1;

	while(low < high-1) {
		long long mid = (low+high)/2;
		long long tmp = 2*mid*mid + (2*r-1)*mid;

		if(tmp > 0&&tmp <= t) low = mid;
		else high = mid;

		//printf("%lld %lld %lld\n", low, high, tmp);
	}

	printf("%lld\n", low);
}

int main() {
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	for(int cas = 1;cas <= t;cas ++) {
		input();
		printf("Case #%d: ", cas);
		solve();
	}
	return 0;
}