#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main(void) {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		int N;
		cin >> N;
		vector<string> str1, str2;
		for (int j = 0; j < N; j++) {
			string s1, s2;
			cin >> s1 >> s2;
			stringstream ss;
			ss << s1 << " " << s2;
			str1.push_back(ss.str());
		}
		sort(str1.begin(), str1.end());

		vector<string> ss1, ss2;
		for (int j = 0; j < N; j++) {
			string s1, s2;
			int k;
			for (k = 0; k < str1.at(j).length(); k++) {
				if (str1.at(j).at(k) == ' ') {
					s1 = str1.at(j).substr(0, k);
					break;
				}
			}
			s2 = str1.at(j).substr(k);
			ss1.push_back(s1);
			ss2.push_back(s2);
		}
		bool hasChecked = false;
		int count = 0;
		for (int j = 0; j < N; j++) {
			for (int k = 1; k < j; k++) {
				if (ss1.at(j) == ss1.at(k) && !hasChecked) {
					count++;
					hasChecked = true;
				}
				else
					hasChecked = false;
			}
		}
		cout << "Case #" << i + 1 << ": " << count << endl;
	}
	return 0;
}