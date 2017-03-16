#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

ll solve(int A, int B, int K) {
	int r = 0;
	for (int a = 0; a < A; a++) {
		for (int b = 0; b < B; b++) {
			if ((a&b) < K)
				r++;
		}
	}
	return r;
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
