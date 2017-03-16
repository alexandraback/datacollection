#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int t, ca = 1;
	string s;
	cin >> t;
	cin.ignore(); 
	while (t--) {
		getline(cin, s);
		string result = "";
		for (int i = 0; i < s.size(); i++) {
			if (i == 0)
				result += s[i];
			else if (result[0] <= s[i])
				result = s[i] + result;
			else result += s[i];
		}
		cout << "Case #" << ca++ << ": " << result << endl;
	}
}
