#include <cstdio>
#include <algorithm>
#define LL long long
#define LP 1000000000000000000LL
using namespace std;
int main(){
	int t;
	scanf("%d", &t);
	for(int test = 1; test <= t; test++){
		LL r, got;
		scanf("%lld %lld", &r, &got);
		LL left = 1;
		LL right = 1100000000LL;
		right = min(right, 3LL * LP / r);
		while(left < right){
			LL midd = (left + right + 1) / 2;
			LL now = r * midd * 2 + ((4 * midd - 2) * midd)  / 2;
			if(now > got) right = midd - 1;
			else left = midd;
		}
		printf("Case #%d: %lld\n", test, left);
	}
	return 0;
}


