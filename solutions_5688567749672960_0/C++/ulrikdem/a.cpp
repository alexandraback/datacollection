#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int flip(int number) {
	int result = 0;
	while(number) {
		result = result * 10 + number % 10;
		number /= 10;
	}
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	vector<int> dp(1000001);
	for(int number = 1; number <= 1000000; ++number) {
		dp[number] = dp[number - 1] + 1;
		if(number % 10 && flip(number) < number) {
			dp[number] = min(dp[number], dp[flip(number)] + 1);
		}
	}
	int tests;
	cin >> tests;
	for(int test = 1; test <= tests; ++test) {
		int target;
		cin >> target;
		cout << "Case #" << test << ": " << dp[target] << '\n';
	}
	return 0;
}
