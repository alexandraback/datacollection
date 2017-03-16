#include <iostream>
#include <etc/cppformat/format.cc>

using namespace std;

void solve(int, int);

int main() {
	ios::ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for(int i = 1 ; i <= tc ; ++i) {
		int K, C, S;
		cin >> K >> C >> S;

		const int M = (K + C - 1) / C;

		if( M > S ) {
			// impossible
			cout << fmt::format("Case #{}: IMPOSSIBLE", i) << endl;
		} else {
			cout << fmt::format("Case #{}: ", i);
			solve(K, C);
			cout << endl;
		}
	}

	return 0;
}

void solve(int K, int C) {
	const int M = (K + C - 1) / C;

	int cnt = 0;
	for(int i = 0 ; i < M ; ++i) {
		long long ans = 0;
		for(int j = 0 ; j < C ; ++j) {
			ans *= K;
			ans += (cnt < K ? cnt : (K-1));
			++cnt;
		}
		++ans;

		cout << ans << " ";
	}
}