#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>
#include <sstream>
using namespace std;

typedef long long ll;

int dp[1000100];
const int INF = 1e9;

int main() {
	for(int i = 0; i < 1000100; i++) {
		dp[i] = INF;
	}
	dp[1] = 1;
	for(int i = 1; i < 1000100; i++) {
		string s;
		stringstream sstr;
		sstr << i;
		sstr >> s;
		ll tmp = atol(string(s.rbegin(), s.rend()).c_str());

		if(tmp < 1000100) {
			dp[tmp] = min(dp[tmp], dp[i]+1);
		}
		dp[i+1] = min(dp[i+1], dp[i] + 1);
	}

	int T;
	cin >> T;
	for(int t = 0; t < T; t++) {
		ll N;
		cin >> N;
		cout << "Case #" << t+1 << ": " << dp[N] << endl;
	}
}
