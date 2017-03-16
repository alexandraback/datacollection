#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <ctime>
#include <deque>
#include <cstdlib>
#include <map>
#include <fstream>

using namespace std;

int T;
string s;
map<string, vector<string> > dict;
int fix[61][5];

int main() {
	dict.clear();
	ifstream fin("garbled_email_dictionary.txt");
	while (!fin.eof()) {
		fin >> s;
		dict[s.substr(s.length() - 1, 1)].push_back(s);
		if (s.length() >= 2) {
			dict[s.substr(s.length() - 2, 2)].push_back(s);
			dict[s.substr(s.length() - 2, 1)].push_back(s);
		}
	}
	fin.close();
	cin >> T;
	for (int caseNum = 0; caseNum < T; ++caseNum) {
		cin >> s;
		for (int i = 0; i < 5; ++i) {
			fix[0][i] = 0;
		}
		for (int i = 1; i <= s.length(); ++i) {
			for (int j = 0; j < 5; ++j) {
				fix[i][j] = 1000000;
				if (j <= 3 && (s[i - 1] == 'a' || s[i - 1] == 'i')) {
					fix[i][j] = min(fix[i][j], fix[i - 1][j + 1]);
				}
				if (j == 4) {
					fix[i][j] = min(fix[i][j], fix[i - 1][0] + 1);
				}
				if (i >= 2) {
					vector<string> td;
					if (j <= 2) {
						td = dict[s.substr(i - 2, 2)];
					} else if (j == 3) {
						td = dict[s.substr(i - 1, 1)];
					} else if (j == 4) {
						td = dict[s.substr(i - 2, 1)];
					}
					for (int k = 0; k < td.size(); ++k) {
						string word = td[k];
						if (word.length() > i) {
							continue;
						}
						int firstChange = -1;
						int lastChange = -1;
						int changeNum = 0;
						bool legal = true;
						for (int l = 0; l < word.length(); ++l) {
							if (word[l] != s[i - word.length() + l]) {
								if (firstChange == -1) {
									firstChange = l;
								}
								if (lastChange >= 0 && l - lastChange < 5) {
									legal = false;
									break;
								}
								if (word.length() - l <= 4 - j) {
									legal = false;
									break;
								}
								lastChange = l;
								++ changeNum;
							}
						}
						if (legal) {
							for (int l = 0; l < 5; ++l) {
								if (l <= firstChange || firstChange == -1) {
									fix[i][j] = min(fix[i][j], fix[i - word.length()][l] + changeNum);
								}
							}
						}
					}
				}
			}
		}
		int ans = 100000;
		for (int i = 0; i < 5; ++i) {
			if (fix[s.length()][i] < ans) {
				ans = fix[s.length()][i];
			}
		}
		cout << "Case #" << caseNum + 1 << ": " << ans << endl;
	}
	return 0;
}