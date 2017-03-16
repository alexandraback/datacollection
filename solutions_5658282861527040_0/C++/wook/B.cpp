#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)

int n;
vector<string> a;

int go(int A, int B, int K) {
	int ans = 0;
	for(int i=0; i<A; ++i) {
		for(int j=0; j<B; ++j) {
			if( (i&j) < K )
				ans ++;
		}
	}
	return ans;
}

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t) {
		int A, B, K;
		cin >> A >> B >> K;
		printf("Case #%d: %d\n", t, go(A, B, K));
	}
	return 0;
}
