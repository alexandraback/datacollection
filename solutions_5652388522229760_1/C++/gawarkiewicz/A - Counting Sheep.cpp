#include <iostream>
#include <set>

using namespace std;

long long solve(int N) {
	long long cur = N;
	set<int> seen;
	for (int i = 0; i < 1000; ++i) {
		for (long long c = cur; c; c /= 10) {
			seen.insert(c % 10);
		}
		if (seen.size() == 10) {
			return cur;
		}
		cur += N;
	}
	return -1;
}

int main() {
	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int N;
		cin >> N;
		long long ret = solve(N);
		cout << "Case #" << t << ": ";
		if (ret == -1) cout << "INSOMNIA"; else cout << ret;
		cout << endl;
	}
	return 0;
}