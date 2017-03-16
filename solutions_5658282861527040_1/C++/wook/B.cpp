#include <bits/stdc++.h>

using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++ i)
#define FOR(i, b, e) for(auto i = b; i < e; ++ i)

int n = 31;
struct Solver {
	vector<int> A, B, K;
	long long dp[32][2][2][2];

	long long count(int i, int Arelaxed, int Brelaxed, int Krelaxed) {
		if(i < 0) return 1;
		int Aend = Arelaxed ? 1 : A[i];
		int Bend = Brelaxed ? 1 : B[i];
		int Kend = Krelaxed ? 1 : K[i];

		long long &ret = dp[i][Arelaxed][Brelaxed][Krelaxed];
		if(ret != -1) return ret;

		ret = 0;
		for(int a = 0; a <= Aend; ++ a) {
			for(int b = 0; b <= Bend; ++ b) {
				int k = a & b;
				if(k <= Kend) {
//					fprintf(stderr, "Trying i=%d, %d/%d/%d\n", i, a, b, k);
					ret += count(i - 1, Arelaxed || (a < Aend), Brelaxed || (b < Bend), Krelaxed || (k < Kend));
				}
			}
		}
		return ret;
	}

	Solver(int a, int b, int k) {
		A = vector<int>(n);
		B = vector<int>(n);
		K = vector<int>(n);
		REP(i, n) A[i] = !!((1u<<i) & (a - 1u));
		REP(i, n) B[i] = !!((1u<<i) & (b - 1u));
		REP(i, n) K[i] = !!((1u<<i) & (k - 1u));
//		for(int x : A) cerr << x << ","; cerr << endl;
	}

	long long ans() {
		memset(dp, -1, sizeof dp);
		return count(n - 1, 0, 0, 0);
	}
};

int main() {
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++ t) {
		int A, B, K;
		cin >> A >> B >> K;
		cout << "Case #" << t << ": " << Solver(A, B, K).ans() << endl;
	}
	return 0;
}
