#include <iostream>
using namespace std;

int val[1000005];

int revs(long long k) {
	int rev = 0;
	while (k) {
		rev = rev * 10 + k % 10;
		k /= 10;
	}
	return rev;
}

int main() {
	int T;
	long long N;
	cin >> T;
	val[1] = 1;
	for (int i = 2; i < 1000001; ++i) {
		val[i] = i;
	}
	for (int i = 2; i <= 1000001; ++i) {
		val[i] = min(val[i], val[i - 1] + 1);
		int j = revs(i);
		//cout << i << " " << j << "\n";
		if (j > i) {
			val[j] = min(val[j], val[i] + 1);
		}
	}
	for(int t = 1; t <= T; ++t) {
		cerr << t << "\n";
		cout << "Case #" << t << ": ";
		cin >> N;
		cout << val[(int) N] << "\n";
	}
	return 0;
}