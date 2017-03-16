#include <iostream>
#include <string>

using namespace std;
int main() {
	int t, test, i;
	string s;
	cin >> t;
	for (test=1;test<=t;test++) {
		cin >> s;
		string result = "";
		result += s[0];
		for (i=1;i<s.length();i++) {
			if (s[i] < result[0])
				result += s[i];
			else
				result = s[i] + result;
		}
		cout << "Case #" << test << ": " << result << endl;
	}
	return 0;
}