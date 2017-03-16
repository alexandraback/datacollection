#include <fstream>
#include <algorithm>
using namespace std;

ifstream fin("a.in");
ofstream fout("a.out");

const int SZ = 1e6 + 6;
int dp[SZ];

inline int rev(int a) {
	int res = 0;
	while (a) res = 10 * res + a%10, a /= 10;
	return res;
}

int solve() {
	int t;
	fin >> t;
	return dp[t];
}

int main() {
	dp[0] = 0;
	dp[1] = 1;
	for (int i = 2; i < SZ; i++) dp[i] = 1 << 30;
	for (int i = 1; i < SZ - 1; i++) {
		dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		int r = rev(i);
		if (r < SZ) dp[r] = min(dp[r], dp[i] + 1);
	}

	int a;
	fin >> a;
	for (int i = 0; i < a; i++)
		fout << "Case #" << i+1 << ": " << solve() << '\n';
}
