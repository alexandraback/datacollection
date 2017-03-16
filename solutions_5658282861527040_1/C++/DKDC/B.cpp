#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int CCnt = 0;

	long T, A, B, K;

	cin >> T;

	while (CCnt < T) {
		cout << "Case #" << ++CCnt << ": ";
		cin >> A >> B >> K;
		if (A > B) {
			long C = A;
			A = B;
			B = C;
		}
		long long ans;
		if (A >= K && B >= K) {
			ans = K*(A+B-K);
			for (int i = K; i < A; i++) {
				for (int j = K; j < B; j++) {
					ans += ((i & j) < K);
				}
			}
		} else if (A >= K && B < K) {
			ans = K*B + B*(A - K);
		} else if (A < K && B >= K) {
			ans = K*A + A*(B - K);
		} else {
			ans = ans = A*B;
		}
		cout << ans << endl;
	}

	return 0;
}
