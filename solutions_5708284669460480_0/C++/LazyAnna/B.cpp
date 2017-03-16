#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int tests;
	int k, l, s;
	string key, word;
	int a[200];
	cin >> tests;
	for (int t = 1; t <= tests; ++t) {
		cin >> k >> l >> s; // k is len of keyboard, l is len of word
		cin >> key >> word;
		//cout << key << endl;
		//cout << word << endl;
		//cout << s << endl;
		for (int i = 0; i < 26; ++i) {
			a[i] = 0;
		}
		for (int i = 0; i < key.length(); ++i) {
			++a[key[i] - 'A'];
		}
		bool flag = false;
		for (int i = 0; i < word.length(); ++i) {
			if (a[word[i] - 'A'] == 0) {
				flag = true;
				break;
			}
		}
		if (flag) {
			cout << "Case #" << t << ": " << 0.0 << endl;
			continue;
		}
		int x = 0;
		for (int i = word.length() - 1; i >= 1; --i) {
			if ((word.substr(0, i)).compare(word.substr(word.length() - i, i)) == 0) {
				x = i;
				break;
			}
		}
		x = word.length() - x;
		int count = 1;
		int i = word.length();
		while (i + x <= s) {
			i += x;
			++count;
		}
		//cout << count << endl;
		int m = (int)(pow(k, s));
		int tot = 0;
		for (int i = 0; i < m; ++i) {
			string st = "";
			int y = i;
			for (int j = 0; j < s; ++j) {
				st = st + key[y % k];
				y = y / k;
			}
			for (int j = 0; j < st.length(); ++j) {
				if (word.compare(st.substr(j, l)) == 0) {
					++tot;
				}
			}
		}
		cout << "Case #" << t << ": " << count - (double) tot / (double) m << endl;
		// sort(a, a + d);
	}
	return 0;
}