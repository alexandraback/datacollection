#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
#include <utility>

using namespace std;


unsigned long long ans(vector<pair<unsigned long long, unsigned long long> > a, vector<pair<unsigned long long, unsigned long long> > b) {
	if (a.size() == 0 || b.size() == 0) return 0;

	if (a[a.size()-1].first == b[b.size()-1].first) {
		unsigned long long type = a[a.size()-1].first;
		unsigned long long ac = a[a.size()-1].second;
		unsigned long long bc = b[b.size()-1].second;
		a.erase(a.end());
		b.erase(b.end());
		unsigned long long amount = min(ac, bc);
		if (ac > amount) a.push_back(make_pair(type, ac-amount));
		if (bc > amount) b.push_back(make_pair(type, bc-amount));
		return ans(a, b) + amount;
	}

	unsigned long long f = a[a.size()-1].first;
	unsigned long long s = a[a.size()-1].second;
	a.erase(a.end());
	unsigned long long one = ans(a, b);
	a.push_back(make_pair(f, s));
	b.erase(b.end());
	return max(one, ans(a, b));
}

int main() {
	int cases; cin >> cases;

	for (int cheese = 1; cheese <= cases; cheese++) {
		cout << "Case #" << cheese << ": ";

		int N, M; cin >> N >> M;
		vector<pair<unsigned long long, unsigned long long> > A(N, make_pair(0,0));
		vector<pair<unsigned long long, unsigned long long> > B(M, make_pair(0,0));

		for (int i = 0; i < N; i++) {
			unsigned long long c, t; cin >> c >> t;
			A[i].first = t;
			A[i].second = c;
		}

		for (int i = 0; i < M; i++) {
			unsigned long long c, t; cin >> c >> t;
			B[i].first = t;
			B[i].second = c;
		}

		cout << ans(A, B);
		
		/*
		vector< vector< int > > dp(N+1, vector<int>(M+1, 0));

		for (int i = 0; i <= N; i++) { 
			for (int j = 0; j <= M; j++) { 
				if ( i == 0 || j == 0) dp[i][j] = 0;

				else if (typeA[i-1] == typeB[j-1]) {
					dp[i][j] = dp[i-1][j-1] + min(countA[i-1], countB[j-1]);
				}

				else {
					dp[i][j] = max( dp[i-1][j],  dp[i][j-1]);
				}
			}
		}

		cout << dp[N][M];
		*/

		cout << endl;
	}
}
