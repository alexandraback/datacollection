#include <iostream>
#include <string>
using namespace std;

char m[26] = {
    'y', 'h', 'e', 's', 'o', 'c', 'v', 'x', 'd', 'u', 'i', 'g', 'l',
    'b', 'k', 'r', 'z', 't', 'n', 'w', 'j', 'p', 'f', 'm', 'a', 'q'
};

int main() {
	int n;
	cin >> n;

	string s;
	getline(cin, s);

	for (int i = 1; i <= n; ++i) {
		getline(cin, s);
		cout << "Case #" << i << ": ";
		for (size_t j = 0; j < s.size(); ++j) {
			if (s[j] >= 'a' && s[j] <= 'z') {
				cout << m[s[j] - 'a'];
			} else {
				cout << s[j];
			}
		}
		cout << endl;
	}
}
