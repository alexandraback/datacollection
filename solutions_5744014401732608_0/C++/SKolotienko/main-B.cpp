#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <queue>
#include <assert.h>
#include <queue>

using namespace std;

void test()
{
	int B;
	long long M;
	cin >> B >> M;

	int minB = 2;
	long long pow2 = 1;
	while (pow2 < M) {
		minB = minB + 1;
		pow2 = pow2 * 2;
	}

	if (B < minB) {
		cout << "IMPOSSIBLE";
	} else {
		cout << "POSSIBLE";

		vector<vector<int>> ans(B, vector<int>(B, 0));

		//// fully connected
		//int fcB = minB - 1;
		//pow2 /= 2;
		//cout << " " << (M - pow2);

		//for (int i = B - fcB; i < B; i++) {
		for (int i = 1; i < B; i++) {
			// connect i to every j > i
			for (int j = i + 1; j < B; j++) {
				ans[i][j] = 1;
			}
		}

		// special case
		if (M == pow2) {
			ans[0][B - 1] = 1;
			M--;
		}

		// bit mask
		long long temp = 1;
		long long tempSum = 0;
		for (int i = 1; i < B - 1; i++) {
			if ((M & temp) != 0) {
				ans[0][B - i - 1] = 1;
				tempSum += temp;
			}
			temp = temp * 2;
		}
		assert(tempSum == M);

		// output
		for (int i = 0; i < B; i++) {
			cout << endl;
			for (int j = 0; j < B; j++) {
				if (i == j) assert(ans[i][j] == 0);
				cout << ans[i][j];
			}
		}

	}
}

int main()
{
	int t = 0;
	cin >> t;
	for (int i = 0; i < t; i++) {
		cout << "Case #" << i + 1 << ": ";
		test();
		cout << endl;
	}
	return 0;
}
