#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <tuple>
#include <string.h>

typedef long long ll;
using namespace std;

typedef map<tuple<int, int, int, int>, ll> memo_t;
memo_t memo;

ll rec(int A, int B, int K, int b) {
	ll &r = memo[make_tuple(A, B, K, b)];
	if (r != 0)
		return r;
	//printf("%d %d %d %d\n", A, B, K, b);
	int m = (1<<b);
	int k = ((A&m)?1:0) + ((B&m)?2:0);
	if (b == 0) {
		if (K&m)
			return r = ((A&m)+1)*((B&m)+1);
		else
			return r = ((A&m)+1)+((B&m));
	}
	if (K&m) {
		if (k == 0)
			r = rec(A, B, -1, b-1);
		else if (k == 1)
			r = rec(-1, B, -1, b-1) + rec(A, B, -1, b-1);
		else if (k == 2)
			r = rec(A, -1, -1, b-1) + rec(A, B, -1, b-1);
		else
			r = rec(A, B, K, b-1) + rec(-1, B, -1, b-1) + rec(A, -1, -1, b-1) + rec(-1, -1, -1, b-1);
		return r;
	} else {
		if (k == 0)
			r = rec(A, B, K, b-1);
		else if (k == 1)
			r = rec(-1, B, K, b-1) + rec(A, B, K, b-1);
		else if (k == 2)
			r = rec(A, -1, K, b-1) + rec(A, B, K, b-1);
		else
			r = rec(-1, -1, K, b-1) + rec(-1, B, K, b-1) + rec(A, -1, K, b-1);
		return r;
	}
}

ll solve(int A, int B, int K) {
	return rec(A-1, B-1, K-1, 29);
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int A, B, K;
		cin >> A >> B >> K;
		ll ans = solve(A, B, K);
		printf("Case #%d: %lld\n", i+1, ans);
	}
}
