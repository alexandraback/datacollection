#include <iostream>
#include <string>
using namespace std;

int main() {
	int t, i, s;
	long long answer, standing;
	string str;
	cin >> t;
	for (i = 1; i <= t; ++i) {
		answer = 0;
		cin >> s;
		cin >> str;
		standing = 0;
		standing = str[0] - '0';
		for (int j = 1; j < str.size(); ++j) {
			if (str[j] - '0' > 0 && standing < j) {
				answer += j - standing;
				standing += j - standing;
			}
			standing += str[j] - '0';
		}
		cout << "Case #" << i << ": " << answer << std::endl;
	}
	return 0;
}
