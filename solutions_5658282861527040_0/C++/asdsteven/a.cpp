#include <iostream>
#include <algorithm>
using namespace std;

long long solve() {
	long long A, B, K;
	cin >> A >> B >> K;
	long long ans = 0;
	for (int i = 0; i < A; ++i)
		for (int j = 0; j < B; ++j)
			if ((i & j) < K)
				ans++;
	return ans;
}

int main() {
	int T;
	cin >> T;
	for (int i = 1; i <= T; ++i)
		cout << "Case #" << i << ": " << solve() << endl;
}
