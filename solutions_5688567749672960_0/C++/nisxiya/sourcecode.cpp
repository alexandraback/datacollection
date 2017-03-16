#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>

using namespace std;


class Solution {
public:
	const static int N = 1000000+10;
	map<int, int> m;
	void solve() {
		int tcase;
		cin >> tcase;
		pre_compute();
		for (int i = 1; i <= tcase; i++) {
			int n;
			cin >> n;

			cout << "Case #" << i << ": " << f[n] << endl;
		}
	}
	int *f;
	void pre_compute() {
		f = new int[N];
		memset(f, 0, sizeof(int)* N);
		f[0] = 0;
		f[1] = 1;
		for (int i = 2; i < N; i++) {
			int i_reverse = reverse(i);
			if (i_reverse < i && i%10 != 0) f[i] = min(f[i-1], f[i_reverse]) + 1;
			else f[i] = f[i-1] + 1;
		}
//		for (int i = 1; i < 30; i++) {
//			cout << "i:" << i << " " << f[i] << endl;
//		}
	}
	int reverse(int k) {
		int ans = 0;
		while (k > 0) {
			ans *= 10;
			ans += k%10;
			k /= 10;
		}
		return ans;
	}
};

int main() {
	Solution solution;
	solution.solve();
	return 0;
}
