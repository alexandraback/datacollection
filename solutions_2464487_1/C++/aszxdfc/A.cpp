#include<iostream>
#include<math.h>
using namespace std;
long long r, t;
long long bs(long long left, long long right, long long target)
{
    //printf("%lld %lld %lld\n", left, right, target);
    if(left > right) return -1;
	if(left == right) {
		if(2 * r * left + left * (2 * left - 1) <= target) {
            //printf("%lld %lld\n", 2 * r * left + left * (2 * left - 1), left);
			return left;
		}
		else return -1;
	}
	long long mid = (left + right) >> 1;
	if(2 * r * mid + mid * (2 * mid - 1) <= target) {
		long long temp = bs(mid + 1, right, target);
		if(temp != -1) return temp;
		return mid;
	}
	return bs(left, mid - 1, target);
}

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("out1.txt", "w", stdout);
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; i++) {
		scanf("%lld%lld", &r, &t);
		//printf("%lf %lld\n", sqrt(t / 2 + 1), t / (2* r));
		printf("Case #%d: %lld\n", i, bs(1, min(ceil(sqrt(t / 2 + 100)), ceil((double)t / (2 * r))), t));
	}
	return 0;
}
