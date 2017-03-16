#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
using namespace std;

const double eps = 1e-6;

int N, X, Y;

int numTriangle(int k) {
	return (k*2+1)*(k+1);
}

double f[2000][2000];

double cmn(int N, int K) {
	if (K == 0 || K == N)
		return 1;
	if (K < 0) return 0;
	if (f[N][K] < 0)
		f[N][K] = cmn(N - 1, K - 1) + cmn(N - 1, K);
	return f[N][K];
}

double calc(int i, int j, int m) {
	if (i < 0 || j < 0 || i > m || j > m) return 0;
	if (f[i][j] < 0) {
		f[i][j] = (i == m ? 1 : 0.5) * calc(i, j - 1, m) + (j == m ? 1 : 0.5) * calc(i - 1, j, m);
	}
	return f[i][j];
}

int main() {
	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w+", stdout);
	int T;
	cin >> T;
	for (int tcase = 1; tcase <= T; ++ tcase) {
		cin >> N >> X >> Y;
		int K = 0; 
		while (numTriangle(K) <= N) ++ K;
		-- K;
		N -= numTriangle(K);
		double prob = 0;
		if (X < 0) X = -X;
		if (X + Y <= K * 2) {
			prob = 1.0;
		} else if (X + Y > K * 2 + 2) {
			prob = 0.0;
		} else {
			for (int i = 0; i <= K*2+10; ++ i)
				for (int j = 0; j <= K*2+10; ++ j)
					f[i][j] = -1;
			f[0][0] = 1;
			for (int i = Y + 1; i <= min(N, K * 2 + 2); ++ i) {
				prob += calc(i, N - i, K * 2 + 2); 
			}
		}
		cout << "Case #" << tcase << ": " << prob << endl;
	}
	return 0;
}
