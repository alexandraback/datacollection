#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <string>

using namespace std;

#define MAXN 1000
#define INF 1000000000


long long get(long long r) {
	return ((long long)(r + 1) * (r + 1) - (long long)r * r);
}
long long r;
long long t;

long long sum(long long a1, long long an, long long k) {
	long long ans = (a1 + an) / 2;
	ans *= k;
	if (ans < 0)
		return t + 1;
	return ans ;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int test;
	scanf("%d", &test);
	for (int i = 1; i <= test; i++) {
		cin >> r >> t;
//		t -= get(r);
//		r += 2;
		long long left = 1, right = 10000000000;
		while (left + 1 < right) {
			long long mid = (left + right) >> 1;
			long long p1 = r;
			long long p2 = r + (mid) * 2;
			long long cur = sum(get(p1), get(p2), mid + 1);
			if (t >= cur)
				left = mid;
			else
				right = mid;
		}
		long long p1 = r;
		long long ans = 0;
		long long p2 = r + (left) * 2;
		long long cur = sum(get(p1), get(p2), left + 1);
		if (t >= cur)
			ans = left;
		
		p1 = r;
		p2 = r + (right) * 2;
		cur = sum(get(p1), get(p2), right + 1);
		if (t >= cur)
			ans = right;
		

		printf("Case #%d: %lld\n", i, ans + 1);
	}

	return 0;
}