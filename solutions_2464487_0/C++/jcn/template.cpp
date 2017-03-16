#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>
#include<utility>
#include<iostream>
#include<sstream>

using namespace std;

const double eps = 1e-8;
const double pi = acos(-1.0);

int ntest;
long long r, t;

long long get(long long n) {
	double dummy_ans = (2.0 * r + 2 * n - 2) * n + n;
	if(dummy_ans > t + 1e15) return t + 1;
	long long ans = ((2 * r + 2 * n - 2) * n + n);
	return ans;
}

int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%lld%lld", &r, &t);
		get(2);
		long long lower = 0, upper = t;
		while(lower + 1 < upper) {
			long long mid = (lower + upper) / 2;
			if(get(mid) > t) upper = mid;
			else {
				lower = mid;
			}
		}
		printf("Case #%d: %lld\n", test, lower);
	}
	return 0;
}
