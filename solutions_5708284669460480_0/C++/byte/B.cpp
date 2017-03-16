#include <iostream>
#include <string>
#include <map>
using namespace std;

double dp[105][105][105];

int T, K, L, S;
string keys, target;

double absx(double a) {
	if (a < 0) {
		return -a;
	}
	return a;
}
double num(string str) {
	int n = 0;
	for (int i = 0; i < str.length(); ++i) {
		bool can = true;
		for (int j = 0; j < target.length(); ++j) {
			if (i + j >= str.length()) {
				can = false;
				break;
			}
			if (str[i +j] != target[j]) {
				can = false;
				break;
			}
		}
		if (can) {
			n++;
		}
	}
	return n;
}

double brute(map<char, double> prob, int s, double p, string str) {
	if (s == S) {
		return p * num(str);
	}

	double ans = 0;
	map<char, double>::iterator it;
	for (it = prob.begin(); it != prob.end(); it++) {
		double pr = it->second;
		ans += brute(prob, s + 1, p * pr, str + (it -> first));
	}
	return ans;
}

int overlap(string str) {
	for (int i = 1; i < str.length(); ++i) {
		bool can = true;
		for (int j = 0; i + j < str.length(); ++j) {
			if (str[i] == str[i + j]) {
				continue;
			}
			can = false;
			break;
		}
		if (can) {
			return i;
		}
	}
	return 0;
}

double solve() {
	cin >> K >> L >> S;
	cin >> keys;
	cin >> target;

	int over = overlap(target);
	
	int maxBanana = S / L;
	if (over > 0 && maxBanana > 0) {
		maxBanana = 1 + (S - L) / over;
	}

	map<char, double> prob;
	for (int i = 0; i < keys.size(); ++i) {
		prob[keys[i]] += 1;
	}
	map<char, double>::iterator it;
	for (it = prob.begin(); it != prob.end(); it++) {
		it->second = it->second / K;
	}

	for (int i = 0; i < target.size(); ++i) {
		if (prob.count(target[i]) == 0) {
			maxBanana = 0;
			break;
		}
	}

	for (int i = 0; i <= S; ++i) {
		for (int j = 0; j <= L; ++j) {
			for (int k = 0; k <= S; ++k) {
				dp[i][j][k] = 0;
			}
		}
	}
	dp[0][0][0] = 1;
	for (int i = 0; i < S; ++i) {
		for (int j = 0; j < L; ++j) {
			for (int k = 0; k <= S; ++k) {
				if (dp[i][j][k] == 0) {
					continue;
				}
				if (target[j] == target[0]) {
					dp[i + 1][0][k] += dp[i][j][k] * (1 - prob[target[j]]);
				} else {
					dp[i + 1][0][k] += dp[i][j][k] * (1 - prob[target[j]] - prob[target[0]]);
					dp[i + 1][1][k] += dp[i][j][k] * prob[target[0]];
				}

				if (j > 0 && target[j - 1] == target[0]) {
					dp[i + 1][0][k] += dp[i][j][k] * (1 - prob[target[j]]);
				}

				if (j + 1 == L) {
					if (over > 0) {
						dp[i + 1][L - over][k + 1] += dp[i][j][k] * prob[target[j]];
					} else {
						dp[i + 1][0][k + 1] += dp[i][j][k] * prob[target[j]];
					}
				} else {
					dp[i + 1][j + 1][k] += dp[i][j][k] * prob[target[j]];
				}
			}
		}
	}
	double ans = 0;
	for (int j = 0; j < L; ++j) {
		for (int k = 0; k <= S; ++k) {
			ans += k * dp[S][j][k];
		}
	}
	double res = brute(prob, 0, 1, "");
	return maxBanana - res;
}

int main() {
    
    cin >> T;
    for (int t = 1; t <= T; ++t) {
    	cerr << t << "\n";
    	cout << "Case #" << t << ": ";
    	printf("%.7f", solve());
    	cout << "\n";
    }
	return 0;
}