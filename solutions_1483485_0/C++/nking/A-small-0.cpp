#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include<cstring>

using namespace std;
int main() {
	char mapper[26];
	string sample[3];
	sample[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
	sample[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
	sample[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";

	string mapping[3];
	mapping[0] = "our language is impossible to understand";
	mapping[1] = "there are twenty six factorial possibilities";
	mapping[2] = "so it is okay if you want to just give up";

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < sample[i].length(); ++j) {
			if (sample[i].at(j) != ' ') {
				mapper[sample[i].at(j) - 'a'] = mapping[i].at(j);
			}
		}
	}
	mapper['y' - 'a'] = 'a';
	mapper['q' - 'a'] = 'z';
	mapper['e' - 'a'] = 'o';
	mapper['z' - 'a'] = 'q';
	int T;
	cin >> T;
	char s[110];
	char m[110];
	cin.getline(s, 105);
	for (int i = 1; i <= T; ++i) {
		cin.getline(s, 105);
		for (int j = 0; j <= strlen(s); ++j) {
			if (isalpha(s[j])) {
				m[j] = mapper[s[j] - 'a'];
			} else {
				m[j] = s[j];
			}
		}
		cout << "Case #" << i << ": " << m << endl;
	}
	return 0;
}
