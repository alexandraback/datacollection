#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int CCnt = 0;

	int T, A, B, K;

	cin >> T;

	while (CCnt < T) {
		cout << "Case #" << ++CCnt << ": ";
		cin >> A >> B >> K;
		long ans = 0;
		for (int i = 0; i < A; i++) {
			for (int j = 0; j < B; j++) {
				ans += ((i & j) < K);
			}
		}
		cout << ans << endl;
	}

	return 0;
}
