#include <bits/stdc++.h>
using namespace std;

long dp[1000001];
long maxIndex = 1;

long reverse_min(long n) {
	if (n % 10 == 0) return -1;
	long orig = n;
	long ret = 0;
	while (n > 0) {
		ret *= 10;
		ret += n % 10;
		n /= 10;
	}
	maxIndex = orig + 1;
	return ret < orig ? ret : -1;
}

long update(long n) {
	if (n < maxIndex) {
		return dp[n];
	}
	for (int i = maxIndex; i <= n; i++) {
		long reversed = reverse_min(i);
		dp[i] = dp[i - 1];
		if (reversed != -1 && dp[reversed] < dp[i]) {
			dp[i] = dp[reversed];
		}
		dp[i]++;
	}
	return dp[n];
}

int main() {
	ifstream in("cculture.in");
	ofstream out("cculture.out");
	int T, N;
	in >> T;
	for (int tc = 1; tc <= T; tc++) {
		in >> N;
		out << "Case #" << tc << ": " << update(N) << endl;
	}
	return 0;
}

