#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cmath>

using namespace std;

int main()
{
	int CCnt = 0;

	int T, N, ans;

	cin >> T;
	
	while (CCnt < T) {
		cout << "Case #" << ++CCnt << ": ";
		cin >> N;
		vector <char> chars;
		vector <int> charCnt;
		vector <char> chars2;
		vector <int> charCnt2;
		char line[255];
		scanf("%s", line);
		char c;
		ans = 0;
		string s1, s2;
		for (int j = 0, c = line[0]; j < 100 && c != 0; j++, c = line[j]) {
			if (chars.size() == 0) {
				chars.push_back(c);
				charCnt.push_back(1);
				s1.append(1, c);
			} else {
				if (c == chars.back()) {
					charCnt.back() += 1;
				} else {
					chars.push_back(c);
					charCnt.push_back(1);
					s1.append(1, c);
				}
			}
		}
		for (int i = 1, k = 0; i < N; i++) {
			char line[255];
			scanf("%s", line);
			char c;
			for (int j = 0, c = line[0]; j < 100 && c != 0; j++, c = line[j]) {
				if (chars2.size() == 0) {
					chars2.push_back(c);
					charCnt2.push_back(1);
					s2.append(1, c);
				} else {
					if (c == chars2.back()) {
						charCnt2.back() += 1;
					} else {
						chars2.push_back(c);
						charCnt2.push_back(1);
						s2.append(1, c);
					}
				}
			}
		}
		if (s1.compare(s2) != 0) {
			cout << "Fegla Won\n";
		} else {
			for (int i = 0; i < chars.size(); i++) {
				if (charCnt[i] > charCnt2[i]) {
					ans += charCnt[i] - charCnt2[i];
				} else {
					ans += charCnt2[i] - charCnt[i];
				}
			}
			cout << ans << endl;
		}
	}

	return 0;
}
