#include <iostream>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
	int t;
	cin >> t;
	string s;

	for (int i = 0; i < t; i++) {
		cin >> s;
		string ss = "";
		ss += s[0];
		for (int j = 1; j < s.size(); j++) {
			if (s[j] >= ss[0]) {
				ss = s[j]+ss;
			} else {
				ss += s[j];
			}
			//cout << ss << endl;
		}
		printf("Case #%d: ", i+1);
		cout << ss << endl;
	}
	return 0;
}