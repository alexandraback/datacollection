#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
	int test_case, s_max;
	string shy_str;
	cin >> test_case;
	for (int tc = 1; tc <= test_case; ++tc) {
		cin >> s_max >> shy_str;
		int ans = 0, sum = 0;	
		for (int shy = 0; shy <= s_max; ++shy) {
			ans = max(ans, shy - sum);
			sum += shy_str[shy] - '0';
		}
		cout << "Case #" << tc << ": " << ans << endl;
	}
	return 0;
}
